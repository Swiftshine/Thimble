#pragma once

#include <types.h>
#include <ghs_stl/vector.h>
#include <gflCamera.hpp>
#include <gflTask.hpp>

namespace gfl {
    class SceneContext;
    class SceneUpdater;
    class RenderQueue;

    class Scene {
    public:
        virtual ~Scene();

    private:
        /* 0x00 */ u8 mUpdateTaskFlags;
        /* 0x01 */ u8 mUpdateViewTaskFlags;
        /* 0x02 */ u8 mDrawTaskFlags;
        /* 0x03 */ u8 mDrawDRCTaskFlags;
        /* 0x04 */ Task* mUpdateTask;
        /* 0x08 */ Task* mUpdateViewTask;
        /* 0x0C */ Task* mDrawTask;
        /* 0x10 */ Task* mDrawDRCTask;
        /* 0x14 */ u32 m_14;
        /* 0x18 */ u32 m_18;
        /* 0x1C */ u32 m_1C;
        /* 0x20 */ u32 m_20;
        /* 0x24 */ u32 m_24;
        /* 0x28 */ u32 m_28;
        /* 0x2C */ ghs::std::vector<Camera*> mCameras;
        /* 0x3C */ u32 m_3C;
        /* 0x40 */ u32 m_40;
        /* 0x44 */ SceneContext* mSceneContext;
        /* 0x48 */ SceneUpdater* mSceneUpdater;
        /* 0x4C */ RenderQueue* mRenderQueues[3];
        /* 0x58 */ u32 m_58;
        /* 0x5C */ u32 m_5C;
        /* 0x60 */ u32 m_60;
        /* 0x64 */ u32 m_64;
        /* 0x68 */ u32 m_68;
    };

    SIZE_ASSERT(Scene, 0x70);
}
