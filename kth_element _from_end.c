//printing nth element from the end 
//linked list
# include <stdio.h>
# include <stdlib.h>
struct list
{
 int data;
 struct list *next;
};
typedef struct list node;
node *first,*prev,*temp,*curr;

//1.method
int kth(int n)  
{
node *a=first;
node *b=first;
int k=n;
while(k-->0)//traversing nth nodes from end so len =10  n=3 remaining 7 left from starting
	a=a->next;

while(a!=NULL)//traverse to remain 7  so b also moves 7 , 3rd from the end means 10-3=7th node becms 3from the end
{
a=a->next;
b=b->next;
}return b->data;
//printf("%d\n",b->data);
}

void create(void)
{
int n;
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
           prev=temp;
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


insertafterthenumber()
{
int data;
temp=(node *)(malloc(sizeof(node)));
printf("\n enter the data :");

  scanf("%d",&temp->data);
   
    printf("\n enter the number insert after the number \n");
     scanf("%d",&data);
	curr=first;   
	while(curr->data!=data)
	    { 
		curr=curr->next;
			if(curr==NULL)
                         {
			   printf("data =%dis not available ",data );
		          	 	return insertbeforethenumber(first);
         	         }
	     }
	        
	  if(curr->data==data)
         	{
			temp->next=curr->next;
			curr->next=temp;		
		}


}




insertbeforethenumber(node *curr)
{

int data;
temp=(node *)(malloc(sizeof(node)));
printf("\n enter the data :");

  scanf("%d",&temp->data);
   temp->next=NULL;
	 printf("\n enter the number insert before the number \n");
     scanf("%d",&data);
	//curr=first;   
	prev=first;	
	

   if(first->data==data)//to insert before the 1st node
    {	
	temp->next=first;
	first=temp;
    }
 else
     {	
	while(curr->data!=data)
	    {
		prev=curr;
		curr=curr->next;
	               if(curr==NULL)
                         {
			   printf("data =%dis not available ",data );
		          	 	return insertbeforethenumber(first);
         	         }
			
	     }

                     if(curr->data==data)
         	       {
                        	temp->next=curr;
			        prev->next=temp;
			}
      }		


}

void delete(node *temp )
 {
   int data;
   printf("enter the number which u want delet\n");
   scanf("%d",&data);
   if(temp->data==data)
    {
     temp=temp->next;
	first=temp;  
    }

    else
      {
        prev=temp;
        curr=temp->next;
          
		while(curr->data!=data)
                 {  
	           prev=prev->next;
	           curr=curr->next;
			if(curr==NULL)
                         {
			   printf("data =%dis not available ",data );
		          	 	return delete(first);
         	         }
			
                 } 

              if(curr->data==data)
                      prev->next=curr->next;                 
      }
}
void update()
{   
 int num,data;
	print(first);
     printf("which data u want modify,by which num\n data=");
     scanf("%d",&data); printf("\nnum=");
     scanf("%d",&num);
     temp=first;
     while(temp->data!=data)
	{
	    temp=temp->next;
		if(temp==NULL)
                   {
			printf("data =%dis not available ",data );
         		 update();
         	   }
        }
   temp->data=num;
}

int re_print(node *temp)
{
 if(temp==NULL)
	printf("\nempty\n");
else
	
{
	
     re_print(temp->next);
	
     printf("%d-->",temp->data);
	//printf("%d> >",temp->next);
}

}

void main()
{
 int ch=0,n1;
 first=NULL;
 printf("\n Linked List creation \n");
 while(1)
{
  printf("choose the option \n1.create\n2.print\n3.insertafterthenumber\n 4.insertbeorethenummber\n5.delete\n");
  printf("6.re_print\n7.update\n8.kth element\n");  
	scanf("%d",&ch);
    switch(ch)  
	{
           case 1: create();
       		   print(first);
		   break;
           case 2: print(first);
       	           break;
			//exit(1);
           case 3: insertafterthenumber();
	           print(first);
	           break;
	   case 4: insertbeforethenumber(first);
	           print(first);
                   break;
	   case 5: print(first);
		   delete(first);
		   print(first);
			break;
	   case 6: re_print(first);
                   break;
	   case 7: update();
		   print(first);
		   break;	
	   case 8: printf("enter the element\t");scanf("%d",&n1); 
			printf("%d\n",kth(n1,first));
		    break;
	   case 0: exit(1);
	}
}

}


