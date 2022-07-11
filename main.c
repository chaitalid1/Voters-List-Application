#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct person{
    int age;
    char name[30];
    char gender;
    char city[20];
    struct person *next;
};

struct person *start=NULL;
void create();
void display();
void insert();
void search();
void sort();

int main()
{
    int choice;
    printf("\n Application for Voter List \n");
    do
    {
        printf("\n Menu ");
        printf("\n 1. Create voter list");
        printf("\n 2. Add new ");
        printf("\n 3. Display voter list");
        printf("\n 4. Search and check Eligibility");
        printf("\n 5. Exit\n");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1:
            {
                create();
                break;
            }
            case 2:
            {
                insert();
                break;
            }
            case 3:
            {
                display(start);
                break;
            }
            case 4:
            {
                search();
                break;
            }
            case 5:
            {
                printf("\n Exiting Program! \n");
                break;
            }
            default:
            {
                printf("\n Invalid choice! \n");
                break;
            }
        }
    }while(choice!=5);
    return 0;
}


void sort()
{
    struct person *current = start, *index = NULL; 
    struct person *temp; 
    temp=(struct person*)malloc(sizeof(struct person)); 
    if(start == NULL) { 
        return; 
    } 
    else { 
        while(current != NULL) { 
            index = current->next; 
            while(index != NULL) { 
                if(strcmp(current->name,index->name) > 0) { 
                    strcpy(temp->name,current->name); 
                    strcpy(current->name,index->name); 
                    strcpy(index->name,temp->name);
                    temp->gender = current->gender; 
                    current->gender = index->gender; 
                    index->gender = temp->gender; 
                    temp->age = current->age; 
                    current->age = index->age; 
                    index->age = temp->age; 
                    strcpy(temp->city,current->city); 
                    strcpy(current->city,index->city); 
                    strcpy(index->city,temp->city);
                } 
                index = index->next; 
            } 
            current = current->next; 
        } 
    } 
}


void create()
{
    struct person *temp;
    char gender1, name1[30], city1[20];
    int age1;
    temp=(struct person*)malloc(sizeof(struct person)); 
    if(temp==NULL)
    {
        printf("\n No space available!!\n");
    }
    else
    {
        printf("\n Enter the details of the person: ");
        printf("\n Enter name: ");
        fflush(stdin);
        gets(name1);
        printf(" Enter age: ");
        scanf("%d", &age1);
        fflush(stdin);
        printf(" Enter gender: ");
        scanf("%c",&gender1);
        fflush(stdin);
        printf(" Enter city: ");
        gets(city1);
        temp->age=age1;
        strcpy(temp->name,name1);
        temp->gender=gender1;
        strcpy(temp->city,city1);
        temp->next=NULL;
        start=temp;
    }
}


void search()
{
    struct person *ptr;
    ptr=(struct person*)malloc(sizeof(struct person));
    int flag; 
    char name1[30];
    ptr = start; 
    if(ptr == NULL) 
    { 
        printf("\nEmpty List\n"); 
    } 
    else 
    { 
        printf("\n Enter name: "); 
        fflush(stdin);
        gets(name1); 
        while (ptr!=NULL) 
        { 
            if(strcmp(ptr->name,name1)==0) 
            {
                printf("\n Details are: \n");
                printf(" Name: %s\n", ptr->name);
                printf(" Age: %d\n",ptr->age);
                printf(" Gender: %c\n", ptr->gender);
                printf(" City: %s\n", ptr->city);
                if((ptr->age) >= 18) 
                {
                    printf("\n %s is eligible to vote.\n", ptr->name);
                }
                else
                {
                    printf("\n %s is not eligible to vote.\n", ptr->name);
                }
                flag=0; 
            } 
            else 
            { 
                flag=1; 
            } 
            ptr = ptr -> next; 
        } 
        if(flag==1) 
        { 
            printf("Person not found!\n"); 
        }
    } 
}


void display(struct person *n)
{
    int i=1;
    printf("\n The Voter List \n");
    sort();
    printf("\n Name \t\t Gender \t Age \t\t City\n");
    while(n!=NULL)
    {
        printf(" %d. %s \t\t %c \t\t %d \t\t %s \n", i++, n->name, n->gender, n->age, n->city);
        n=n->next;
    }
}


void insert()
{
    printf("\n Add new voter \n");
    char gender1, name1[30], city1[20];
    int age1;
    struct person *temp,*ptr;
    ptr=(struct person*)malloc(sizeof(struct person)); 
    temp=(struct person*)malloc(sizeof(struct person));
    if(temp==NULL)
    {
        printf("\n Out of Memory Space \n");
    }
    else
    {
        printf("\n Enter the details of the person: ");
        printf("\n Enter name: ");
        fflush(stdin);
        gets(name1);
        printf(" Enter age: ");
        scanf("%d", &age1);
        fflush(stdin);
        printf(" Enter gender: ");
        scanf("%c",&gender1);
        fflush(stdin);
        printf(" Enter city: ");
        gets(city1);
        temp->age=age1;
        strcpy(temp->name,name1);
        temp->gender=gender1;
        strcpy(temp->city,city1);
        temp->next=NULL;
        if(start==NULL)
        {
            start=temp;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next = temp; 
            temp->next = NULL;
        }
    }
}


