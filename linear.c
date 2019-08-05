#include <stdio.h>
void linear(int arr[],int,int);
void linear(int arr[],int n,int key){
	int flag=0,i=0;
	for(i=0;i<n;i++){
		if(arr[i]==key){
			flag=1;
			break;
		}	
	}
	if(flag==1){
		printf("Element %d is found at %d position\n",key,i+1);
	}
	else{
		printf("Element not found\n");
	}
}
void sort(int arr[],int n);
void sort(int arr[],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}
	}
}
void sortdesc(int arr[],int n);
void sortdesc(int arr[],int n){
        int i,j;
        for(i=0;i<n;i++){
                for(j=0;j<n-i-1;j++){
                        if(arr[j]<arr[j+1]){
                                int temp=arr[j+1];
                                arr[j+1]=arr[j];
                                arr[j]=temp;
                        }
                }
        }
}
void binary(int arr[],int n,int key,int lower,int upper);
void binary(int arr[],int n,int key,int lower,int upper){
	static int mid;
	mid=(lower+upper)/2;
	if(arr[mid]==key){
		printf("Element:%d is found at %d position\n",key,mid+1);
		return;
	}
	else if(arr[mid]>key){
		return binary(arr,n,key,lower,mid-1);
	}
	else{
		return binary(arr,n,key,mid+1,upper);
	}
	printf("Element not present:\n");
}
void binaryloop(int arr[],int key,int n){
	int l=0,u=n,mid;
        while(l<u){
       	 mid=(l+u)/2;
       	 if(arr[mid]==key){
        		  printf("Element:%d found at %d",key,mid+1);
                 	 break;
         }
         else if(arr[mid]>key){
             		 u=mid-1;
         }
         else{
        		     l=mid+1;
	 }
	}
}
void main(){
	int n,key,choice;
	printf("Enter the no of elements in the array:\n");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the elements in the array:\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched:\n");
	scanf("%d",&key);
	printf("LINEAR SEARCH:\n");
	linear(arr,n,key);
	int ch;
	printf("BINARY SEARCH:\n");
	printf("Enter your choice\t1.Ascending\t2.Descending:\n");
	scanf("%d",&ch);
	if(ch==1){
		printf("SORTED ARRAY(IN ASCENDING) IS :\n");
		sort(arr,n);
		for(int p=0;p<n;p++){
			printf("%d \n",arr[p]);
		}
	}
	else{
		printf("SORTED ARRAY IN DESCENDING:\n");
		sortdesc(arr,n);
		for(int p=0;p<n;p++){
                        printf("%d \n",arr[p]);
		}
	}
	int c;
	printf("Enter your choice:\t1.Loop\t2.Recursion:\n");
	scanf("%d",&c);
	if(c==2){
		static int lower=0,upper;
		upper=n;
		binary(arr,n,key,lower,upper);
	}
	else{
		binaryloop(arr,key,n);
	}
}
