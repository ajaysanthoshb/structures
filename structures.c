#include<stdio.h>
#include<string.h>
struct employee
{
	long long int empno;
	long long int salary;
	int age;
	char empname[50];
};

typedef struct employee employ;

void display(employ s[20],int n)
{
	int i;
	printf("Name  \tage  \tPhone Number  \tSalary\n");
	for(i = 0;i < n;i++)
	{
		printf("%s",s[i].empname);
		printf("  \t");
		printf("%d  \t",s[i].age);
		printf("%lld  \t",s[i].empno);
		printf("%lld  \t",s[i].salary);
		printf("\n");
	}
}

int main()
{
	employ s[20];
	int n;
	printf("enter no. of employees\n");
	scanf("%d",&n);
	int i,j;
	for(i = 0;i < n;i++)
	{
		printf("enter employ%d name\n",i+1);
		scanf("%s",&s[i].empname);
		printf("enter employ%d age\n",i+1);
		scanf("%d",&s[i].age);
		printf("enter employ%d salary\n",i+1);
		scanf("%lld",&s[i].salary);
		printf("enter employ%d phone number\n",i+1);
		scanf("%lld",&s[i].empno);
	}
	display(s,n);
	return 0;
}
