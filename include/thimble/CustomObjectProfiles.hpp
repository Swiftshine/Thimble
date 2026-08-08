#pragma once

#include <game/object/ObjectProfile.hpp>

typedef void (*GimmickProfileInitFunction)(GimmickProfile* pProfile, const char* pName, u32 objectID, u32 gimmickID);

struct GimmickRegistrant {
    char mInLevelName[0x20];
    GimmickProfileInitFunction mInitFunction;
};

// clang-format off

// this is okay because InitProfile is static and would mangle the same way it would as if it were part of a namespace
#define DECL_GIMMICK_PROFILE_INIT(C) \
    namespace C { \
        extern void InitProfile(GimmickProfile*, const char*, u32, u32); \
    }

#define DECL_GIMMICK_REGISTRANT(C, N) \
    { \
        .mInLevelName = N, \
        .mInitFunction = C::InitProfile \
    }

DECL_GIMMICK_PROFILE_INIT(EggSpawner);

const GimmickRegistrant AdditionalGimmickRegistrants[] = {
    DECL_GIMMICK_REGISTRANT(EggSpawner, "th_egg_spawn"),
};

// clang-format on
