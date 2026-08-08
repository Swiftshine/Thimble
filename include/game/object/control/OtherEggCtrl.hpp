#pragma once

#include <ghs_stl/list.hpp>
#include <object/YsHandle.hpp>

class OtherEggCtrl {
public:
    inline OtherEggCtrl() {}
    virtual ~OtherEggCtrl();

    /* 0x0 */ ghs::std::list<YsHandle> mList;
};
