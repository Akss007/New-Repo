#include<stdio.h>
#include<stdlib.h>
typedef int itemtype;
typedef struct node_tag
{
	itemtype data;
	struct node_tag* next;	
}node_type;
typedef enum {SUCCESS,FAILURE_HeapFull,FAILURE_ListEmpty,FAILURE_ItemNotFound} status;
void Intialize(node_type* lptr)
{
	lptr->next=NULL;
}
node_type* MakeNode(int d)
{
	system("clear");
	node_type* nptr;
	nptr=(node_type*)malloc(sizeof(node_type));
	if(nptr!=NULL)
	{
		nptr->data=d;
		nptr->next=NULL;
	}
	return nptr;
}
status InsertAtEnd(node_type* lptr,itemtype data)
{
	system("clear");
	node_type* nptr,*temp;
	status sc=SUCCESS;
	temp=lptr;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	nptr=MakeNode(data);
	if(nptr==NULL)
	{
		sc=FAILURE_HeapFull;
	}
	else
	{	temp->next=nptr;
	}
	return sc;
}
status InsertAtStart(node_type* lptr,itemtype data)
{
	system("clear");
	node_type* nptr;
	status sc=SUCCESS;
	nptr=MakeNode(data);
	if(nptr==NULL)
	{
		sc=FAILURE_HeapFull;
	}
	else
	{
		nptr->next=lptr->next;
		lptr->next=nptr;
	}
	return sc;
}
status DeleteAtEnd(node_type* lptr)
{
	system("clear");
	node_type* toDelete,*slastptr;
	status sc=SUCCESS;
	toDelete=lptr;
	if(toDelete==NULL)
	{
		sc=FAILURE_ListEmpty;
	}
	else
	{
		while(toDelete->next!=NULL)
		{
			slastptr=toDelete;
			toDelete=toDelete->next;
		}
		slastptr->next=NULL;
		free(toDelete);
	}	
	return sc;
}
status DeleteAtStart(node_type* lptr)
{
	system("clear");
	status sc=SUCCESS;
	node_type *toDelete;
	toDelete=lptr;
	if(toDelete==NULL)
	{
		sc=FAILURE_ListEmpty;
	}
	else
	{	
		toDelete=lptr->next;
		lptr=toDelete->next;
		free(toDelete);
	}
	return sc;
}
status nodeTraverse(node_type* lptr,itemtype d)
{
	system("clear");
	status sc=FAILURE_ItemNotFound;
	node_type* toFind;
	int flag=0;
	toFind=lptr;
	while(flag==0)
	{
		if(toFind->data==d)
		{
			flag=1;
			sc=SUCCESS;
		}
		else
		{
			toFind=toFind->next;
		}
	}
	return sc;
}
void PrintList(node_type* lptr)
{
	system("clear");
	node_type* nptr;
	int flag=0;
	nptr=lptr;
	if(nptr==NULL)
	{
		printf("The list is Empty\n");
	}
	else
	{
		nptr=lptr->next;
		while(nptr->next!=NULL)
		{
			if(flag==1)
			{
				printf("--->");
			}
			printf("%d",nptr->data);
			nptr=nptr->next;
			flag=1;
		}
		printf("%d",nptr->data);
		printf("---|\n");
	}
}