#pragma once

#include <object/MapObject.hpp>

class Player : public MapObject {
public:
    // blah blah blah
    STRUCT_FILL(0x9B0 - sizeof(MapObject));
};

SIZE_ASSERT(Player, 0x9B0);
