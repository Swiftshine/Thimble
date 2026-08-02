#pragma once

#include <object/YsHandleObj.hpp>

#define YSGAMEOBJ_OBJECTID_DECL(CLASS) static ObjectTypeInfo<CLASS> TypeInfo;

class YsGameObj : public YsHandleObj {
public:
    template <typename T>
    struct ObjectTypeInfo { };
private:
    YSGAMEOBJ_OBJECTID_DECL(YsGameObj);
public:
    enum class ObjectCategory {
        EnemyObject     = 0,
        Player          = 1,
        PlEgg           = 2,
        Category_3      = 3,    // referenced, but unused
        Category_4      = 4,    // referenced, but unused
        Shell           = 5,
        GimmickObject   = 6,
        Item            = 7,
        Terrain         = 8,
        PlArrow         = 9,
        SpringObject    = 10,
    };

    YsGameObj(int category);

    /* 0x0C */ ~YsGameObj();

    // Returns true if the cast was successful.
    /* 0x14 */ virtual bool ObjectCast(ObjectTypeInfo<YsGameObj>* pTypeInfo, YsHandleObj* pHandleObj);
public:
    /* 0xC */ ObjectCategory mCategory;
};

SIZE_ASSERT(YsGameObj, 0x10);
