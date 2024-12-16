#include<stdio.h>
#include<stdlib.h>
void insertatbegin();
void insertatend();
void insertatpos();
void display();
void displayreverse();
void deleteatbegin();
void deleteatend();
void deleteatpos();
int menu();

struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*start=NULL,*newnode=NULL,*temp=NULL,*temp1=NULL;

int main()
{
  int ch;
  while(1)
  {
      ch=menu();
      switch(ch)
      {
          case 1: insertatbegin();
                   break;
          case 2: display();break;
          case 3: exit(0);
          case 4: insertatend();break;
          case 5: insertatpos();break;
          case 6: deleteatbegin();break;
          case 7:deleteatend();break;
          case 8: deleteatpos();break;
          case 9: displayreverse();break;
          default : printf("enter valid choice");
      }
  }
}

int menu()
{
    int ch;
    printf("\n------------");
    printf("\n Doubly Linked List");
    printf("\n------------");
    printf("\n1.Insert at Begin\n2.Display\n3.Exit\n4.insert at end\n5.insertatpos\n");
    printf("6.deleteatbegin\n7.deleteatend\n8.deleteatpos");
    printf("\n\n-->Enter Your Choice:");
    scanf("%d",&ch);
    return ch;
}

void insertatbegin()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Data in the Node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        newnode->next=start;
        start->prev = newnode;
        start=newnode;
    }
}

void insertatend()
{
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Data in the Node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        temp=start;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
        newnode->prev=temp;
    }
}

void insertatpos()
{
   int pos,i;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the Data in the Node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    newnode->prev=NULL;
    printf("Enter the position : ");
    scanf("%d",&pos);
     if(start==NULL)
    {
       start=newnode;
    }
    else
    {
            temp = start;
             for(i=1;i<pos;i++)
             {
              temp = temp->next;
             }
            temp1=temp->prev;
            temp1->next=newnode;
            newnode->prev=temp1;
            newnode->next=temp;
            temp->prev=newnode;
        }
}

void deleteatbegin()
{
    if(start==NULL)
    {
        printf("list is empty deletion not possible");
    }
    else
    {
        temp=start;
        if(temp->prev==temp->next)
        {
            start=NULL;
            free(temp);
        }
        else
        {
            start=temp->next;
            start->prev=NULL;
            free(temp);
        }
    }
}

void deleteatend()
{
    if(start==NULL)
    {
        printf("list is empty deletion not possible");
    }
    else
    {
        temp=start;
        if(temp->prev==temp->next)
        {
            start=NULL;
            free(temp);
        }
        else
        {
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
           temp->prev->next=NULL;
           free(temp);
        }
    }
}

void deleteatpos()
{
    int pos,i,count;
    printf("\nEnter the Position of the element you would like to delete:");
    scanf("%d",&pos);
    temp=start;
    if(start==NULL)
    {
        printf("list is empty");
    }
    else
    {
        if(temp->prev==temp->next)
        {
            start=NULL;
            free(temp);
        }
        else
        {
         for(i=1,count=1;i<pos;i++)
         {
          temp=temp->next;
          count++;
         }
         if(count==pos)
         {
            deleteatend();
         }
         else
         {
             temp1=temp->prev;
             temp1->next=temp->next;
             temp->next->prev=temp1;
             free(temp);
         }
        }
    }
}

void display()
{
    temp=start;
    if(temp==NULL)
    {
        printf("empty list\n");
    }
    while(temp!=NULL)
    {
      printf("---->|%d|%d|%d|",temp->prev,temp->data,temp->next);
        temp=temp->next;
    }
}

void displayreverse()
{
    temp=start;
    if(temp==NULL)
    {
        printf("empty list\n");
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    while(temp!=NULL)
    {
        printf("\t%d",temp->data);
        temp=temp->prev;
    }
}
