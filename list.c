#include "list.h"
#include "error_file.h"

node* create_empty_list(size_t elements)
{
    node* head;
    node* previous;
    node* next;
    //printf("%d",sizeof(node));
    head=(node*)malloc(sizeof(node));
    head->list_size=(size_t*)malloc(sizeof(size_t));
    *(head->list_size)=elements;
    previous=head;
    head->val=NULL;

    for(int i=1; i<elements;++i)
    {
        next=(node*)malloc(sizeof(node));
        next->list_size=head->list_size;
        next->val=NULL;
        (*previous).next=next;
        previous=next;
    }
/*
    for(int i=0; i<elements;++i)
    {
        printf("\n%d\n",head->val);
        head=head->next;
    }*/
    return head;
}

int insert_empty_node(node* head,size_t index)
{
    node* element;
    element=head;
    if(index>*head->list_size)
    {
        error_handling("Index is smaller than size of list\n");
        return 0;
    }
    if(index==0)
    {
        for(int i=0;i<*head->list_size;++i)
        {
            element=element->next;
        }
        element->next=(node*)malloc(sizeof(node));
        *head->list_size+=1;
    }
    return head;
}
void print_list_info(node* head)
{
    node* element;
    element=head;
    printf("You have %d elements in your list\n",*head->list_size);
    for(int i=0; i<*head->list_size;++i)
    {
        printf("Element %d: ",i+1);
        if(element->val==NULL)
            printf("is empty\n");
        else
            print_image_info(element->val);
        element=element->next;
    }
}

int assign_element(node* head,image* im,size_t index)
{
    node* element;
    element=head;
    if(index>*head->list_size)
    {
        error_handling("Selected index is out of list boundary\n");
        return 0;
    }
    else
    {
        for(int i=1; i<index;++i)
        {
            element=element->next;
        }
        element->val=im;
    }
    return 1;


}
