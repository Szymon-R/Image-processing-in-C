

#include "image_file.h"
image* read_image(const char* file_name, size_t file_name_length)
{
    FILE* inFile;
    image* im;

    inFile = fopen( file_name, "rb" );
    if(!inFile)
    {
        error_handling("Error opening file: ");
        return 0;
    }
    im=(image*)malloc(sizeof(image));
    if(fread(&im->file_header,1,sizeof(BmpFileHeader),inFile)!=sizeof(BmpFileHeader))
    {
	    error_handling("Error reading file header: ");
	    return 0;
	}

	if( fread(&im->info_header, 1, sizeof(BmpInfoHeader), inFile) != sizeof(BmpInfoHeader) )
	{
	     error_handling("Error reading info header: ");
	     return 0;
	}
	im->name=(char*)malloc(file_name_length);
	for(int i=0; i<file_name_length;++i)
    {
        im->name[i]=file_name[i];
    }
    //print_image_info(im);
    return im;
}

void print_image_info(image* im)
{


    printf("\n\tImage: %s",im->name);
    printf("\n\tImage type: %c%c",(*im).file_header.signature[0],im->file_header.signature[1]);
    printf("\n\tFile size: %d",(*im).file_header.fileSize);
    printf("\n\tWidth: %d",(*im).info_header.width);
    printf("\n\tHeight: %d\n",(*im).info_header.height);
}
