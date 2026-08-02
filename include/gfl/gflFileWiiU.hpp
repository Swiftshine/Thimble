#pragma once

#include <gflFile.hpp>

namespace gfl {

class FileWiiU : public File {
public:

private:
    STRUCT_FILL(0xB2C - 0x28);
};

// SIZE_ASSERT(FileWiiU, 0xB2C);

}
