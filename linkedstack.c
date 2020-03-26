#include<stdio.h>
#include<stdlib.h>
void push(int);
int pop();
typedef struct node_type
{
    int item;
    struct node_type* next;
}node;
node* top=NULL;

node* make_node(int value)
{
    node* node_ptr;
    node_ptr=NULL;
    node_ptr=(node*)malloc(sizeof(node));
    if(node_ptr==NULL)
    {
        printf("memory exhausted");
    }
    else
    {
       node_ptr->item=value;
       node_ptr->next=NULL;
    }
    return node_ptr;
}
void push(int value)
{
    node* new_node_ptr;
    new_node_ptr=make_node(value);
    if(new_node_ptr==NULL)
    {
        printf("attempting to push a non existing node");
    }
    else if(top==NULL)
    {
        top=new_node_ptr;
    }
    else
    {
        new_node_ptr->next=top;
        top=new_node_ptr;
    }
}
int pop()
{
    node* temp;
    int v;
   if(top==NULL)
    {
        printf("empty");
        return -1;
    }
    else
    {
       temp=top;
        top=top->next;
        v=temp->item;
        free(temp);
    }
    return(v);
}
int main()
{
    int i,j,h,l;
    int value;
    for(i=0;i<5;i++)
    {
       printf("enter the value to be pushed");
       scanf("%d",&value);
       push(value);
    }
    for(j=0;j<5;j++)
    {
        h=pop();
        printf("\n%d\n",h);
     }
    l=pop();
    printf("\n%d\n",l);
}


    
    
    