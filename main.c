#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "image_file.h"


#define max1 1000
#define max2 1000




int main()
{
    image* im;
    node* head;

        im=read_image("czacha.bmp",11);
        save_image(im,"plik.bmp");
        head=create_empty_list(max1);
        assign_element(head,im,rand()%max2);
        uint8_t* temp=im->pixels;
        /*
        for(size_t i=0; i<100;++i)
        {
            printf("%d\n",*temp);
            ++temp;
        }*/
        insert_empty_node(head,0);
        delete_list(head);




    //print_list_info(head);

   return 0;
}

