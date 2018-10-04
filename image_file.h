#ifndef IMAGE_FILE_H_INCLUDED
#define IMAGE_FILE_H_INCLUDED

#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "error_file.h"
#pragma pack ( 1 )
typedef struct
{
    char signature[2];
    uint32_t fileSize;
    uint32_t reserved;
    uint32_t offset;

} BmpFileHeader;

typedef struct
{
    uint32_t headerSize;
    uint32_t width;
    uint32_t height;
    uint16_t planeCount;
    uint16_t bitDepth;
    uint32_t compression;
    uint32_t compressedImageSize;
    uint32_t horizontalResolution;
    uint32_t verticalResolution;
    uint32_t numColors;
    uint32_t importantColors;

} BmpInfoHeader;


typedef struct
{
    BmpFileHeader file_header;
    BmpInfoHeader info_header;
    void* pixels;
    char* name;
    //those information are in headers, but they will be used frequently
   /* uint32_t rows;
    uint32_t cols;
    uint32_t row_size;
    uint32_t col_size;
    uint32_t pixel_type;*/

}image;


image* read_image(const char* file_name,size_t file_name_length);
int write_image(image* im);
void print_image_info(image* im);

#endif // IMAGE_FILE_H_INCLUDED
