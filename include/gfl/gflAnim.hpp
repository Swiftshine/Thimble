#pragma once

#include <gflAnimBlend.hpp>
#include <gflAnimObj.hpp>
#include <ghs_stl/vector.hpp>

namespace gfl {

class Model;

class Anim {
public:
    struct BuildInfo {
        size_t GetAnimObjCount() const;

        void* mAnimObjBuildInfo;
    };

    Anim(BuildInfo* pBuildInfo, Model* pModel);
    virtual ~Anim();

    void fn_02C1C950();
    void UpdateFrame(size_t animIndex, float arg2);
    void CalcShapeAnimations(AnimObj* pAnimObj);
    void CalcShapeAnimations(size_t animIndex, bool arg2);
    void CalcShapeAnimations(AnimObj* pAnimObj, bool arg2);
    void fn_02C1Cf08(size_t animIndex);
    float GetCurrentFrame(size_t animIndex) const;
    float GetEndFrame(size_t animIndex) const;
    bool IsAnimationDone(size_t animIndex) const;
    void SetUpdateRate(size_t animIndex, float rate);
    bool HasAnimation(size_t animIndex) const;
    void SetHasAnimation(size_t animIndex, bool arg2);
    bool ShouldUpdate(size_t animIndex) const;
    bool HasSkeletalAnimation(size_t animIndex) const;
    AnimObj* GetAnimObj(size_t animIndex) const;
    AnimObj* GetActiveAnimObj() const;
    void fn_02C1D188();
    void fn_02C1D2C8();
    size_t GetNumAnimObjs() const;

private:
    /* 0x00 */ Model* mModel;
    /* 0x04 */ size_t mActiveAnimObjIndex;
    /* 0x08 */ int m_8;
    /* 0x0C */ ghs::std::vector<AnimObj*> mAnimObjs;
    /* 0x1C */ AnimBlend* mAnimBlend;
    /* 0x20 */ bool m_20;
    /* 0x21 */ bool m_21;
    /* 0x22 */ bool m_22;
    /* 0x23 */ bool m_23;
    /* 0x24 */ u32 m_24;
    /* 0x28 */ u32 m_28;
    /* 0x2C */ u32 m_2C;
    /* 0x30 */ u32 m_30;
    /* 0x34 */ u32 m_34;
    /* 0x38 */ u32 m_38;
    /* 0x3C */ u32 m_3C;
    /* 0x40 */ u32 m_40;
    /* 0x44 */ AnimObj* mActiveAnimObj;
    /* 0x48 */ u32 m_48;
};

SIZE_ASSERT(Anim, 0x50);
} // namespace gfl
