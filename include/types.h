#pragma once
#include <cstdint>
#include <telkin/Preprocessor.h>

using u8 = uint8_t;
using s8 = int8_t;
using u16 = uint16_t;
using s16 = int16_t;
using u32 = uint32_t;
using s32 = int32_t;
using u64 = uint64_t;
using s64 = int64_t;

#define STRUCT_FILL(size) PP_CONCAT(u8 unk_contents_, __LINE__)[size]
#define PAD(size) PP_CONCAT(u8 padding_, __LINE__)[size]
#define SIZE_ASSERT(C, S) static_assert(sizeof(C) == S, "Size mismatch")
