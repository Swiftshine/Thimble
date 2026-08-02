#pragma once

#include <gfl/gflPointer.hpp>

#include <object/GimmickObject.hpp>
#include <graphics/YsModelControl2.hpp>
#include <object/collision/ColObjTrans.hpp>
#include <object/collision/ObjHit.hpp>
#include <object/collision/MapObjHit.hpp>
#include <object/control/OtherEggCtrl.hpp>

class GmkEggBox : public GimmickObject {
public:
    /* 0x180 */ gfl::Pointer<YsModelControl2> mModelControl;
    /* 0x184 */ gfl::Pointer<ColObjTrans> mColObjTrans;
    /* 0x188 */ gfl::Pointer<ObjHit> mObjHit;
    /* 0x18C */ MapObjHit mMapObjHit;
    /* 0x1AC */ gfl::Pointer<OtherEggCtrl> mOtherEggCtrl;
    /* 0x1B0 */ u32 m_1B0;
    STRUCT_FILL(0x23C - 0x1B4);
};


SIZE_ASSERT(GmkEggBox, 0x23C);
