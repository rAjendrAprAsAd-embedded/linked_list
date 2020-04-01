#include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};

typedef struct list node;
node *first=NULL;


/* Function to remove duplicates from a sorted list */
void remove_duplicates()
{
    node *ptr1, *ptr2, *duplicate,*temp=first;
   
	 ptr1 = temp;

    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        while (ptr2->next != NULL)
        {
            if (ptr1->data == ptr2->next->data)
            {
                duplicate = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(duplicate);
            }
            else
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}


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

}

loopfinding(node *loop)
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
}



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
		loopfinding(slow_ptr);
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
           case 3: remove_duplicates();
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


