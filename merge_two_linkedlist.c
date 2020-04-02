# include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};

typedef struct list node;
node *first=NULL,*sec=NULL;


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
n=4;prev=NULL;
while(n--)
{	
    temp=(node *)(malloc(sizeof(node)));
     printf("\n Enter the numbers ");
     scanf("%d",&temp->data);
      if(sec==NULL) //here we are checking our node is first or not 
        {
          sec=temp;
           prev=sec;
        }
        else
          {	
            prev->next=temp;
            prev=temp;	      
	     
          }
    
   }

}
node* merg()
{
node *temp;
node *n3=NULL; 
node *n1=first;
node *n2=sec;
if(first==NULL)
	return n2;
if(sec=NULL)
	return n1;
	
	if(n1->data<=n2->data)
	{
	 n3=n1;
	 n1=n3->next;	
	}
	else
	{
	n3=n2;
	n2=n2->next;
	}
temp=n3;
while(n1!=NULL && n2!=NULL)
{
	if(n1->data<=n2->data)
	{	n3->next=n1;
		n3=n1;
		n1=n3->next;}
	else{
		n3->next=n2;
		n3=n2;
		n2=n3->next;
		}

}
if(n1==NULL)
	n3->next=n2;
if(n2==NULL)
	n3->next=n1;
return temp;

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
			printf("\n");
		   print(sec);
       	           break;
           case 3: first=merg();
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


