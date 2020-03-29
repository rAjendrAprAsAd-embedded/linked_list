#include<stdio.h>
#include<stdlib.h>
struct data 
{
	int value;
	struct data *next;
};
void add_end(struct data **);
void creat_list(struct data **,int);
void print_list(struct data *);
void interchange(struct data **);
main()
{
	struct data *head=NULL;
	int choice;
	//printf("enter choice\n");
	//scanf("%d",&choice);
	//switch(choice)
	//{
		//case 1:
	creat_list(&head,6);
	creat_list(&head,5);
	creat_list(&head,4);
	creat_list(&head,3);
	creat_list(&head,2);
	creat_list(&head,1);
	printf("list before swapping\n");
	print_list(head);
	printf("\n");
	printf("list after swapping\n");
	interchange(&head);
	print_list(head);
	//break;
	  /*      case 2:
	interchange(&head);
	break;
		case 3:
	print_list(head);break;
		case 4:
	add_end(&head);break;
		default:printf("invalid choice\n");return 0;
	}*/
}
void creat_list(struct data **node,int data)
{
	struct data *nu;
	nu=(struct data *)malloc(sizeof(struct data));
	if(nu==NULL)
	{
		printf("memory allocation failed\n");
		return;
	}
	//printf("enter value\n");
	//scanf("%d",&nu->value);
	nu->value=data;
	nu->next=(*node);
	(*node)=nu;

}
void print_list(struct data *p)
{
	int i;
	while(p!=NULL)
	{
		i=(p->value);
		//printf("dummy\n");
		printf("%d",i);
	        p=(p->next);
	}
}
void interchange(struct data **node)
{
	struct data *prev=(*node);//1-2-3-4-5-6
	struct data *cur=(*node)->next;//2-3-4-5-6
	(*node)=cur;//2-3-4-5-6
	if(((*node)==NULL)||((*node)->next==NULL))
	{
		printf("empty linklist");
		return;
	}
	while(1)
	{
		struct data *next=cur->next;//3-4-5-6
		cur->next=prev;//3-1
		if((next==NULL)||(next->next==NULL))
		{
			prev->next=next;
			break;
		}
		prev->next=next->next;
		prev=next;
	        cur=prev->next;
	}
	
}
void add_end(struct data **node)
{
	struct data *nu;
	struct data *temp;
	nu=(struct data *)malloc(sizeof(struct data));
	printf("enter value");
		scanf("%d",&nu->value);
		nu->next=NULL;
		if(*node==NULL)
		{
			*node=nu;
		}
		else
		{
			temp=*node;
			while(temp->next)
			{
				temp=temp->next;
			}
			temp->next=nu;
		}
}

