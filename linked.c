#include<stdio.h>
#include<stdlib.h>
void create_list(int);
void transverse();
int main()
{
	int i,j,t;
	for(i=0;i<5;i++)
	{
	printf("enter the value");
	scanf("%d",&t);
	create_list(t);
	}
	for(j=0;j<5;j++)
	{
		transverse();
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
	  printf("memory is exhausted");
	else
	{
		node_ptr->item=val;
		node_ptr->next=NULL;
		
	}
	return node_ptr;
}
void create_list(int val)
{
	node* new_node_ptr=NULL;
	node* temp;
	new_node_ptr=make_node(val);
	if(new_node_ptr==NULL)
	{
       printf("trying to insert is a non existing node");
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
		 temp->next=new_node_ptr;
	    }
	}
}
void transverse( )
{
	node* temp;
	temp=header;
	while(temp!=NULL)
	{
		printf("item is =%d",temp->item);
		temp=temp->next;
	}
}

	
