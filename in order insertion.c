#include<stdio.h>
#include<stdlib.h>
void insertorder(int);
void traverse();
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
void insertorder(int value)
{
	node* new_node_ptr;
	node* temp;
	new_node_ptr=make_node(value);
	if(new_node_ptr==NULL)
	{
		printf("memory exhausted");
	}
	else if(header==NULL)
	{
		header=new_node_ptr; 
	}
	else if(new_node_ptr->item<=header->item)
	{
		new_node_ptr->next=header;
		header=new_node_ptr;
	}
	else
	{
		temp=header;
		while(((temp->next!=NULL)&&((temp->next)->item<=new_node_ptr->item)))
		{
			temp=temp->next;
		}
		new_node_ptr->next=temp->next;
		temp->next=new_node_ptr;
	}
}
void traverse()
{
	node* temp;
	temp=header;
	while(temp!=NULL)
	{
		printf("\nitem is=%d\n",temp->item);
		temp=temp->next;
	}
}
int main()
{
	int i;
	int value;
	
	for(i=0;i<5;i++)
	{
		printf("enter the value");
		scanf("%d",&value);
		insertorder(value);
	}
	traverse();
	insertorder(100);
	traverse();
}

	

			
