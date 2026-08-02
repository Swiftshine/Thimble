#pragma once

#include <ghs_stl/list.h>
#include <object/YsHandle.hpp>

class OtherEggCtrl {
public:
    OtherEggCtrl();
    virtual ~OtherEggCtrl();


    /* 0x0 */ ghs::std::list<YsHandle> mList;
};
