#pragma once

#include <types.h>

#include <manager/DentManager.hpp>
#include <gfl/gflMath.hpp>

class ChildItem {
public:
    ChildItem(const char* pOwnerName);
    ~ChildItem();

    void Deregister();
    void Register();
    bool HasDentManager() const;
    void fn_0204B408(bool);
    void fn_0204B410(u32);
    bool fn_0204B46C() const;
    void fn_0204B474();
    void fn_0204B4D4(u32);
    u32 fn_0204B4DC() const;
    void SetPosition(const gfl::Vec3& rPos);
    const gfl::Vec3& GetPosition() const;
    void SetOffset(const gfl::Vec3& rOffs);
    const gfl::Vec3& GetOffset() const;
    void fn_0204B52C(u32);
    u32 fn_0204B534() const;
    void fn_0204b53C(const gfl::Vec2&);
    const gfl::Vec2& fn_0204B554() const;
    void fn_0204B55C(f32);
    f32 fn_0204B564() const;
    void fn_0204B56C(f32);
    f32 fn_0204B574() const;
private:
    /* 0x00 */ const char* mOwnerName;
    /* 0x04 */ DentManager* mDentManager;
    /* 0x08 */ bool m_8;
    /* 0x0C */ u32 m_C;
    /* 0x10 */ gfl::Vec3 mPosition;
    /* 0x1C */ gfl::Vec3 mOffset;
    /* 0x28 */ u32 m_28;
    /* 0x2C */ gfl::Vec2 m_2C;
    /* 0x34 */ f32 m_34;
    /* 0x38 */ f32 m_38;
    /* 0x3C */ bool m_3C;
};

SIZE_ASSERT(ChildItem, 0x40);
