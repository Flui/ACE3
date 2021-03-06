class CfgVehicles {
    class Module_F;
    class ACE_ModuleRespawn: Module_F {
        author = "$STR_ACE_Common_ACETeam";
        category = "ACE";
        displayName = "Respawn System";
        function = QFUNC(module);
        scope = 2;
        isGlobal = 1;
        icon = QUOTE(PATHTOF(UI\Icon_Module_Respawn_ca.paa));

        class Arguments {
            class SavePreDeathGear {
                displayName = "Save Gear?";
                description = "Respawn with the gear a soldier had just before his death?";
                typeName = "BOOL";

                class values {
                    class Yes { name = "Yes"; value = 1; };
                    class No { default = 1; name = "No"; value = 0; };
                };
            };

            class RemoveDeadBodiesDisconnected {
                displayName = "Remove bodies?";
                description = "Remove player bodies after disconnect?";
                typeName = "BOOL";

                class values {
                    class Yes { default = 1; name = "Yes"; value = 1; };
                    class No { name = "No"; value = 0; };
                };
            };
        };
    };

    class ACE_ModuleFriendlyFire: Module_F {
        author = "$STR_ACE_Common_ACETeam";
        category = "ACE";
        displayName = "Friendly Fire Messages";
        function = QFUNC(moduleFriendlyFire);
        scope = 2;
        isGlobal = 1;
        icon = QUOTE(PATHTOF(UI\Icon_Module_FriendlyFire_ca.paa));

        class Arguments {};
    };

    class ACE_ModuleRallypoint: Module_F {
        author = "$STR_ACE_Common_ACETeam";
        category = "ACE";
        displayName = "Rallypoint System";
        function = QFUNC(moduleRallypoint);
        scope = 2;
        isGlobal = 1;
        icon = QUOTE(PATHTOF(UI\Icon_Module_Rallypoint_ca.paa));

        class Arguments {};
    };

    // team leader
    class Man;
    class CAManBase : Man {
        class ACE_SelfActions {
            class ACE_MoveRallypoint {
                displayName = "Move Rallypoint";
                condition = QUOTE([ARR_2(_player, side group _player)] call FUNC(canMoveRallypoint));
                statement = QUOTE([ARR_2(_player, side group _player)] call FUNC(moveRallypoint));
                showDisabled = 0;
                priority = -0.5;
            };
        };
    };

    // rallypoints
    class FlagCarrier;
    class Flag_NATO_F: FlagCarrier {
        class ACE_Actions;
    };

    class Flag_CSAT_F: FlagCarrier {
        class ACE_Actions;
    };

    class Flag_AAF_F: FlagCarrier {
        class ACE_Actions;
    };

    // static
    class ACE_Rallypoint_West_Base: Flag_NATO_F {
        XEH_ENABLED;

        author = "$STR_ACE_Common_ACETeam";
        displayName = "$STR_ACE_Respawn_RallypointWestBase";
        vehicleClass = QGVAR(Rallypoints);

        class ACE_Actions: ACE_Actions {
            class ACE_Teleport {
                displayName = "$STR_ACE_Respawn_TeleportedToRallypoint";
                distance = 4;
                condition = QUOTE(side group _player == west);
                statement = QUOTE([ARR_3(_player,side group _player,'ACE_Rallypoint_West')] call FUNC(teleportToRallypoint));
                position = "[0,0,-1]";
                showDisabled = 1;
                priority = 1;
            };
        };
    };

    class ACE_Rallypoint_East_Base: Flag_CSAT_F {
        XEH_ENABLED;

        author = "$STR_ACE_Common_ACETeam";
        displayName = "$STR_ACE_Respawn_RallypointEastBase";
        vehicleClass = QGVAR(Rallypoints);

        class ACE_Actions: ACE_Actions {
            class ACE_Teleport {
                displayName = "$STR_ACE_Respawn_TeleportedToRallypoint";
                distance = 4;
                condition = QUOTE(side group _player == east);
                statement = QUOTE([ARR_3(_player,side group _player,'ACE_Rallypoint_East')] call FUNC(teleportToRallypoint));
                position = "[0,0,-1]";
                showDisabled = 1;
                priority = 1;
            };
        };
    };

    class ACE_Rallypoint_Independent_Base: Flag_AAF_F {
        XEH_ENABLED;

        author = "$STR_ACE_Common_ACETeam";
        displayName = "$STR_ACE_Respawn_RallypointIndependentBase";
        vehicleClass = QGVAR(Rallypoints);

        class ACE_Actions: ACE_Actions {
            class ACE_Teleport {
                displayName = "$STR_ACE_Respawn_TeleportedToRallypoint";
                distance = 4;
                condition = QUOTE(side group _player == independent);
                statement = QUOTE([ARR_3(_player,side group _player,'ACE_Rallypoint_Independent')] call FUNC(teleportToRallypoint));
                position = "[0,0,-1]";
                showDisabled = 1;
                priority = 1;
            };
        };
    };

    // moveable
    class ACE_Rallypoint_West: Flag_NATO_F {
        XEH_ENABLED;

        author = "$STR_ACE_Common_ACETeam";
        displayName = "$STR_ACE_Respawn_RallypointWest";
        vehicleClass = QGVAR(Rallypoints);

        class ACE_Actions: ACE_Actions {
            class ACE_Teleport {
                displayName = "$STR_ACE_Respawn_TeleportedToBase";
                distance = 4;
                condition = QUOTE(side group _player == west);
                statement = QUOTE([ARR_3(_player,side group _player,'ACE_Rallypoint_West_Base')] call FUNC(teleportToRallypoint));
                position = "[0,0,-1]";
                showDisabled = 1;
                priority = 1;
            };
        };
    };

    class ACE_Rallypoint_East: Flag_CSAT_F {
        XEH_ENABLED;

        author = "$STR_ACE_Common_ACETeam";
        displayName = "$STR_ACE_Respawn_RallypointEast";
        vehicleClass = QGVAR(Rallypoints);

        class ACE_Actions: ACE_Actions {
            class ACE_Teleport {
                displayName = "$STR_ACE_Respawn_TeleportedToBase";
                distance = 4;
                condition = QUOTE(side group _player == east);
                statement = QUOTE([ARR_3(_player,side group _player,'ACE_Rallypoint_East_Base')] call FUNC(teleportToRallypoint));
                position = "[0,0,-1]";
                showDisabled = 1;
                priority = 1;
            };
        };
    };

    class ACE_Rallypoint_Independent: Flag_AAF_F {
        XEH_ENABLED;

        author = "$STR_ACE_Common_ACETeam";
        displayName = "$STR_ACE_Respawn_RallypointIndependent";
        vehicleClass = QGVAR(Rallypoints);

        class ACE_Actions: ACE_Actions {
            class ACE_Teleport {
                displayName = "$STR_ACE_Respawn_TeleportedToBase";
                distance = 4;
                condition = QUOTE(side group _player == independent);
                statement = QUOTE([ARR_3(_player,side group _player,'ACE_Rallypoint_Independent_Base')] call FUNC(teleportToRallypoint));
                position = "[0,0,-1]";
                showDisabled = 1;
                priority = 1;
            };
        };
    };
};
