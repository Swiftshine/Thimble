#pragma once

#include <types.h>

namespace gfl {

class Timer {
public:
    // If no name is given, the default is "Timer"
    Timer(const char* pName = nullptr);
    virtual ~Timer();

    void Start();
    s64 GetDelta(s64* pFirst, s64* pSecond);
    void End();
    void Reset();
public:
    /* 0x00 */ bool m_0;
    /* 0x04 */ const char* mName;
    /* 0x08 */ s64 mStartTime;
    /* 0x10 */ s64 mEndTIme;
    /* 0x18 */ s64 mDelta;
    /* 0x20 */ bool mCounting;
};

}
