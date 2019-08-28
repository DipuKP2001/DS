#include <stdio.h>
#include<stdlib.h>
struct node
{
        int info;
        struct node *next;
};
struct node *start=NULL;
void insert_begin()
{
        struct node *temp;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info);
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                temp->next=start;
                start=temp;
        }
}
void insert_end()
{
        struct node *temp,*ptr;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->info );
        temp->next =NULL;
        if(start==NULL)
        {
                start=temp;
        }
        else
        {
                ptr=start;
                while(ptr->next !=NULL)
                {
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}
void insert_pos()
{
        struct node *ptr,*temp;
        int i,pos;
        temp=(struct node *)malloc(sizeof(struct node));
        if(temp==NULL)
        {
                printf("\nOut of Memory Space:\n");
                return;
        }
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->info) ;

        temp->next=NULL;
        if(pos==0)
        {
                temp->next=start;
                start=temp;
        }
        else
        {
                for(i=0,ptr=start;i<pos-1;i++)
                {
                        ptr=ptr->next;
                        if(ptr==NULL)
                        {
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void delete_begin()
{
        struct node *ptr;
        if(ptr==NULL)
        {
                printf("\nList is Empty:\n");
                return;
        }
        else
        {
                ptr=start;
                start=start->next ;
                printf("\nThe deleted element is :%d\t",ptr->info);
                free(ptr);
        }
}
void delete_end()
{
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL)
        {
                ptr=start;
                start=NULL;
                printf("\nThe deleted element is:%d\t",ptr->info);
                free(ptr);
        }
        else
        {
                ptr=start;
                while(ptr->next!=NULL)
                {
                        temp=ptr;
                        ptr=ptr->next;
                }
                temp->next=NULL;
                printf("\nThe deleted element is:%d\t",ptr->info);
                free(ptr);
        }
}
void delete_pos()
{
        int i,pos;
        struct node *temp,*ptr;
        if(start==NULL)
        {
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else
        {
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                if(pos==0)
                {
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info  );
                        free(ptr);
                }
                else
                {
                        ptr=start;
                        for(i=0;i<pos;i++)
                        {
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL)
                                {
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->info );
                        free(ptr);
                }
        }
}
void search(){
   int key;
   printf("Enter the element to be searched:\n");
   scanf("%d",&key);
   int i=0;
   struct node *temp=start;
   while(temp!=NULL){
        if(temp->info==key){
            printf("%d found at position %d \n",key,i);
            return;
        }
        i++;
        temp=temp->next;
   }
   printf("%d not found\n",key);
}
void traversal()
{
        struct node *ptr;
        if(start==NULL)
        {
                printf("\nList is empty:\n");
                return;
        }
        else
        {
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr!=NULL)
                {
                        printf("%d-->",ptr->info );
                        ptr=ptr->next ;
                }
        }
        printf("\n");
}
int main()
{
        int ch;
        while(1){
                printf("---------------------------------------\n");
                printf("1.Insertion at beginning\t2.Insertion at end\t3.Insertion at specific position\t4.Deletion from beginning\t5.Deletion from end\t6.Deletion at specific position\t7.Search\t8.Traversal\t9.Exit");
                printf("\nEnter your choice:\n");
                scanf("%d",&ch);
                switch(ch)
                {
                        case 1:
                                        insert_begin();
                                        break;
                        case 2:
                                        insert_end();
                                        break;
                        case 3:
                                        insert_pos();
                                        break;
                        case 4:
                                        delete_begin();
                                        break;
                        case 5:
                                        delete_end();
                                        break;
                        case 6:
                                        delete_pos();
                                        break;
                        case 7:
                                        search();
                                        break;
                        case 8:
                                        traversal();
                                        break;

                        case 9:
                                        printf("\nExiting....\n");
                                        exit(0);
                        default:
                                        printf("\nInvalid choice!!!\n");
                                        return;
                }
        }
        return 0;
}
