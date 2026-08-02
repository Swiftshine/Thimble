#include <telkin/Telkin.h>
#include <gfl/gflResArchivedFileInfo.hpp>
#include <gfl/gflMemoryUtil.hpp>
#include <game/file/Bson.hpp>
#include "ThimbleConfig.hpp"

using namespace th;

ThimbleConfig::ThimbleConfig()
    : mBson(nullptr)
{ }

ThimbleConfig::~ThimbleConfig() { }

ThimbleConfig& ThimbleConfig::Instance() {
    static ThimbleConfig inst;
    return inst;
}

void ThimbleConfig::ConfigureFrom(const char* pFilepath) {
    gfl::ResFileObject res = gfl::ResArchivedFileInfo::OpenFileFromArchive("thimble/config.bson", 0);
    tk::println("Read from %s", pFilepath);

    Bson* bson = reinterpret_cast<Bson*>(gfl::Alloc(gfl::HeapID::Work, sizeof(Bson), 4));

    if (bson != nullptr) {
        tk::println("Constructed new Bson object");
        mBson = bson;
    } else {
        tk::println("Failed to construct Bson object");
        mBson = nullptr;
        return;
    }

    mBson->ParseFromFileInfo(res);
    tk::println("Parsed from file info");
}

const Bson* ThimbleConfig::GetBSON() const {
    return mBson.get();
}
