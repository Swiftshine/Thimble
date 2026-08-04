#pragma once

#include <types.h>
#include <telkin/Telkin.h>

namespace th {
    inline void PatchInstruction(u32 address, u32 instr) {
        // US addr
        const u32 CONSOLE_TEXT_OFFSET = 0x0C700000;
        #if defined(__CONSOLE__)
            address += CONSOLE_TEXT_OFFSET;
        #endif

        u32 instruction = instr;

        tk::privilegedWrite((const void*)address, (const void*)&instruction, sizeof(u32));
    }
}
