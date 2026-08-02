#pragma once

#include <object/MapObject.hpp>

class PlEgg : public MapObject {
public:
    enum class Type : u32 {
        WoolBall            = 0,
        TestEgg             = 1, // crashes due to lack of resource
        Key                 = 2,
        FluffinPuffinChick  = 4,
    };

    enum class Behavior : u32 {
        Owned = 0,
        Unowned = 1,
    };

    enum class Size : u32 {
        Small = 0,
        Medium = 1,
        Large = 2,
    };

    struct BuildInfo {
        Behavior mBehavior;
        u32 m_4;
        Type mEggType;
        Size mSize;
        u32 mFlags;
        u32 m_14;
    };

    SIZE_ASSERT(BuildInfo, 0x18);
private:
    // blah blah blah
    STRUCT_FILL(0x1FC - sizeof(MapObject));
};

SIZE_ASSERT(PlEgg, 0x1FC);
