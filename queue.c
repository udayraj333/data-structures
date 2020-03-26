#include<stdio.h>
#include<stdlib.h>
void insert(int);
int dequeue();
typedef struct node_type
{
    int item;
    struct node_type* next;
}node;
node* front=NULL;
node* rear=NULL;
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
void insert(int value)
{
	node* new_node_ptr;
	new_node_ptr=make_node(value);
	if(new_node_ptr==NULL)
	{
		printf("attemting to insert a non-existing node");
	}
	else if(front==NULL&&rear==NULL)
	{
		front=new_node_ptr;
		rear=new_node_ptr;
	}
	else
	{
		rear->next=new_node_ptr;
		rear=new_node_ptr;
	}
}
int dequeue()
{
	node* temp;
	int v;
	if(front==NULL&&rear==NULL)
	{
	   printf("queue is empty");
	   return -1;
	}
	else
	{
		temp=front;
		front=front->next;
		if(front==NULL)
		{
			rear=NULL;
		}
		v=temp->item;
		free(temp);
		return(v);
	}
}
int main()
{
	int i,j,h,l;
	int value;
	for(i=0;i<5;i++)
	{
		printf("enter the number to be insert");
		scanf("%d",&value);
		insert(value);
	}
	for(j=0;j<5;j++)
	{
		h=dequeue();
		printf("\n%d\n",h);
	}
	l=dequeue();
	printf("\n%d\n",l);
}
	
		

	
