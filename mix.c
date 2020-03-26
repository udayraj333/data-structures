#include<stdio.h>
#include<stdlib.h>
void createlist1(int);
void createlist2(int);
void joinlist();
void traverse();
typedef struct node_type
{
    int item;
    struct node_type* next;
}node;
node* header1=NULL;
node* header2=NULL;
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
void createlist1(int value1)
{
	node* new_node_ptr=NULL;
	node* temp;
	new_node_ptr=make_node(value1);
	if(new_node_ptr==NULL)
	{
		printf("insert is failed");
	}
	else if(header1==NULL)
	{
		header1=new_node_ptr;
	}
	else
	{
		temp=header1;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node_ptr;
	}
}
void createlist2(int value2)
{
	node* new_node_ptr=NULL;
	node* temp;
	new_node_ptr=make_node(value2);
	if(new_node_ptr==NULL)
	{
		printf("insert is failed");
	}
	else if(header2==NULL)
	{
		header2=new_node_ptr;
	}
	else
	{
		temp=header2;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new_node_ptr;
	}
}
void joinlist()
{
    node* temp;
    temp=header1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=header2;
    header=header1;
}
void traverse()
{
    node* temp;
    temp=header;
    while(temp!=NULL)
    {
        printf("item is=%d\n",temp->item);
        temp=temp->next;
    }
}
int main()
{
    int i,j;
    int value1,value2;
    for(i=0;i<5;i++)
    {
        printf("enter the value1");
        scanf("%d",&value1);
        createlist1(value1);
    }
    
    for(j=0;j<5;j++)
    {
        printf("enter the value2");
        scanf("%d",&value2);
        createlist2(value2);
    }

    joinlist();
    traverse();
}
