#include "config.hpp"
#include "logging.hpp"

static modloader::ModInfo modInfo = {MOD_ID, VERSION, 0};
config_t config;

Configuration& getConfig()
{
    static Configuration config(modInfo);
    config.Load();
    return config;
}

void SaveConfig()
{
    INFO("Saving Configuration...");
    getConfig().config.RemoveAllMembers();
    getConfig().config.SetObject();
    rapidjson::Document::AllocatorType& allocator = getConfig().config.GetAllocator();
    getConfig().config.AddMember("enabled", config.enabled, allocator);
    getConfig().config.AddMember("xmin", config.xmin, allocator);
    getConfig().config.AddMember("xmax", config.xmax, allocator);
    getConfig().config.AddMember("zmin", config.zmin, allocator);
    getConfig().config.AddMember("zmax", config.zmax, allocator);
    getConfig().config.AddMember("shape", config.shape, allocator);
    getConfig().Write();
    INFO("Saved Configuration!");
}

bool LoadConfig()
{
    INFO("Loading Configuration...");
    getConfig().Load();
    bool foundEverything = true;
    if (getConfig().config.HasMember("enabled") && getConfig().config["enabled"].IsBool())
    {
        config.enabled = getConfig().config["enabled"].GetBool();
    }
    else
    {
        foundEverything = false;
    }
    if (getConfig().config.HasMember("xmin") && getConfig().config["xmin"].IsDouble())
    {
        config.xmin = getConfig().config["xmin"].GetDouble();
    }
    else
    {
        foundEverything = false;
    }
    if (getConfig().config.HasMember("xmax") && getConfig().config["xmax"].IsDouble())
    {
        config.xmax = getConfig().config["xmax"].GetDouble();
    }
    else
    {
        foundEverything = false;
    }
    if (getConfig().config.HasMember("zmin") && getConfig().config["zmin"].IsDouble())
    {
        config.zmin = getConfig().config["zmin"].GetDouble();
    }
    else
    {
        foundEverything = false;
    }
    if (getConfig().config.HasMember("zmax") && getConfig().config["zmax"].IsDouble())
    {
        config.zmax = getConfig().config["zmax"].GetDouble();
    }
    else
    {
        foundEverything = false;
    }
    if (getConfig().config.HasMember("shape") && getConfig().config["shape"].IsInt())
    {
        config.shape = getConfig().config["shape"].GetInt();
    }
    else
    {
        foundEverything = false;
    }
    if (foundEverything)
    {
        INFO("Loaded Configuration!");
        return true;
    }
    return false;
}