#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node * link;
};
insertAtBeg(struct node **head,int a)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=a;
	new->link=*head;
	*head=new;
	return;
}
insertAtLast(struct node **head,int a)
{
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=a;
	new->link=NULL;
	if(*head==NULL)
        {
		*head=new;
	}
	else
	{
              struct node *last=*head;
	      while(last->link)
	      last=last->link;
	      last->link=new;
		
        }
	return;
}
insertAfterAny(struct node **head,int a,int b)
{

	struct node *t=*head;
	while(t->data!=b)
	{
		t=t->link;
		if(t==NULL)
		{
			printf("sorry element not found\n");
			return;
		}

	}
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->data=a;
	new->link=t->link;
	t->link=new;
	return;
}
deleteAtbeg(struct node **head)
{
	struct node *t=*head;
	*head=(*head)->link;
	free(t);
}
deleteAtLast(struct node **head)
{	
	struct node *last=*head;
	if(last==NULL)
	printf("List is empty\n");
	else if(last->link==NULL)
	{
		free(last);
		*head=NULL;
	}
	else
	{
		while(last->link->link!=NULL)
		last=last->link;
	free(last->link);
	last->link=NULL;
	}
	return;
}
deleteAtAny(struct node **head,int a)
{
	struct node *t=*head,*t1;
	while(t->data!=a)
	{
		t=t->link;
		if(t==NULL)
		{
		printf("Sorry element not found\n");
		return;
		}
	}
	t1=t->link;
	t->link=t->link->link;
	free(t1);
	
	
}
printList(struct node **head)
{
	if(*head==NULL)
	printf("List is empty\n");
	else
	{
		struct node *t=*head;
		while(t)
		{
			printf("%d  ",t->data);
			t=t->link;
		}
		printf("\n");
	}
	return;
}
int main()
{
	struct node *start=NULL;
	int ch,a,b;
while(1)
{
	printf(
"Enter your choice: \n\
1: Insert at beginning\n\
2: Delete at beginning\n\
3: Insert at last\n\
4: Delete at last\n\
5: Insert at Any position\n\
6: Delete at Any position\n\
7: Print the list\n\
8: Exit\n"     );
	scanf("%d",&ch);
	switch(ch)
	{
		
		case 1: printf("Enter the data\n");
			scanf("%d",&a);
			insertAtBeg(&start,a);
			break;
		case 2: deleteAtbeg(&start);
			break;
		case 3: printf("Enter the data\n");
			scanf("%d",&a);
			insertAtLast(&start,a);
			break;
		case 4: deleteAtLast(&start);
			break;
		case 5: printf("Enter the data\n");
			scanf("%d",&a);
			printf("Enter the element after you want to insert:-");
			scanf("%d",&b);
			insertAfterAny(&start,a,b);
			break;
		case 6: printf("Enter the element after which you want to delete:-\n");
			scanf("%d",&a);
			deleteAtAny(&start,a);
			break;
		case 7: printList(&start);
			break;
		case 8: exit(0);


	}
}	
	
}
