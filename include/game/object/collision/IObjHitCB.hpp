#pragma once

#include <types.h>
#include <gfl/gflMath.hpp>
#include <object/YsHandle.hpp>
#include <object/collision/ObjHit.hpp>

struct CollisionInfo;

class IObjHitCB {
public:
    IObjHitCB();
    virtual ~IObjHitCB();

    virtual bool OnCollision(ObjHit* pHitSelf, ObjHit* pHitOther, const gfl::Vec3& rPosition) = 0;
};
