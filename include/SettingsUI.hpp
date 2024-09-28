#pragma once

#include "VertigoPlatform.hpp"

#include "custom-types/shared/macros.hpp"
#include "lapiz/shared/macros.hpp"
#include "bsml/shared/macros.hpp"

#include "UnityEngine/Transform.hpp"
#include "Zenject/IInitializable.hpp"
#include "System/IDisposable.hpp"

#define SETTINGSUI_INTERFACES { classof(::System::IDisposable*), classof(::Zenject::IInitializable*) }

___DECLARE_TYPE_WRAPPER_INHERITANCE(AntiVertigo, SettingsUI, Il2CppTypeEnum::IL2CPP_TYPE_CLASS, System::Object, "AntiVertigo", SETTINGSUI_INTERFACES, 0, nullptr,
    DECLARE_INSTANCE_FIELD_PRIVATE(UnityEngine::Transform*, root);
    DECLARE_INSTANCE_FIELD_PRIVATE(VertigoPlatform*, _platform);
    DECLARE_INSTANCE_FIELD_PRIVATE(ListW<System::Object*>, _shape_options);

    DECLARE_INSTANCE_METHOD(void, PostParse);
    DECLARE_INSTANCE_METHOD(ListW<System::Object*>, get_shape_options);
    DECLARE_OVERRIDE_METHOD_MATCH(void, Initialize, &Zenject::IInitializable::Initialize);
    DECLARE_OVERRIDE_METHOD_MATCH(void, Dispose, &System::IDisposable::Dispose);

    DECLARE_CTOR(ctor, VertigoPlatform* platform);

    DECLARE_BSML_PROPERTY(bool, enabled);
    DECLARE_BSML_PROPERTY(float, xmin);
    DECLARE_BSML_PROPERTY(float, xmax);
    DECLARE_BSML_PROPERTY(float, zmin);
    DECLARE_BSML_PROPERTY(float, zmax);
    DECLARE_BSML_PROPERTY(StringW, shape);
)