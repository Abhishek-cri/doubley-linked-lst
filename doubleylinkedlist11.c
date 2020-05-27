#include<stdio.h>
#include<stdlib.h>
struct node
{
       int data;
       struct node *next;
       struct node *prev;
} *head=NULL;

void creation()
{
       int data,n;
       struct  node *temp,*ptr;
       printf("press -1 to exit\n");
       printf("enter data\n");
       scanf("%d",&data);
       while(data!=-1)
       {
              ptr=(struct node *)malloc(sizeof(struct node));
              ptr->data=data;
              ptr->next=NULL;
              ptr->prev=NULL;
              if(head==NULL)
              {
                     ptr->prev=NULL;
                     head=ptr;
              }
              else
              {
                     temp=head;
                     while(temp->next!=NULL)
                     {
                            temp=temp->next;
                     }
                     temp->next=ptr;
                     ptr->prev=temp;


              }
              printf("press -1 to exit\n");
              printf("enter data\n");
              scanf("%d",&data);
       }

}

void display()
{
       struct node *temp;
       temp=head;
       if(head==NULL)
       {
              printf("no data\n");
       }
       else
       {
              temp=head;
              while(temp!=NULL)
              {
                     printf("data->%d\n",temp->data);
                     temp=temp->next;
              }
       }
}

void insert_beg()
{
       struct node *temp,*new_node;
       int data;
       printf("enter data");
       scanf("%d",&data);
       new_node=(struct node *)malloc(sizeof(struct node));
       new_node->data=data;
       new_node->prev=NULL;
       new_node->next=head;
       head->prev=new_node;
       head=new_node;
       printf("first node is printed succesfully\n");
}
void insert_end()
{
       int data;
       struct node *temp,*ptr;
       printf("enter data");
       scanf("%d",&data);
       ptr=(struct node *)malloc(sizeof(struct node));
       ptr->data=data;
       ptr->next=NULL;
       temp=head;
       while(temp->next!=NULL)
       {
              temp=temp->next;
       }
       temp->next=ptr;
       ptr->prev=temp;
       printf("data is added successfully");

}
void insert_pos()
{
       int data,pos,i;
       struct node *temp,*pretemp,*ptr;
       printf("enter position to insert data");
       scanf("%d",&pos);
       printf("enter data");
       scanf("%d",&data);
       ptr=(struct node*)malloc(sizeof(struct node));
       ptr->data=data;
       temp=head;
       pretemp=temp;
       if(pos==1)
       {
              insert_beg();
       }
       else
  {
       temp=head;
       pretemp=temp;
       for(i=2;i<=pos;i++)
       {
              pretemp=temp;
              temp=temp->next;
       }
       ptr->prev=pretemp;
       ptr->next=temp;
       temp->prev=ptr;
       pretemp->next=ptr;
       printf("data is added successfully");
  }
}

void delete_beg()
{
       struct node *temp,*p;
       temp=head;
       if(head==NULL)
       {
              printf("UNDERFLOW");
       }
       else
{
       temp=head;
       head=head->next;
       head->prev=NULL;
       free(temp);
}
}

void delete_end()
{
       struct node *temp,*pretemp;
       if(head==NULL)
       {
              printf("UNDERFLOW");

       }
       else
       {
              temp=head;
              pretemp=temp;
              while(temp->next!=NULL)
              {
                     pretemp=temp;
                     temp=temp->next;
              }
              pretemp->next=NULL;
              free(temp);
       }
}

void delete_pos()
{
       struct node *temp,*pretemp;
       int val;
       printf("enter data you want to delete data");
       scanf("%d",&val);
       temp=head;
       pretemp=temp;
       if(head==NULL)
       {
              printf("UNDERFLOW");
       }
       else
       {
              while(pretemp->next!=NULL)
              {
                     if(pretemp->next->data==val)
                     {
                            temp=pretemp->next;
                            pretemp->next=temp->next;
                            temp->next->prev=pretemp;
                            free(temp);
                     }
                     pretemp=pretemp->next;
              }

       }

}

void invalid_choice()
{
       printf("invalid choice");
}


int main()
{
       int option;
       do
       {
              printf("MAIN MENU\n");
              printf("1.creation\n 2.display\n3.insertion at beg\n4.insert at end\n 5.insert at any position\n 6.delete beg\n7.delete at end\n 8.delete at any position \n9.other choice\n");
              printf("enter your option\n");
              scanf("%d",&option);
              switch(option)
              {
              case 1:
                     creation();
                     break;
              case 2:
                     display();
                     break;
              case 3:
                     insert_beg();
                     break;
              case 4:
                     insert_end();
                     break;

              case 5:
                     insert_pos();
                     break;
              case 6:
                     delete_beg();
                     break;
              case 7:
                     delete_end();
                     break;
              case 8:
                     delete_pos();
                     break;

              case 9:
                     invalid_choice();
                     break;
              }
       }while(option!=9);
       return 0;
}
