
 # include <stdio.h>
# include <stdlib.h>

struct list
{
 int data;
 struct list *next;
};
typedef struct list node;
 node *first=NULL;


void create()
{
first=NULL;
int n;node *temp,*prev=first;
	printf("how many node u want create :");
	scanf("%d",&n);
while(n--)
{	
    temp=(node *)(malloc(sizeof(node)));
     printf("\n Enter the numbers ");
    scanf("%d",&temp->data);
      if(first==NULL) //here we are checking our node is first or not 
        {
          first=temp;
           prev=first;
        }
        else
          {	
            prev->next=temp;
            prev=temp;	      
	     
          }
   }
}


void delete(int x) 
{ 
        node** tmp1 = NULL; 
	node **a=&first;
        while(*a) { 
                if((*a)->data == x) { 
                        tmp1 = a; 
                } 
                a = &(*a)->next; 
        } 
        if(tmp1) { 
                node* tmp = *tmp1; 
                *tmp1 = tmp->next; 
                free(tmp); 
        } 
} 

void print(node *temp)
{
 printf("\n The list is \n");
 printf(" -----------\n");
 while(temp!=NULL)
 {
  printf("%d-->",temp->data);
  temp=temp->next;
 }
printf("NULL");
}





void main()
{
 int ch=0,x;
 first=NULL;
 printf("\n Linked List creation \n");
 while(1)
{printf("...\n");
  
	scanf("%d",&ch);
    switch(ch)  
	{
           case 1: create();
       		   //print(first);
		   break;
           case 2: print(first);
       	           break;
           case 3:printf("enter the value");
			 scanf("%d",&x);
			delete(x);
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


