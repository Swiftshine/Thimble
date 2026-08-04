#pragma once

#include <game/object/ObjectProfile.hpp>
#include <thimble/CustomObjectProfileHeaders.hpp>

typedef void (* GimmickProfileInitFunction)(GimmickProfile* pProfile, const char* pName, u32 objectID, u32 gimmickID);

struct GimmickRegistrant {
    char mInLevelName[0x20];
    GimmickProfileInitFunction mInitFunction;
};

const GimmickRegistrant AdditionalGimmickRegistrants[] = {
    {
        "TEST -- REMOVE THIS ENTRY LATER",
        // an existing function address that's valid and won't crash the game
        // (you wouldn't actually put raw addresses like this,
        // you'd just pass in the Init function as a pointer)
        #if defined(__CONSOLE__)
            (GimmickProfileInitFunction)(0x024B0398 + 0x0C700000)
        #else
            (GimmickProfileInitFunction)(0x024B0398)
        #endif
    }
};
