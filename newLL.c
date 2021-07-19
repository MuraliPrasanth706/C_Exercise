#include<stdio.h>
#include<stdlib.h>
void create();
void display();
int length();
void addbegin();
void Delete();

struct node{
int data;
struct node *link;
};
struct node *root=NULL;
int len;
void main(){
int ch;
while(1){
    printf("\n\n___________________SLL_____________________________\n");
    printf("1.Create \n");
    printf("2.Display \n");
    printf("3.length \n");
    printf("4.Addbegin\n");
    printf("5.Delete");
    printf("\n6.Exit\n");
    printf("\n--------------------------------------\n");
    printf("\nEnter your choice:");
    scanf("%d",&ch);
     switch(ch){
     case 1: create();
     break;
     case 2: display();
     break;
     case 3: len=length();
     printf("LENGTH:%d\n\n",len);
     break;
     case 4: addbegin();
     break;
     case 5: Delete();
     break;
     case 6: exit(0);
     break;
     default:
        printf("\nInvalid choice\n");
               break;
     }

}
}
void create()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->data);
        temp->link=NULL;
        if(root==NULL)
        {
                root=temp;
        }
        else
        {
            struct node*p;
                p=root;
                while(p->link!=NULL)
                {
                        p=p->link;
                }
                p->link=temp;
        }
}
void display()
{
    struct node *temp;
    temp=root;
    if(temp==NULL){
        printf("\nLIST ARE EMPTY");
    }else{
    while(temp!=NULL){
        printf("%d=>",temp->data);
        temp=temp->link;
    }
    }

}

int length(){
    int count=0;
    struct node *temp;
    temp=root;
    while(temp!=NULL){
            count++;
    temp=temp->link;

    }
    return count;
}
void addbegin(){

    struct node *temp,*p;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data:");
    scanf("%d",&temp->data);
    temp->link=NULL;
    if(root!=NULL)
    {
        p=root;
    }
    temp->link=p;
    root=temp;

}
void Delete(){
 struct node *temp;
 int loc;
 printf("Enter location:");
 scanf("%d",&loc);
 if(loc>length)
 {
     printf("\nLoction is greater than Length");
 }else if(loc == 1)
 {
     temp=root;
     root=temp->link;
     temp->link=NULL;
     free(temp);
}
else
{
    struct node *p=root,*q=root;
    while(loc>1)
    {
        p=q;
        q=q->link;
        loc--;
    }
    p->link=q->link;
     q->link=NULL;
    free(q);
}

}
