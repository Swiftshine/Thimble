#pragma once

#include <ghs_stl/list.h>

#include <gfl/gflScene.hpp>

#include <object/YsHandle.hpp>
#include <object/PlEgg.hpp>

class PlEggCtrl {
public:

    size_t GetNumAttachedYarnBalls() const;

    /* 0x00 */ YsHandle mHandle;
    /* 0x08 */ gfl::Scene* mScene;
    /* 0x0C */ PlEgg* mEggInHand;
    /* 0x10 */ PlEgg* mEggInMouth;
    /* 0x14 */ ghs::std::list<PlEgg*> mFollowingYarnBalls;
    /* 0x20 */ ghs::std::list<PlEgg*> m_20;
    /* 0x2C */ ghs::std::list<PlEgg*> mReservedYarnBalls;
    /* 0x38 */ ghs::std::list<PlEgg*> m_38;
    /* 0x44 */ STRUCT_FILL(0xFC - 0x44);
};

SIZE_ASSERT(PlEggCtrl, 0xFC);
