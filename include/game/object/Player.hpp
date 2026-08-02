#pragma once

#include <object/MapObject.hpp>
#include <object/control/PlEggCtrl.hpp>

class Player : public MapObject {
public:
    PlEggCtrl* GetPlEggCtrl() const;

    // blah blah blah
    STRUCT_FILL(0x9B0 - sizeof(MapObject));
};

SIZE_ASSERT(Player, 0x9B0);
