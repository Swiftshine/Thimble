#pragma once

#include <types.h>

class YsHandleObj;

struct YsHandle {
    /* 0x0 */ YsHandleObj** mObject;
    /* 0x4 */ u32 mID;
};

SIZE_ASSERT(YsHandle, 0x8);
