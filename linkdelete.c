#include<stdio.h>
#include<stdlib.h>
void createlist(int);
void traverse();
void delete(int);
typedef struct node_type
{
    int item;
    struct node_type* next;
}node;
node* header=NULL;
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
void createlist(int value)
{
	node* new_node_ptr=NULL;
	node* temp;
	new_node_ptr=make_node(value);
	if(new_node_ptr==NULL)
	{
		printf("insert is failed");
	}
	else if(header==NULL)
	{
		header=new_node_ptr;
	}
	else
	{
		temp=header;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node_ptr;
	}
}
void traverse()
{
	node* temp1;
	temp1=header;
	while(temp1!=NULL)
	{
		printf("\nitem is=%d\n",temp1->item);
		temp1=temp1->next;
	}
}
void delete(int value2)
{
    node* temp;
    node* pred;
    if(header==NULL)
    {
        printf("linked list empty");
        return;
    }
    else if(header->item==value2)
    {
        header=header->next;
        return;
    }
    else
    {
        temp=header;
        while((temp->next!=NULL)&&(temp->item!=value2))
        {
            pred=temp;
            temp=temp->next;
        }
        if(temp->item!=value2)
        {
            printf("item is not found");
            return;
        }
        else
        {
            pred->next=temp->next;
        }
    }
}
int main()
{
	int i,j;
	int value,value2;
	for(i=0;i<5;i++)
	{
		printf("enter the value to be inserted");
		scanf("%d",&value);
	    createlist(value);
	}
	traverse();
	printf("\nenter the value to be removed\n");
	scanf("%d",&value2);
	delete(value2);
	traverse();
}