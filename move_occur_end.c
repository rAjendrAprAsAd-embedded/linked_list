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


node *movend(node* head, int key) 
{ 
  
    // Node to keep pointing to tail 
    node* tail = head; 
    if (head == NULL)  
    { 
        return NULL; 
    } 
    while (tail->next != NULL)  
    { 
        tail = tail->next; 
    } 
      
    // Node to point to last of linked list 
    node* last = tail; 
    node* current = head; 
    node* prev = NULL; 
      
    // Node prev2 to point to previous when head.data!=key 
    node* prev2 = NULL; 
      
    // loop to perform operations to remove key to end 
    while (current != tail)  
    { 
        if (current->data == key && prev2 == NULL)  
        { 
            prev = current; 
            current = current->next; 
            head = current; 
            last->next = prev; 
            last = last->next; 
            last->next = NULL; 
            prev = NULL; 
        } 
        else
        { 
            if (current->data == key && prev2 != NULL) 
            { 
                prev = current; 
                current = current->next; 
                prev2->next = current; 
                last->next = prev; 
                last = last->next; 
                last->next = NULL; 
            } 
            else if (current != tail)  
            { 
                prev2 = current; 
                current = current->next; 
            } 
        } 
    } 
    return head; 
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
           case 3:  scanf("%d",&data);
			first=movend(first,data);
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


