# include <stdio.h>
# include <stdlib.h>
//#ifndef string
/*#define x(y)  scanf("%c",&y->data);
struct list 
{
char data;
struct list *next;
}
#else
#define x(y)  scanf("%d",&y->data);
struct list
{
 int data;
 struct list *next;
};
#endif*/
struct list
{
 int data;
 struct list *next;
};
typedef struct list node;
 node *first=NULL;


void create(node **x)
{
int n;node *temp,*prev=*x;
	printf("how many node u want create :");
	scanf("%d",&n);
while(n--)
{	
    temp=(node *)(malloc(sizeof(node)));
     printf("\n Enter the numbers ");
    scanf("%d",&temp->data);
      if(*x==NULL) //here we are checking our node is first or not 
        {
          *x=temp;
           prev=*x;
        }
        else
          {	
            prev->next=temp;
            prev=temp;	      
	     
          }
   }
}


void middlehead(node** head) 
{ 
    if (*head == NULL) 
        return; 
  	
	node* one_node = (*head); 
  
    node* two_node = (*head); 
  
    node* prev = NULL; 
    while (two_node != NULL && two_node->next != NULL) { 
  
        /* for previous node of middle node */
        prev = one_node; 
  
        /* move two node each time*/
        two_node = two_node->next->next; 
  
        /* move one node each time*/
        one_node = one_node->next; 
    } 
  
    /* set middle node at head */
    prev->next = prev->next->next; 
    one_node->next = (*head); 
    (*head) = one_node; 
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
 int ch=0,data;
 first=NULL;
 printf("\n Linked List creation \n");
 while(1)
{printf("...\n");
  
	scanf("%d",&ch);
    switch(ch)  
	{
           case 1:
			create(&first);
		
		   break;
           case 2: print(first);
       	           break;
           case 3:  middlehead(&first);
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


