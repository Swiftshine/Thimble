#pragma once

#include <types.h>

#include <gfl/gflMath.hpp>

class IObjHitCB;
class MapObject;

class ObjHit {
public:
    enum class ObjHitType {
        Point       = 0,
        Sphere      = 1,
        AABB        = 2,
        Box         = 3,
        Capsule     = 4,
        Cylinder    = 5,
    };

    enum class ObjHitCategory {
        NONE                    = 0,
        DEFENSE                 = 1,
        PL_PUSH                 = 2,
        PL_DAMAGE               = 3,
        PL_RIDE                 = 4,
        PL_ATTACK               = 5,
        PL_HIP_ATTACK           = 6,
        PL_EGG                  = 7,
        PL_RELEASE              = 8,
        PL_SEARCH               = 9,
        PL_SUSPEND              = 10,
        PL_EVENT                = 11,
        PL_ITEMGET              = 12,
        PL_BUTTON_ATK           = 13,
        PL_BUTTON_DMG           = 14,
        CATEGORY_15             = 15,
        CATEGORY_16             = 16,
        PL_POW_LIFE_NEAR        = 17,
        PL_POW_SEARCH_MII       = 18,
        PL_POW_SEARCH_CLOUD     = 19,
        PL_POW_SEARCH_FRAME     = 20,
        LIFE_NEAR_CHECK         = 21,
        SEARCH_MII_CHECK        = 22,
        SEARCH_CLOUD_CHECK      = 23,
        SEARCH_FRAME_CHECK      = 24,
        EN_PUSH                 = 25,
        EN_DAMAGE               = 26,
        EN_ATTACK               = 27,
        EN_RELEASE              = 28,
        EN_CHECK_PUSH_PL        = 29,
        EN_ITEMGET              = 30,
        EN_ATTACK_EN            = 31,
        PL_FIRE_ATK             = 32,
        EN_FIRE_ATK             = 33,
        FIRE_DMG                = 34,
        PL_ICE_ATK              = 35,
        EN_ICE_ATK              = 36,
        ICE_DMG                 = 37,
        EGG_BASE                = 38,
        EGG_BASE_CHECK          = 39,
        ITEM_CHECK_PUSH         = 40,
        ITEM_CHECK_PUSH_ITEM    = 41,
        ITEM_PUSH               = 42,
        ITEM_PUSH_ITEM          = 43,
        ITEM_GET                = 44,
        ITEM_DAMAGE             = 45,
        GIMMICK_OLD             = 46,
        GIMMICK_CHECK_PUSH      = 47,
        GIMMICK_PUSH            = 48,
        GIMMICK_RIDE            = 49,
        GIMMICK_TRIGGER         = 50,
        GIMMICK_RELEASE         = 51,
        GIMMICK_ATTACK          = 52,
        GIMMICK_FIRE            = 53,
        GIMMICK_FIRE_STRONG     = 54,
        GIMMICK_DAMAGE          = 55,
        SUSPEND                 = 56,
        TERRAIN_EVENT           = 57,
        MAP_EVENT               = 58,
        ENV_MODEL_OBJ           = 59,
        WORLDMAP_CHECK          = 60,
        WORLDMAP_SEARCH         = 61,
        WORLDMAP_OBJECT         = 62,
        WORLDMAP_CAMERA_CHANGE  = 63,
        DEBUG_MAP_OBJECT        = 64,
        DEBUG_SELECTOR          = 65,
    };

    struct ObjHitInfo {
        /* 0x00 */ ObjHitType mObjHitType;
        /* 0x04 */ ObjHitCategory mObjHitCategory;
        /* 0x08 */ u32 m_8;
        /* 0x0C */ u32 m_C;
        /* 0x10 */ u32 m_10;
        /* 0x14 */ u32 m_14;
        /* 0x18 */ float mBoundingSphereRadius;
        /* 0x1C */ gfl::Vec3 mBoundingSize;
        /* 0x28 */ u32 m_28;
        /* 0x2C */ u32 m_2C;
        /* 0x30 */ u32 m_30;
        /* 0x34 */ u32 m_34;
        /* 0x38 */ float m_38;
    };

    /* 0x0C */ virtual void Init(void* pArg1, IObjHitCB* pCallback, const gfl::Matrix34& rMatrix);
    /* 0x14 */ virtual void vf14();
    /* 0x1C */ virtual void vf1C();
    /* 0x24 */ virtual void vf24();
    /* 0x2C */ virtual ~ObjHit();

public:
    /* 0x00 */ IObjHitCB* mCallback;
    /* 0x04 */ MapObject* mOwner;
    /* 0x08 */ gfl::Matrix34 m_8;
    /* 0x38 */ gfl::Matrix34 m_38;
    /* 0x68 */ ObjHitInfo mInfo;
    /* 0xA4 */ u32 m_A4;
    /* 0xA8 */ u32 m_A8;
    /* 0xAC */ u32 m_AC;
    /* 0xB0 */ u32 m_B0;
    /* 0xB4 */ u32 m_B4;
    /* 0xB8 */ u32 mFlags;
    /* 0xBC */ u32 m_BC;
};

SIZE_ASSERT(ObjHit, 0xC4);
