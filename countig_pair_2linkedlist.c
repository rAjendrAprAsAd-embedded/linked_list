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
 node *first=NULL,*second=NULL;


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


int countpairs(node* head1, node* head2, int x) 
{ 
    int count = 0; 
      
   node *p1, *p2; 
      
    for (p1 = head1; p1 != NULL; p1 = p1->next) 
      for (p2 = head2; p2 != NULL; p2 = p2->next) 
          if ((p1->data + p2->data) == x) 
                count++;             
    return count; 
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
           case 1:printf("first"); 
			create(&first);
       		   print(second);
				create(&second);
		
		   break;
           case 2: print(first);
       	           break;
           case 3:
			printf("sum value");
			scanf("%d",&data);
		
		printf("\n%d",countpairs(first,second,data));
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


