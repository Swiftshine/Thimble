#pragma once

#include <gflAnimBlend.hpp>
#include <gflHeapWiiU.hpp>
#include <gflResArchivedFileInfo.hpp>
#include <nw/g3d.h>

namespace gfl {

class Model;

class AnimObj {
public:
    enum class AnimFlags : u32 {
        None            = 0,
        Skeletal        = 1 << 0,
        ShaderParam     = 1 << 1,
        TexturePattern  = 1 << 2,
        Visibility      = 1 << 3,
        Shape           = 1 << 4,
        All             = 0xFF
    };

    AnimObj(void* pBuildInfo, Model* pModel);
    virtual ~AnimObj();

    nw::g3d::ShaderParamAnimObj* MakeShaderParamAnimObj(u32 arg1, u32 arg2, void* pArg3);
    void fn_02C2000C(u32 arg1, void* pArg2) const;
    void Init(const gfl::ResFileObject resFileObject, void* pBuildInfo, Model* pModel);
    void SetUpdateRate(float rate);
    void DestroyAnimObj(gfl::HeapWiiU* pHeap, nw::g3d::ModelAnimObj* pAnimObj);
    nw::g3d::BindResult Bind();
    float GetCurrentFrame() const;
    void UpdateFrame(float arg1);
    bool IsAnimationDone() const;
    float GetUpdateRate() const;
    void SetHasAnimation(bool hasAnimation);
    void UpdateFrame(u32 animFlags);
    void Calc(nw::g3d::ModelAnimObj* pAnimObj);
    void Calc(u32 animFlags);
    void fn_02C215F4();
    bool TryBind();
    bool fn_02C2175C(u32 arg1, u32 arg2, void* pArg3);
    void SetAnimFlags(u32 animFlags);
    void UpdateFrame();
    void Calc();
private:
    /* 0x00 */ float mEndFrame;
    /* 0x04 */ bool mHasAnimation;
    /* 0x05 */ bool mShouldUpdate;
    /* 0x06 */ bool m_6;
    /* 0x08 */ Model* mModel;
    /* 0x0C */ nw::g3d::SkeletalAnimObj* mSkeletalAnimation;
    /* 0x10 */ nw::g3d::ShaderParamAnimObj* mShaderParamAnimation1;
    /* 0x14 */ nw::g3d::ShaderParamAnimObj* mShaderParamAnimation2;
    /* 0x18 */ nw::g3d::ShaderParamAnimObj* mShaderParamAnimation3;
    /* 0x1C */ nw::g3d::TexPatternAnimObj* mTexturePatternAnimation;
    /* 0x20 */ nw::g3d::VisibilityAnimObj* mVisibilityAnimation1;
    /* 0x24 */ nw::g3d::VisibilityAnimObj* mVisibilityAnimation2;
    /* 0x28 */ nw::g3d::ShapeAnimObj* mShapeAnimation;
    /* 0x2C */ AnimFlags mAnimFlags;
};

SIZE_ASSERT(AnimObj, 0x34);

}
