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
temp=first->next->next;
prev->next=temp;
}
int looplength(node *slow_ptr)
{
	int count=1;
node *temp=slow_ptr;
while(temp->next!=slow_ptr)
{
count++;
temp=temp->next;
}

return count;

}
/*loopfinding(node *loop)
{
node *temp=first;
node *t=loop;
	
      while(1)
	{
		t=loop;
           while(t->next!=loop && t->next!=temp)
	     {
		t=t->next;
	     }
	if(t->next==temp)
	   break;
          
	temp=temp->next;
	}
	t->next=NULL;
	printf("sfff");
}

*/

int findLoop()
{
node *fast_ptr=first;
node *slow_ptr=first;
while(slow_ptr!=NULL && fast_ptr!=NULL && fast_ptr->next!=NULL)
{
	
	slow_ptr=slow_ptr->next;
	fast_ptr=fast_ptr->next->next;	

	if(slow_ptr==fast_ptr)
	{
		printf("loop find");
		//loopfinding(slow_ptr);
		printf("%d",looplength(slow_ptr));
		return 1;
	}
       
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
 printf("Nill");
}





void main()
{
 int ch=0;
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
           case 3: findLoop();
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


