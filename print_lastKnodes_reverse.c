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

}

//can  u check this below commented code

//i/p 1 2 3 4 5 6  7 8   n=3     o/p 8 7 6
 /*
void recur(node* temp,int n) 
{ static int count=0;
    if (!temp) 
        return; 
   
    recur(temp->next,--n);
      (*count)++; 
   if((*count)<=n)
	printf("%d ",temp->data); 
} */
  

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

void  lastrever(int n)
{
int count=1;
node *temp=first;
reverse_node(&temp);
for(count =1;count<=n;count++)
{
printf("%d  ",temp->data);
temp=temp->next;
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
 int ch=0,n;
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
           case 3:printf("enter the N nodes:\n");scanf("%d",&n);
			 lastrever(n);
			break;
	case 4: printf("enter the N nodes:\n");scanf("%d",&n);
			recur(first,n);
			break;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


