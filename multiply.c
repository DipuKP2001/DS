#include <stdio.h>
#include <stdlib.h>
struct node{
	int coeff,exp;
	struct node *link;
};
struct node* insert(){
	printf("Enter the maximum degree:\n");
	int n,coef;
	scanf("%d",&n);
	struct node *head=NULL;
	printf("Enter the polynomial:\n");
	while(n>=0){
		printf("Enter the coefficient of x^%d:\t",n);
		scanf("%d",&coef);
		if(coef){
			struct node *newnode=(struct node*)malloc(sizeof(struct node));
			newnode->coeff=coef;
			newnode->exp=n;
			newnode->link=NULL;
			if(head==NULL){
				head=newnode;
			}
			else{
				struct node *temp=head;
				while(temp->link!=NULL){
					temp=temp->link;
				}
				temp->link=newnode;
			}
		}
		n--;
	}
	return head;
}
void display(struct node *head){
	struct node *temp=head;
	while(temp->link){
		printf("%dx^%d+",temp->coeff,temp->exp);
		temp=temp->link;
	}
	printf("%dx^%d\n",temp->coeff,temp->exp);
}
void multi(struct node *phead,struct node *qhead){
	struct node *pptr,*qptr,*rhead=NULL,*rptr;
	pptr=phead;
	qptr=qhead;
	while(pptr){
		qptr=qhead;
		while(qptr){
			struct node *newnode=(struct node*)malloc(sizeof(struct node));
			newnode->coeff=pptr->coeff*qptr->coeff;
			newnode->exp=pptr->exp+qptr->exp;
			newnode->link=NULL;
			if(rhead){
				rhead=newnode;
			}
			else if(newnode->exp>rhead->exp){
				newnode->link=rhead;
				rhead=newnode;
			}
			else if(newnode->exp==rhead->exp){
				rhead->coeff=rhead->coeff+newnode->coeff;
			}
			else if((newnode->exp)>(rptr->exp)){
				rptr->link=newnode;
				newnode->link=NULL;
			}
			else{
				struct node *temp=rhead->link;
				while(rptr){
					if(rptr->exp=newnode->exp){
						rptr->coeff=rptr->coeff+newnode->coeff;
					}
					else if((rptr->exp)>(newnode->exp)){
						temp=rptr;
						rptr=newnode;
						newnode->link=temp;
					}
					else{
						rptr=rptr->link;
					}
				}
			}

		}
	}
}
void main(){
	struct node *phead=NULL,*qhead=NULL;
	phead=insert();
	qhead=insert();
	printf("Polynomial1:\n");
	display(phead);
	printf("Polynomial2:\n");
	display(qhead);
	multi(phead,qhead);
}
