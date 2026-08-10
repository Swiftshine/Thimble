#pragma once
#include <cstddef>
#include <cstdint>
#include <telkin/Preprocessor.h>

using placeholder_t = int;

using u8 = uint8_t;
using s8 = int8_t;
using u16 = uint16_t;
using s16 = int16_t;
using u32 = uint32_t;
using s32 = int32_t;
using u64 = uint64_t;
using s64 = int64_t;
using size_t = std::size_t;
using byte_t = u8;
using char16 = int16_t; // for nw::g3d

#define STRUCT_FILL(size) PP_CONCAT(u8 unk_contents_, __LINE__)[size]
#define PAD(size) PP_CONCAT(u8 padding_, __LINE__)[size]
#define SIZE_ASSERT(C, S) static_assert(sizeof(C) == S, "Size mismatch")
