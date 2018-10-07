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

    for(size_t i=1; i<elements;++i)
    {
        next=(node*)malloc(sizeof(node));
        next->list_size=head->list_size;
        next->val=NULL;
        (*previous).next=next;
        previous=next;
    }
    next->next=NULL;
/*
    for(int i=0; i<elements;++i)
    {
        printf("\n%d\n",head->val);
        head=head->next;
    }*/
    return head;
}
//0 means end if the list. Indexes starts with 1
int insert_empty_node(node* head,size_t index)
{
    node* element;
    node* temp;
    size_t limit=*head->list_size;
    element=head;
    if(index>*head->list_size)
    {
        error_handling("Index is greater than size of the list\n");
        return 0;
    }
    if(index==0)
    {
        for(size_t i=1;i<limit;++i)
        {
            element=element->next;
        }

        element->next=(node*)malloc(sizeof(node));
        element->next->next=NULL;
    }
    else
    {
        for(size_t i=1;i<index-1;++i)
        {
            element=element->next;
        }
        temp=element->next;
        element->next=(node*)malloc(sizeof(node));
        element->next->next=temp;
    }
    *head->list_size+=1;
    element->next->val=NULL;
    return 1;
}
void print_list_info(node* head)
{
    size_t limit=*head->list_size;
    node* element;
    element=head;
    printf("You have %d elements in your list\n",*head->list_size);
    for(int i=0; i<limit;++i)
    {
        printf("Element %d: ",i+1);
        if(print_image_info(element->val)==0)
            printf("is empty\n");
        element=element->next;
    }
}

int assign_element(node* head,image* im,size_t index)
{
    node* element;
    element=head;
    size_t limit=*head->list_size;
    if(index>limit)
    {
        error_handling("Selected index is out of list boundary\n");
        return 0;
    }
    else
    {
        for(size_t i=1; i<index;++i)
        {
            element=element->next;
        }
        element->val=im;
    }
    return 1;
}

int delete_list(node* head)
{
    size_t limit=*head->list_size;
    node* temp;
    free(head->list_size);
    for(size_t i=0; i<limit;++i)
    {
        temp=head->next;
        delete_image(head->val);
        free(head);
        head=temp;
    }
}
