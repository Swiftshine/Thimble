#pragma once

#include "gfl/gflResArchivedFileInfo.hpp"
#include <types.h>
#include <ghs_stl/string.h>

class Bson {
private:
    struct StringEntry {
        size_t mOffset;
        size_t mLength;
    };
public:
    enum class NodeType : u32 {
        Root            = 300,
        Object          = 301,
        Array           = 302,
        Integer         = 303,
        Float           = 304,
        String          = 305,
        Bool            = 306,
        StringTable     = 400,
        StringBank      = 500,
        EndOfFile       = 900,
    };

    struct Node {
        NodeType mNodeType;
        size_t mNodeSize;
    };

    struct ObjectNode : Node {
        size_t mNumNodes;
        byte_t mNodes[];
    };

    struct ArrayNode : Node {
        size_t mNumNodes;
        byte_t mNodes[];
    };

    Bson();
    ~Bson();

    bool ParseFromFileInfo(const gfl::ResFileObject& rResFileObject);
    bool ParseFromBytes(byte_t* pRawBytes, void* pArg2, const ghs::std::string& rFilepath);
    ObjectNode* GetObject(const char* pNodeName);
    ArrayNode* GetArray(const char* pNodeName);
    bool GetBoolFromObject(ObjectNode* pObject, const char* pNodeName, bool defaultValue = false);
    const char* GetStringFromObject(ObjectNode* pObject, const char* pNodeName, const char* defaultValue = nullptr);
    float GetFloat(ObjectNode* pObject, const char* pNodeName, float defaultValue = 0.0f);
    int GetInt(ObjectNode* pObject, const char* pNodeName, int defaultValue = 0);
    const char* GetStringFromRoot(const char* pKey, const char* defaultValue = "") const;

public:
    /* 0x00 */ ghs::std::string mFilepath;
    /* 0x20 */ void* mResArchivedFileInfo; // of type gfl::ResArchivedFileInfo
    /* 0x24 */ byte_t* mRawBytes;
    /* 0x28 */ byte_t* mRootObject;
    /* 0x2C */ StringEntry* mStringTable;
    /* 0x30 */ size_t mNumStrings;
    /* 0x34 */ byte_t* mStringBank;
    /* 0x38 */ u32 m_38;
};

SIZE_ASSERT(Bson, 0x3C);
