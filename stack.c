#include <stdio.h>
#include <stdlib.h>
int arr[100],top=-1,count;
void push(int element){
	count++;
	if(count>100){
		printf("Stack Overflow:\n");
		exit(0);
	}
	arr[++top]=element;
	printf("Inserted element is:%d\n",element);
}
int pop(){
	if(top==-1){
		printf("List is empty!!!\n");
		exit(0);
	}
	count --;
	return arr[top--];
}
void display(){
	if(top==-1){
		printf("List is empty!!!\n");
		return;
	}
	int max=top;
	printf("Elements in the stack are:\n");
	while(max!=-1){
		printf("%d\t",arr[max]);
		max--;
	}
	printf("\n");
}
void main(){
	int num,x,del;
	while(1){
		int ch;
		printf("Enter your choice:\n");
		printf("1.Push\n2.Pop\n3.Display\n4.Exit\n\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the number of elements to be inserted in the stack\n");
			       	scanf("%d",&num);
				while(num){
				       printf("Enter the element to be inserted:\n");
				       scanf("%d",&x);
				       push(x);
				       num--;
			       }
			       break;
			case 2:
			       del=pop();
			       printf("Deleted element is:%d\n",del);
			       break;
			case 3:
			       display();
			       break;
			case 4:
			       printf("!!!!!!!!!!!!!!!!!You have choosed to exit!!!!\n");
			       exit(0);
			default:
			       printf("Exiting...\n");
			       return;

		}
	}
}
