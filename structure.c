#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/* using linked lists to read and display the employee details*/
struct node
{
	char empname[50];
    long long int empno;
	int age;
	long long int salary;
	struct node *next;
};

typedef struct node nd;

nd *insert(nd *);
nd *delet(nd *);
nd *display(nd *);

int main()
{
	int choice;
	nd *head = NULL;
	int l;
	while(1)
	{
		printf("enter 1 to give employee details\n");
    	printf("enter 2 to remove a employ detail\n");
	    printf("enter 3 to display all employee details\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				head = insert(head);
				break;
			case 2:
				head = delet(head);
				break;
			case 3:
				head = display(head);
				break;
			default:
				exit(1);
		}
		printf("\n\n");
	}
	return 0;
}

nd *insert(nd *head) /* function to insert a new employ details */
{
	int age;
	long long int empno;
	long long int salary;
	char empname[50];
	int i;
	printf("enter employee name\n"); /* giving employ name as input*/
	scanf("%s",empname);
	printf("enter employee phone number\n");/* giving employ phn no. as input */
	scanf("%lld",&empno);
	printf("enter employee age\n");/* giving employ age as input*/
	scanf("%d",&age);
	printf("enter employee salary\n"); /* giving employ salary number as input*/
	scanf("%lld",&salary);
	nd *newnode;
	newnode = (nd *)malloc(sizeof(nd));
	for(i = 0;i < strlen(empname);i++)
	{
		newnode->empname[i] = empname[i];
	}
	newnode->empno = empno;
	newnode->salary = salary;
	newnode->age = age;
	nd *temp;
	if(head == NULL) /* if linked list is empty then insertion technique*/
	{
		head = newnode;
		newnode->next = NULL;
	}
	else/* if linked list contains some nodes then insertion technique */
	{
	   temp = head;
	   while(temp->next != NULL)
	   {
	   	   temp = temp->next;
	   }
	   temp->next = newnode;
	   newnode->next = NULL;	
	}
	return head;
}

nd *delet(nd *head) /* function to delete an existing employ details*/
{
	int pos,length=0,i;
	printf("enter employ's S.No to delete that employ's details\n ");
	scanf("%d",&pos); /* here pos indicates the employ serial number*/
	nd *temp=head,*t1;
	while(temp != NULL) /* determining the length of linked list */
	{
		length++;
		temp = temp->next;
	}
	if(pos == 1) /* deletion of first employ details */
	{
		if(head == NULL)
		{
			printf("no need to delete anything\n");
			return NULL;
		}
		else if(head->next == NULL)
		{
			free(head);
			return NULL;
		}
		else
		{
			temp = head;
			head = head->next;
			free(temp);
			return head;
		}
	}
	else if(pos == length) /* deletion of last employ details */
	{
		if(head == NULL)
		{
			printf("no need to delete anything\n");
			return NULL;
		}
		else if(head->next == NULL)
		{
			free(head);
			return NULL;
		}
		else
		{
			temp = head;
		    while(temp->next->next != NULL)
		    {
			    temp = temp->next;
		    }
		    t1 = temp->next;
		    temp->next = NULL;
		    free(t1);
		    return head;
		}
	}
	else if(pos > 1 && pos < length)
	{
		i = 1;
		temp = head;
		while(i < pos-1)
		{
			temp = temp->next;
			i++;
		}
		t1 = temp->next;
		temp->next = t1->next;
		free(t1);
		return head;
	}
	else
	{
		printf("this employ's S.No is not exist\n");
		return head;
	}
}

nd *display(nd *head) /* function to display the existing employee details in the linked lists */
{
	printf("S.No\tName  \tAge\tPhone Number\tSalary\n");
	nd *temp = head;
	int i,j;
	j = 0;
	while(temp != NULL)
	{
		i = 0;
		j++;
		printf("%d\t",j);
		while(temp->empname[i] != '\0')
		{
			printf("%c",temp->empname[i]);
			i++;
		}
		printf(" \t");
		printf("%d\t",temp->age);
		printf("%lld\t",temp->empno);
		printf("%lld",temp->salary);
		printf("\n");
		temp = temp->next;
	}
	return head;
}
