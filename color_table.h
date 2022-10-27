#ifndef ASTRO_PETER_BMP_FILE_COLOR_TABLE_H_
#define ASTRO_PETER_BMP_FILE_COLOR_TABLE_H_


#include "rgba32_color.h"

class color_table {
  color white { .blue=0xFF, .green=0xFF, .red=0xFF};
  color green {.blue=0x00, .green=0xFF, .red=0x00};
  color purple {.blue=0xFF, .green=0x00, .red=0xFF};
  color yellow {.blue=0x00, .green=0xFF, .red=0xFF};
  color black {.blue=0x00, .green=0x00, .red=0x00};
};

#endif //ASTRO_PETER_BMP_FILE_COLOR_TABLE_H_
