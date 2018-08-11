# repo
experiment area
Code
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void decode(char e_data[100],int n)
{
	int i;
	printf("\n\n************************Decoding*********************************\n");
	for(i=0;i<n;i++)
	{
		if(e_data[i]=='0' && e_data[i+1]=='1')
		{
			printf("1 ");
			i++;
		}
		else if(e_data[i]=='1' && e_data[i+1]=='0')
		{
			printf("0 ");
			i++;
		}
	}
	printf("\n\n****************************************************************\n");
}
void encode(char data[50],int n)
{
	int i,a=0,ch;
	char e_data[100];
	for(i=0;i<n;i++)
	{
		if(data[i]=='1')
		{
			e_data[a]='0';
			a++;
			e_data[a]='1';
			a++;
		}
		else
		{
			e_data[a]='1';
			a++;
			e_data[a]='0';
			a++;
		}
	}
	int m = strlen(e_data);
	printf("\n\n************************Encoding*********************************\n");
	printf("The encoded data is as follows:\n");
	for(i=0;i<a;i++)
	{
		if(e_data[i]=='1')
		{
			printf(" 1 ");
		}
		else
		{
			printf(" -1 ");
		}
	}
	printf("\n\n****************************************************************\n");
	printf("\n\n");
	printf("Press 1 to decode the same data else press 0\n");
	scanf("%d",&ch);
	if(ch==1)
	{
		decode(e_data,m);
	}
	else if(ch==0)
	{
		exit(0);
	}
	else
	{
		printf("Incorrect choice!!!!!!\n\n");
	}
	printf("\n");
}
void main()
{
	char data[50];
	printf("\n\n***********************Manchester********************************\n");
	printf("Enter the data to be encoded:\n");
	scanf("%s",data);
	int n = strlen(data);
	encode(data,n);
	printf("\n\n*****************************End*********************************\n");
}

/*OUTPUT
pooja@pooja-VirtualBox:~$ gcc manchester.c
pooja@pooja-VirtualBox:~$ ./a.out


***********************Manchester********************************
Enter the data to be encoded:
110011


************************Encoding*********************************
The encoded data is as follows:
 -1  1  -1  1  1  -1  1  -1  -1  1  -1  1 

****************************************************************


Press 1 to decode the same data else press 0
1


************************Decoding*********************************
1 1 0 0 1 1 

****************************************************************



*****************************End*********************************
pooja@pooja-VirtualBox:~$ 
*/
