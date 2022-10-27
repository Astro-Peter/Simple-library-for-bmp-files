#ifndef ASTRO_PETER_BITMAP_FILE_HEADER_H
#define ASTRO_PETER_BITMAP_FILE_HEADER_H

#include <cstdint>

#pragma pack(1)

struct bitmap_file_header {
    const char b{'B'};
    const char m{'M'};
    uint32_t file_size{};
    const uint32_t reserved{0};
    const uint32_t offset{60};
};


#endif //ASTRO_PETER_BITMAP_FILE_HEADER_H
