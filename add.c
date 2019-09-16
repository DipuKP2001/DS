#include <stdio.h>
#include <stdlib.h>
struct node{
    int coeff,exp;
    struct node* link;
}*phead=NULL,*qhead=NULL,*rhead=NULL;
struct node* createNode(struct node *head,int coeff,int exp){
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    newnode->coeff=coeff;
    newnode->exp=exp;
    newnode->link=NULL;
    if(!head){
        head=newnode;
    }
    else{
        struct node *temp=head;
        while(temp->link){
            temp=temp->link;
        }
        temp->link=newnode;
    }
    return head;
}
struct node* poly(){
    struct node *head=NULL;
    int n,coeff;
    printf("Enter the degree of the equation:\n");
    scanf("%d",&n);
    while(n>=0){
        printf("Enter the coefficient of x^%d: ",n);
        scanf("%d",&coeff);
        if(coeff){
            head=createNode(head,coeff,n);
        }
        n--;
    }
    traversal(head);
    return head;
}
void traversal(struct node *head){
    struct node *temp=head;
    while(temp){
        printf("%dx^%d",temp->coeff,temp->exp);
        if(temp->link){
                printf("+");
        }
        temp=temp->link;
    }
    printf("\n");
}
struct node* add(struct node *phead,struct node *qhead){
    struct node *pptr=phead,*qptr=qhead,*head=NULL;
    while(pptr!=NULL && qptr!=NULL){
        if(pptr->exp==qptr->exp){
            head=createNode(head,pptr->coeff+qptr->coeff,pptr->exp);
            pptr=pptr->link;
            qptr=qptr->link;
        }
        else if(pptr->exp>qptr->exp){
            head=createNode(head,pptr->coeff,pptr->exp);
            pptr=pptr->link;
        }
        else{
            head=createNode(head,qptr->coeff,qptr->exp);
            qptr=qptr->link;
        }
    }
    while(pptr){
        head=createNode(head,pptr->coeff,pptr->exp);
        pptr=pptr->link;
    }
    while(qptr){
        head=createNode(head,qptr->coeff,qptr->exp);
        qptr=qptr->link;
    }
    return head;
}
void main(){
    printf("1st polynomial:\n");
    phead=poly();
    printf("2nd polynomial:\n");
    qhead=poly();
    rhead=add(phead,qhead);
    printf("\n<<<<<<<<<<ADDING>>>>>>>>>>\n");
    traversal(rhead);
}
