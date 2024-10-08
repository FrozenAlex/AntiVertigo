#pragma once

#include <vector>
#include "beatsaber-hook/shared/utils/logging.hpp"
#include "beatsaber-hook/shared/utils/hooking.hpp"
#include "logging.hpp"

class Hooks {
    private:
        static inline std::vector<void (*)()> installFuncs;
    public:
        static inline void AddInstallFunc(void (*installFunc)())
        {
            installFuncs.push_back(installFunc);
        }

        static inline void InstallHooks()
        {
            for (auto& func : installFuncs) func();
        }
};

#define AUTO_INSTALL(name_) \
struct Auto_Hook_##name_ { \
    Auto_Hook_##name_() { \
        Hooks::AddInstallFunc(::Hooking::InstallHook<Hook_##name_>);\
    } \
}; \
static Auto_Hook_##name_ Auto_Hook_Instance_##name_;

#define MAKE_AUTO_HOOK_MATCH(name_, mPtr, retval, ...) \
struct Hook_##name_ { \
    using funcType = retval (*)(__VA_ARGS__); \
    static_assert(std::is_same_v<funcType, ::Hooking::InternalMethodCheck<decltype(mPtr)>::funcType>, "Hook method signature does not match!"); \
    constexpr static const char* name() { return #name_; } \
    static const MethodInfo* getInfo() { return ::il2cpp_utils::il2cpp_type_check::MetadataGetter<mPtr>::get(); } \
    static funcType* trampoline() { return &name_; } \
    static inline retval (*name_)(__VA_ARGS__) = nullptr; \
    static funcType hook() { return hook_##name_; } \
    static retval hook_##name_(__VA_ARGS__); \
}; \
AUTO_INSTALL(name_) \
retval Hook_##name_::hook_##name_(__VA_ARGS__)