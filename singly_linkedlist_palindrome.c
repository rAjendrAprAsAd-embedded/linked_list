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

void reverse_node(node** head_ref) 
{ 
    node* prev = NULL; 
   node* current = *head_ref; 
    node* next; 
    while (current != NULL) { 
        next = current->next; 
        current->next = prev; 
        prev = current; 
        current = next; 
    } 
	 *head_ref = prev; 
} 

int palindrome()
{

node *midnode;
node *tm=NULL;
node *temp=first;

node *slow_ptr=temp;
node *fast_ptr=temp;
	
 while (fast_ptr!= NULL && fast_ptr->next!=NULL) 
    { 
        fast_ptr = fast_ptr-> next->next; 
        slow_ptr=slow_ptr->next; 
     } 	
    if (fast_ptr!= NULL) { //for odd nodes
            midnode = slow_ptr; 
            slow_ptr= slow_ptr->next; 
        } 
 tm=slow_ptr;

reverse_node(&tm); 

while((tm!=NULL) && temp )
{
if(tm->data==temp->data)
{
tm=tm->next;
temp=temp->next;
}

else { printf("not palindrome \n");
       return  0;}
}

printf("palindrome\n");
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
           case 3: palindrome();
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


