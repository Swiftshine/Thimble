#pragma once
#include <types.h>

namespace gfl {

class Task;

struct TaskInfo {
    /* 0x00 */ char mName[23];
    /* 0x17 */ u8 mFlags;
    /* 0x18 */ TaskInfo* mParent;
    /* 0x1C */ TaskInfo* mSibling;
    /* 0x20 */ TaskInfo* mChild;
    /* 0x24 */ Task* mOwner;
};

SIZE_ASSERT(TaskInfo, 0x28);

class Task {
public:
    virtual ~Task();
    virtual int PollTask();
private:
    /* 0x00 */ TaskInfo* mTaskInfo;
    /* 0x04 */ void* mFunctor;
    /* 0x08 */ void* mFunctorFunc;
    /* 0x0C */ u32 mFlags;
    /* 0x10 */ u32 mSuspendFlags;
    /* 0x14 */ u32 mTaskRuns;
};

SIZE_ASSERT(Task, 0x1C);

} // gfl
