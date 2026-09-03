#pragma once

#include <game/object/GimmickObject.hpp>
#include <game/object/ObjectIDs.hpp>
#include <ghs_stl/list.hpp>
#include <ghs_stl/string.hpp>
#include <types.h>

typedef void (*ResourceListInitFunction)(ghs::std::list<ghs::std::string>* pList);
typedef void (*ParameterSetupFunction)();
typedef void (*ManagerInitFunction)();
typedef void (*ManagerDestroyFunction)();

enum class ObjectID : u32;
enum class EnemyID : u32;
enum class GimmickID : u32;

struct ObjectInitInfo {
    /* 0x00 */ const char* mName;
    /* 0x04 */ ObjectID mObjectID;
    /* 0x08 */ ManagerInitFunction mManagerInitFunction;
    /* 0x0C */ ManagerDestroyFunction mManagerDestroyFunction;
    /* 0x10 */ ResourceListInitFunction mResourceListInitFunction;
    /* 0x14 */ ParameterSetupFunction mParameterSetupFunction;
    /* 0x18 */ bool mSpawnOnce; // once spawned, is never respawned
    /* 0x19 */ bool m_19;
    /* 0x1A */ bool m_1A;
    /* 0x1B */ bool m_1B;
};

SIZE_ASSERT(ObjectInitInfo, 0x1C);

typedef void (*EnemyBuildFunction)(void* pBuildInfo);

struct MapEnemy : ObjectInitInfo {
    /* 0x1C */ EnemyID mEnemyID;
    /* 0x20 */ EnemyBuildFunction mBuildFunction;
    /* 0x24 */ STRUCT_FILL(0x30);
};

SIZE_ASSERT(MapEnemy, 0x54);

typedef GimmickObject* (*GimmickBuildFunction)(u32 gimmickID, GimmickBuildInfo* pBuildInfo);

struct MapGimmick : ObjectInitInfo {
    /* 0x1C */ GimmickID mGimmickID;
    /* 0x20 */ GimmickBuildFunction mBuildFunction;
};

SIZE_ASSERT(MapGimmick, 0x24);
