#pragma once

#include <types.h>

struct ModelResourceTable {
    /* 0x00 */ u32 mFlags;
    /* 0x04 */ const char* mResourceName;
    /* 0x08 */ u32 mNumSkeletalAnimationIDs;
    /* 0x0C */ u32* mSkeletalAnimationIDs;
    /* 0x10 */ u32 mNumSkeletalAnimationNames;
    /* 0x14 */ const char** mSkeletalAnimationNames;
};
