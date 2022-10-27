#ifndef ASTRO_PETER_BMP_FILE_RGBA32_COLOR_H_
#define ASTRO_PETER_BMP_FILE_RGBA32_COLOR_H_

#include <cstdint>

struct color{
  uint8_t blue{};
  uint8_t green{};
  uint8_t red{};
  uint8_t zero{0x00};
};

#endif //ASTRO_PETER_BMP_FILE_RGBA32_COLOR_H_
