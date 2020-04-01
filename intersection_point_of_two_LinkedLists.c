# include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};

typedef struct list node;
node *first=NULL,*sec=NULL;
/*

void create(node **head_ref)
{
int n;node *temp,*prev=*head_ref;
	printf("how many node u want create :");
	scanf("%d",&n);
while(n--)
{	
    temp=(node *)(malloc(sizeof(node)));
     printf("\n Enter the numbers ");
     scanf("%d",&temp->data);
      if(*head_ref==NULL) //here we are checking our node is first or not 
        {
          *head_ref=temp;
           prev=*head_ref;
        }
        else
          {	
            prev->next=temp;
            prev=temp;	      
	     
          }
    
   }
}*/
int length(node *slow_ptr)
{int count=0;
	while(slow_ptr!=NULL)
	 {
		count++;
		slow_ptr=slow_ptr->next;}

return count;

}


int findLoop(node *temp1,node *temp2)
{
int l1=length(temp1);
int l2=length(temp2);
int i=0,diff=(l2>l1?(l2-l1):(l1-l2));
for(i=1;i<=diff;i++)
{
if(l1>l2)
	temp1=temp1->next;
else
	temp2=temp2->next;
}
while (temp1 != NULL && temp2 != NULL) { 
        if (temp1 == temp2) 
            return temp1->data; 
        temp1 = temp1->next; 
        temp2 = temp2->next; 
    } 

return -1;
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





int main() 
{ 
  
    node* newNode; 
    node* head1 = (node*)malloc(sizeof(node)); 
    head1->data = 10; 
  
    node* head2 = (node*)malloc(sizeof(node)); 
    head2->data = 3; 
  
    newNode = (node*)malloc(sizeof(node)); 
    newNode->data = 6; 
    head2->next = newNode; 
  
    newNode = (node*)malloc(sizeof(node)); 
    newNode->data = 9; 
    head2->next->next = newNode; 
  
    newNode = (node*)malloc(sizeof(node)); 
    newNode->data = 15; 
    head1->next = newNode; 
    head2->next->next->next = newNode; 
  
    newNode = (node*)malloc(sizeof(node)); 
    newNode->data = 30; 
    head1->next->next = newNode; 
  
    head1->next->next->next = NULL; 
  
          printf("%d",findLoop(head1, head2)); 
  
     
} 


