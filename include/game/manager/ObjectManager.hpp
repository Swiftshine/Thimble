#pragma once

#include <gfl/gflSingleton.hpp>
#include <ghs_stl/list.hpp>
#include <object/PlEgg.hpp>
#include <object/Player.hpp>
#include <object/control/OtherEggCtrl.hpp>

class ObjectManager {
public:
    static gfl::Singleton<ObjectManager> sInstance;

    static PlEgg* SpawnPlEgg(u32 yarnBallColor, const gfl::Vec3& rPosition, const gfl::Vec3& rScale,
                             const PlEgg::BuildInfo* pBuildInfo, OtherEggCtrl* pEggCtrl);
    static PlEgg* CreatePlEgg(Player* pPlayer, u32 eggType, const gfl::Vec3& rPosition);

    Player* GetPlayer(u32 playerID);
    Player* FindNearestPlayer(const gfl::Vec3& rPosition);
};
