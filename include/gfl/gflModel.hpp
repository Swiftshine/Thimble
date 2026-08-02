#pragma once

#include <types.h>

#include <gflRenderObj.hpp>
#include <gflResArchivedFileInfo.hpp>
#include <gflMath.hpp>
#include <gflAnim.hpp>
#include <gflShape.hpp>
#include <gflMaterial.hpp>

#include <nw/g3d.h>

namespace gfl {

class Model : public RenderObj {
public:

private:
    /* 0x70 */ u32 mFlags;
    /* 0x74 */ ResFileObject mResFileObject;
    /* 0x78 */ Matrix34 mModelMatrix;
    /* 0xA8 */ nw::g3d::ModelObj* mModelObj;
    /* 0xAC */ Anim* mAnim;
    /* 0xB0 */ Shape* mShapes;
    /* 0xB4 */ size_t mNumShapes;
    /* 0xB8 */ Material* mMaterials;
    /* 0xBC */ size_t mNumMaterials;
    /* 0xC0 */ STRUCT_FILL(0xF8 - 0xC0);
};

SIZE_ASSERT(Model, 0xF8);

}
