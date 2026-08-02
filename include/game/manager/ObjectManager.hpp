#pragma once

#include <ghs_stl/list.h>
#include <object/PlEgg.hpp>
#include <object/Player.hpp>
#include <gfl/gflSingleton.hpp>

class ObjectManager {
public:
    static gfl::Singleton<ObjectManager> sInstance;

    static PlEgg* SpawnPlEgg(u32 yarnBallColor, const gfl::Vec3& rPosition, const gfl::Vec3& rScale, const PlEgg::BuildInfo* pBuildInfo, ghs::std::list<PlEgg*>* pEggList);
    static PlEgg* CreatePlEgg(Player* pPlayer, u32 eggType, const gfl::Vec3& rPosition);

    Player* GetPlayer(u32 playerID);
    Player* FindNearestPlayer(const gfl::Vec3& rPosition);
};
