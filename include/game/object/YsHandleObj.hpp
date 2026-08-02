#pragma once

#include <object/YsHandle.hpp>

class YsHandleObj {
public:
    YsHandleObj();
    virtual ~YsHandleObj();
public:
    /* 0x0 */ YsHandle mHandle;
};

SIZE_ASSERT(YsHandleObj, 0xC);
