#pragma once

#include <gfl/gflTask.hpp>
#include <gfl/gflMath.hpp>
#include <object/YsGameObj.hpp>
#include <object/collision/IObjHitCB.hpp>
#include <graphics/FlfMdlDraw.hpp>
#include <util/BitsetWrapper.hpp>

class MapObject : public YsGameObj, public IObjHitCB {
public:
    enum class Flags {
        ShouldDelete = 1 << 0x1A,
    };

    static u32 sMapObjectCount;

    MapObject(int category, int arg2, const char* pTaskName);
    ~MapObject();

    /* 0x014 */ virtual bool ObjectCast(ObjectTypeInfo<YsGameObj>* pTypeInfo, YsHandleObj* pHandleObj) override;
    /* 0x01C */ virtual bool OnCollision(ObjHit* pHitSelf, ObjHit* pHitOther, const gfl::Vec3& rPosition) override;
    /* 0x024 */ virtual void vf24();
    /* 0x02C */ virtual void Init();
    /* 0x034 */ virtual void vf34();
    /* 0x03C */ virtual void vf3C();
    /* 0x044 */ virtual void vf44();
    /* 0x04C */ virtual void vf4C();
    /* 0x054 */ virtual void vf54();
    /* 0x05C */ virtual void vf5C();
    /* 0x064 */ virtual void vf64();
    /* 0x06C */ virtual void vf6C();
    /* 0x074 */ virtual void vf74();
    /* 0x07C */ virtual void vf7C();
    /* 0x084 */ virtual void vf84();
    /* 0x08C */ virtual void vf8C();
    /* 0x094 */ virtual void vf94();
    /* 0x09C */ virtual void vf9C();
    /* 0x0A4 */ virtual void vfA4();
    /* 0x0AC */ virtual void vfAC();
    /* 0x0B4 */ virtual void vfB4();
    /* 0x0BC */ virtual void vfBC();
    /* 0x0C4 */ virtual void vfC4();
    /* 0x0CC */ virtual void vfCC();
    /* 0x0D4 */ virtual void vfD4();
    /* 0x0DC */ virtual void vfDC();
    /* 0x0E4 */ virtual void vfE4();
    /* 0x0EC */ virtual void vfEC();
    /* 0x0F4 */ virtual void vfF4();
    /* 0x0FC */ virtual void vfFC();
    /* 0x104 */ virtual void UpdateGraphics();
    /* 0x10C */ virtual void UpdateMatrix();
    /* 0x114 */ virtual void UpdateModelMatrix();
    /* 0x11C */ virtual void vf11C();
    /* 0x124 */ virtual void vf124();
    /* 0x12C */ virtual void SetPrimaryTaskFlags(bool set, u32 flag);
    /* 0x134 */ virtual void vf134();
    /* 0x13C */ virtual void SetPosition(const gfl::Vec3& rPosition);
    /* 0x144 */ virtual void SetOtherPosition(const gfl::Vec3& rPosition);
    /* 0x14C */ virtual const gfl::Vec3& GetOtherPosition() const;
    /* 0x154 */ virtual void vf154();
    /* 0x15C */ virtual void vf15C();
    /* 0x164 */ virtual void vf164();
    /* 0x16C */ virtual void vf16C();
    /* 0x174 */ virtual void vf174();
    /* 0x17C */ virtual void vf17C();
    /* 0x184 */ virtual void vf184();
    /* 0x18C */ virtual void vf18C();
    /* 0x194 */ virtual void vf194();
    /* 0x19C */ virtual void vf19C();
    /* 0x1A4 */ virtual void vf1A4();
    /* 0x1AC */ virtual void vf1AC();
    /* 0x1B4 */ virtual void vf1B4();
    /* 0x1BC */ virtual void vf1BC();
    /* 0x1C4 */ virtual void vf1C4();
    /* 0x1CC */ virtual void vf1CC();
    /* 0x1D4 */ virtual void vf1D4();
    /* 0x1DC */ virtual void Update();
    /* 0x1E4 */ virtual void vf1E4();
    /* 0x1EC */ virtual void vf1EC();
    /* 0x1F4 */ virtual void vf1F4();
    /* 0x1FC */ virtual void vf1FC();
    /* 0x204 */ virtual void vf204();
    /* 0x20C */ virtual void vf20C();
    /* 0x214 */ virtual void vf214();
    /* 0x21C */ virtual void vf21C();
    /* 0x224 */ virtual void vf224();
    /* 0x22C */ virtual void vf22C();
    /* 0x234 */ virtual void vf234();
    /* 0x23C */ virtual void vf23C();
    /* 0x244 */ virtual void vf244();
    /* 0x24C */ virtual void vf24C();
    /* 0x254 */ virtual void vf254();
    /* 0x25C */ virtual void OnDelete();
    /* 0x264 */ virtual void vf264();
    /* 0x26C */ virtual void vf26C();
    /* 0x274 */ virtual void vf274();
    /* 0x27C */ virtual void vf27C();
    /* 0x284 */ virtual void vf284();

    void SetFlags(u32, bool);

    void DeleteSelf();
public:
    /* 0x014 */ gfl::Task mPrimaryTask;
    /* 0x030 */ gfl::Task* mSecondaryTask;
    /* 0x034 */ u32 mObjectID;
    /* 0x038 */ u32 mFramesActive;
    /* 0x03C */ FlfMdlDraw* mFlfMdlDraw;
    /* 0x040 */ gfl::Matrix34 mMatrix;
    /* 0x070 */ gfl::Matrix34 mModelMatrix;
    /* 0x0A0 */ gfl::Vec3 mPosition;
    /* 0x0AC */ gfl::Vec3 mModelPosition;
    /* 0x0B8 */ gfl::Vec3 m_B8;
    /* 0x0C4 */ gfl::Vec3 m_C4;
    /* 0x0D0 */ u32 m_D0;
    /* 0x0D4 */ u32 m_D4;
    /* 0x0D8 */ u32 m_D8;
    /* 0x0DC */ gfl::Vec3 m_DC;
    /* 0x0E8 */ gfl::Vec3 m_E8;
    /* 0x0F4 */ gfl::Vec3 m_F4;
    /* 0x100 */ u32 m_100;
    /* 0x104 */ u32 m_104;
    /* 0x108 */ u32 m_108;
    /* 0x10C */ BitsetWrapper29 mFlags;
    /* 0x110 */ u32 m_110;
    /* 0x114 */ u32 m_114;
};

SIZE_ASSERT(MapObject, 0x118);
