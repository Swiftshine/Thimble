#pragma once

#include <ghs_stl/vector.h>

#include <graphics/YsModelControl2.hpp>
#include <object/collision/ColObj.hpp>
#include <object/collision/MapObjHit.hpp>
#include <object/misc/ChildItem.hpp>
#include <object/MapObject.hpp>

class ObjectCollection {
public:
    void AddModelControl(YsModelControl2*);
    void AddColObj(ColObj*);
    void AddMapObjHit(MapObjHit*);
    void AddMapObject(MapObject*);
    void AddChildItem(ChildItem*);
    void RemoveModelControl(YsModelControl2*);
    void RemoveColObj(ColObj*);
    void RemoveMapObjHit(MapObjHit*);
    void RemoveMapObject(MapObject*);
    void RemoveChildItem(ChildItem*);
public:
    /* 0x00 */ ghs::std::vector<YsModelControl2*> mModelControls;
    /* 0x10 */ ghs::std::vector<ColObj*> mColObjs;
    /* 0x20 */ ghs::std::vector<MapObjHit*> mMapObjHit;
    /* 0x30 */ ghs::std::vector<MapObject*> mMapObjects;
    /* 0x40 */ ghs::std::vector<ChildItem*> mChildItems;
};

SIZE_ASSERT(ObjectCollection, 0x50);
