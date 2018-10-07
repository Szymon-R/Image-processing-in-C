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
        head=create_empty_list(max1);
        assign_element(head,im,rand()%max2);
        insert_empty_node(head,0);
        delete_list(head);




    //print_list_info(head);

   return 0;
}

