#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
 int data;
 struct node *next;
 struct node *pre;
};

 struct queue
 {
 struct node *front1;
 struct node *rear;
 };

struct queue *q;
 void create_queue( struct queue *q)
{
    q->front1=NULL;
    q->rear=NULL;
}

struct queue *enqueue_front1(struct queue *q,int d)
{
struct node *newq;
newq=(struct node *)malloc(sizeof(struct node));
newq->data=d;
newq->pre=NULL;
if (newq==NULL)
    return 0;
printf("sjdhkjsdjsd");
if (q->front1==NULL&&q->rear==NULL)
{


    newq->next=NULL;
    q->front1=newq;
   q->rear=newq;
}
else
{


    q->front1->pre=newq;
    newq->next=q->front1;
    q->front1=newq;
}
printf("Enqueue successful");
return q;
}
struct queue *enqueue_rear(struct queue *q,int d)
{
struct node *newq;
newq=(struct node *)malloc(sizeof(struct node));
newq->data=d;
newq->next=NULL;
if (q->front1==NULL&&q->rear==NULL)
{


    newq->pre=NULL;
    q->front1=newq;
    //q->rear=newq;
}
else
{


    q->rear->next=newq;
    newq->pre=q->rear;
    q->rear=newq;
}
printf("Enqueue successful");

return q;
}


struct queue *dequeue_front1(struct queue *q)
{
struct node *temp;

if (q->front1==NULL&&q->rear==NULL)
    printf("underflow");
 else
 {
temp=q->front1;
q->front1=temp->next;
if(temp->next!=NULL)
        {
            temp->next->pre=NULL;
        }
if (q->front1==NULL)
        {
            q->rear=NULL;
        }
free(temp);

 }
printf("dequeue successful");
return q;
}



struct queue *dequeue_rear(struct queue*q)
{
 struct node *temp;

if (q->front1==NULL&&q->rear==NULL)
    printf("underflow");
 else
 {
temp=q->rear;
q->rear=temp->pre;
if(temp->pre!=NULL)
        {
            temp->pre->next=NULL;
        }
if (q->rear==NULL)
        {
            q->front1=NULL;
        }
free(temp);

 }
printf("dequeue successful");
return q;
}
int peek_front1(struct queue*q)
{
if (q->front1==NULL&&q->rear==NULL)
    printf("underflow");
    else
    return (q->front1->data);
}

 int peek_rear(struct queue*q)
{
if (q->front1==NULL&&q->rear==NULL)
    printf("underflow");
    else
    return (q->rear->data);
}
struct queue *display(struct queue*q)
{
 struct node *ptr;
if (q->front1==NULL&&q->rear==NULL)
    printf("underflow");
    else
        ptr=q->front1;
    while(ptr!=NULL)
    {
        printf("\t %d",ptr->data);
        ptr=ptr->next;
    }
return q;
}



int main()
{

int op,d,p;
printf("hellomain");
create_queue(q);

do{
        printf("enter the choice");
        printf("\n1.enqueue front\n2.enqueue rear\n3.dequeue front\n4.dequeue rear\n5.peek front\n6.peek rear\n7display\n8.exit");
        scanf("%d",&op);
switch(op)
{
case 1:
printf("Enter the number to be enqueued front");
scanf("%d",&d);
q= enqueue_front1(q,d);
break;

case 2:
printf("Enter the number to be enqueued rear");
scanf("%d",&d);
q= enqueue_rear(q,d);
break;

case 3:
q=dequeue_front1(q);
break;

case 4:
q=dequeue_rear(q);
break;

case 5:
 p=peek_front1(q);
printf("The value is %d",p);
break;

case 6:
 p=peek_rear(q);
printf("The value is %d",p);
break;

    case 7:
    display(q);
    break;

    case 8:
    break;
}


}while(op!=8);

return 0;

}
