#pragma once

#include <types.h>
#include <ghs_stl/vector.h>

#include <object/collision/IObjHitCB.hpp>

class MapObject;
class MapObjHit {
public:
    struct Collision {
        /* 0x0 */ ObjHit* mObjHit;
        /* 0x4 */ u32 m_4;
        /* 0x8 */ u32 m_8;
        /* 0xC */ u32 mCollisionFlags;
    };

    struct CollisionDefinition {
        /* 0x00 */ u32 mObjHitType;
        /* 0x04 */ u32 mObjHitCategory;
        /* 0x08 */ u32 m_8;
        /* 0x0C */ gfl::Vec3 mOffset;
        /* 0x18 */ gfl::Vec2 mDimensions;
        /* 0x20 */ u32 m_20;
        /* 0x24 */ u32 m_24;
        /* 0x28 */ u32 m_28;
        /* 0x2C */ u32 m_2C;
        /* 0x30 */ u32 m_30;
        /* 0x34 */ u32 m_34;
    };

    SIZE_ASSERT(CollisionDefinition, 0x38);

    MapObjHit(MapObject* pOwner, IObjHitCB* pCallback);
    /* 0x0C */ virtual ~MapObjHit();
    /* 0x14 */ virtual void SetMatrix(const gfl::Matrix34& rMtx);
    /* 0x1C */ virtual void vf1C();

    void SetCollisionFlag(u32 toggle, u32 flag);
    void SetAllCollisionFlag(u32 toggle);
    void DefineCollision(const CollisionDefinition& rColDef, u32 arg2);
    void DefineCollisions(const CollisionDefinition pColDef[], u32 count, u32 arg3);
private:
    /* 0x00 */ MapObject* mOwner;
    /* 0x04 */ IObjHitCB* mCallback;
    /* 0x08 */ u32 mCollisionFlags;
    /* 0x0C */ ghs::std::vector<Collision> mCollisions;
};

SIZE_ASSERT(MapObjHit, 0x20);
