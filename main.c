#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "list.h"
#include "image_file.h"








int main()
{
    image* im;
    node* head;
    im=read_image("czacha.bmp",10);
    head=create_empty_list(10);
    assign_element(head,im,3);
    print_list_info(head);
    insert_empty_node(head,0);
    print_list_info(head);
   return 0;
}

