# include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};

typedef struct list node;
node *first=NULL;


void create(int n)
{
node *temp,*prev=first;
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



void insert_after_nth( int len, int data) 
{ int i=0;
    if (first == NULL) 
        return; 
  node* temp = (node *)malloc(sizeof(node *));
	temp->data=data;
    node* s_ptr = first; 
    node* f_ptr = first; 
  for (; i <=len- 1; i++) 
        f_ptr = f_ptr->next; 
  
    while (f_ptr->next!= NULL) 
	{ 
  	s_ptr = s_ptr->next; 
        f_ptr = f_ptr->next; 
    } 
    temp->next = s_ptr->next; 
    s_ptr->next = temp; 
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
 int ch=0,n,data;
 first=NULL;
 printf("\n Linked List creation \n");
 while(1)
{printf("...\n");
  
	scanf("%d",&ch);
    switch(ch)  
	{
           case 1: 
			printf("enter the length\n");scanf("%d",&n);create(n);
       		   //print(first);
		   break;
           case 2: print(first);
       	           break;
           case 3:   printf("enter the data and nth node from end");
			scanf("%d",&data);
			scanf("%d",&n);
			insert_after_nth(n,data);break;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


