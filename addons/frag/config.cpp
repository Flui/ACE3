#include "script_component.hpp"
class CfgPatches {
    class ADDON {
        units[] = {};
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_common"};
        author[] = {"Nou"};
        VERSION_CONFIG;
    };
};

//PRELOAD_ADDONS;

#include "CfgEventhandlers.hpp"
#include "CfgAmmo.hpp"
