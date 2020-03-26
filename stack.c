#include<stdio.h>
#define max 5
int top=-1;
void push(int*,int);
int pop(int*);
int main()
{
  int stk[max];
  int i,k,j,item,l,m;
  for(i=0;i<max;i++)
  {
  printf("enter stk[%d]=",i);
  scanf("%d",&stk[i]);
  }	
  for(j=0;j<max;j++)
  {
  item=stk[j];
  push(stk,item);
  }
  push(stk,item);
  for(k=0;k<max;k++)
  {
  l=pop(stk);
  printf("\n%d\n",l);
  }
  m=pop(stk);
  printf("\n%d\n",m);
}
void push(int stk[],int item)
{ 
  if (top>=max-1)
  printf("\nstack is full\n");
  else
  {
  top++;
  stk[top]=item;
  }
}
int pop(int stk[])
{
	int temp;
	if(top==-1)
	{
	printf("\nstack is empty\n");
	return -1;
	}
    else
     {
	  temp=stk[top];
	  top--;
	  return(temp);
	  }
}	  






