#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <ostream>

#include "bitmap_info_header.h"
#include "bitmap_file_header.h"
#include "color_table.h"

void file_write(bitmap_file_header file_head, bitmap_info_header file_info, color_table colors, const uint64_t* image_info,
                uint16_t length, uint16_t width, const std::string& output, uint32_t pad_size){
  std::ofstream bmp(output, std::ofstream::binary);
  bmp.write(reinterpret_cast<const char*>(&file_head), sizeof file_head);
  bmp.write(reinterpret_cast<const char*>(&file_info), sizeof file_info);
  bmp.write(reinterpret_cast<const char*>(&colors), sizeof colors);
  //writing the image by horizontal lines
  for (uint16_t i = 0; i < length; i++){
    for (uint16_t j = 0; j < width; j+=2){
      //std::cout << 'q' << ' ';
      uint8_t pixel1;
      int first = std::min((uint64_t)image_info[j + i * width], (uint64_t) 4);
      if (j == width - 1){
        pixel1 =(uint8_t) (first * 16);
      } else {
        int second = std::min((uint64_t)image_info[j + 1 + i * width], (uint64_t) 4);
        pixel1 = (uint8_t)(first * 16 + second);
      }
      bmp.write(reinterpret_cast<const char *>(&pixel1), sizeof pixel1);
    }
    for (int k = 0; k < pad_size; k++){
      uint8_t s = (char) 0;
      bmp.write(reinterpret_cast<const char *>(&s), sizeof s);
    }
    //std::cout << i << ' ';
    /*if (i == 0){
      break;
    }*/
  }
  std::cout << 'f';
  bmp.close();
}

//void convert_png(bitmap_file_header file_head, bitmap_info_header file_info, color_table colors, const uint64_t* sand_pile,
//                 uint16_t length, uint16_t width, const std::string& output, uint32_t pad_size, const std::string& input){
//  std::ifstream png(input, std::ifstream::binary);
//  char fileStart[8];
//  char stdSequence[8]{-119, 80, 78, 71, 13, 10, 26, 10};
//  uint32_t chunkLength;
//  char chunkType[4];
//  char CRC[4];
//  png >> fileStart;
//  if (fileStart != stdSequence){
//    return;
//  }
//
//}

void draw_line(bitmap_file_header file_head, bitmap_info_header file_info, color_table colors, uint64_t* image_info,
               uint16_t length, uint16_t width, const std::string& output, uint32_t pad_size, uint16_t x1, uint16_t y1,
               uint16_t x2, uint16_t y2, uint16_t thickness){
  float xCoeff = float (y2 - y1) /float (x2 - x1);
  int y;
  for (int x = x1; x <= x2; x++){
    y = int((float)x * xCoeff) + y1;
    image_info[y * length - 1 + x] = 10;
    std::cout << y * length - 1 + x << ' ';
    if (thickness > 1){
      for (int j = 1; j <= (thickness / 2); j++){
        if ((y - j) * length - 1 + x >= 0){
          image_info[(y - j) * length - 1 + x] = 10;
        }
        if ((y + j) * length - 1 + x <= width * length - 1){
          image_info[(y + j) * length - 1 + x] = 10;
        }
      }
    }
  }
  file_write(file_head, file_info, colors, image_info, length, width, output, pad_size);
}

int main(){
  uint16_t width, length;
  width = 500;
  length = 500;
  const uint32_t pad_size = (32 - width * 4 % 32) / 8 % 4;
  bitmap_file_header file_head{.file_size = 74 + (length * (((uint32_t) width * 4) / 8 + pad_size))};
  bitmap_info_header file_info{.width = width, .height = length, .image_size = file_head.file_size - 74, .res_hor = 100, .res_vert = 100};
  color_table colors;
  uint64_t *sand_pile;
  sand_pile = new uint64_t [length * width]{  };
  std::fstream file;
  draw_line(file_head, file_info, colors, sand_pile, length, width, "C:\\Projects\\Test.bmp", pad_size, 0, 499, 499, 250, 10);
}