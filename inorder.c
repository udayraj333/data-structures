#include<stdio.h>
#include<stdlib.h>
void insert_order(int);
int main()
{
	int i,t;
	for(i=0;i<5;i++)
	{
	printf("enter the value");
	scanf("%d",&t);
	insert_order(t);
	}
	
}
typedef struct node_type
{
	int item;
	struct node_type *next;
}node;
node* header=NULL;
node* make_node(int val)
{
	node* node_ptr;
	node_ptr=NULL;
	node_ptr=(node*)malloc(sizeof(node));
	if(node_ptr==NULL)
	printf("memory exhausted");
	else
	{
		node_ptr->item=val;
		node_ptr->next=NULL;
	}
	return node_ptr;
}
void insert_order(int val)
{
	node* new_node_ptr,*temp;
	new_node_ptr=make_node(val);
    if(new_node_ptr==NULL)
    printf("attempting to insert is non exisiting");
    else if(header==NULL)
    header=new_node_ptr;
    else if(new_node_ptr->item<=header->item)
    {
    	new_node_ptr->next=header;
    	header=new_node_ptr;
    	
	}
	else
	{
		temp=header;
		while(((temp->next)->item<=new_node_ptr->item)&&(temp->next!=NULL))
		{
			temp=temp->next;
			
		}
		new_node_ptr->next=temp->next;
		temp->next=new_node_ptr;
		
	}
}
