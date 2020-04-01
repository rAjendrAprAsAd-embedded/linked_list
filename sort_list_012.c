 # include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};

typedef struct list node;
node *first=NULL;
void sort() 
{ 
    int i=0,count[3] = {0, 0, 0};  // Initialize count of '0', '1' and '2' 
    node *ptr = first; 
  
    
    while(ptr != NULL) 
    {   count[ptr->data] += 1; 
        ptr = ptr->next; 
    } 
    ptr = first; 

    while (ptr != NULL) 
    { 
        if (count[i] == 0) 
            ++i; 
        else
        { 
            ptr->data = i; 
            --count[i]; 
            ptr = ptr->next; 
        } 
    } 
} 
  
void delete(int M, int N) 
{ 
   node *curr = first;
	node *temp=NULL; 

    int count; 
  
    while (curr!=NULL) 
    { 
        
        for (count = 1; count<M && curr!= NULL; count++) 
            curr = curr->next; 
  
       if (curr == NULL) 
            return; 
  
      
        temp = curr->next; 
        for (count = 1; count<=N && temp!=NULL; count++) 
        { 
            node *temp2=temp; 
            temp=temp->next; 
            free(temp2); 
        } 
        curr->next = temp;
        curr = temp; 
    } 
} 
 

void create()
{
int n;node *temp,*prev=first;
	printf("how many node u want create :");
	scanf("%d",&n);
while(--n)
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
 int ch=0,m,n;
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
           case 3:sort();
				print(first);
			break;;
	  case 9: exit(0);
		default :printf("wrong option\n");
	}
}

}


