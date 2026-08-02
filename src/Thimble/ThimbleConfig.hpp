#pragma once

#include <gfl/gflPointer.hpp>
#include <game/file/Bson.hpp>

namespace th {

class ThimbleConfig {
public:
    static ThimbleConfig& Instance();

    ThimbleConfig();
    ~ThimbleConfig();

    void ConfigureFrom(const char* pFilepath);
    const Bson* GetBSON() const;
private:
    gfl::Pointer<Bson> mBson;
    // todo: make a cache
};

}
