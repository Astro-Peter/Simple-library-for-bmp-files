#ifndef ASTRO_PETER_BMP_FILE_BITMAP_INFO_HEADER_H_
#define ASTRO_PETER_BMP_FILE_BITMAP_INFO_HEADER_H_

#include <cstdint>

struct bitmap_info_header {
    const int32_t header_size{40};
    int32_t width{};
    int32_t height{};
    const uint16_t color_planes{1};
    const uint16_t bits_per_p{4};
    const uint32_t compression{0};
    uint32_t image_size{};
    int32_t res_hor{};
    int32_t res_vert{};
    const uint32_t colors_number{5};
    const uint32_t imp_colors{0};
};

#endif //ASTRO_PETER_BMP_FILE_BITMAP_INFO_HEADER_H_
