#include<stdio.h>
void failure(char text[100],int n,char pat[100],int m)
{
	int i=1,j=0,a;
	int f[m];
	f[0]=0;
	while(i<m)
	{
		if(pat[j]==pat[i])
		{
			f[i]=j+1;
			i++;
			j++;
		}
		else if(j>0)
		{
			j=f[j-1];
		}
		else
		{
			f[i]=0;
			i++;
		}
	}
	printf("***********************************************\n");
	printf("Failure Function\n");
	for(i=0;i<m;i++)
	{
		printf("F[%d]=%d\n",i,f[i]);
	}
	printf("***********************************************\n");
	printf("\n");
	int val = kmp(text,n,pat,m,f);
	printf("***********************************************\n");
	if(val==-1)
	{
		printf("The pattern doens't exist in the given text :(\n");
	}
	else
	{
		printf("The pattern exists in the given text :)\nIt is from position %d to %d in the text\n",val,val+(m-1));
		printf("Pattern from text\n");
		for(i=val;i<=val+(m-1);i++)
		{
			printf("%c\t",text[i]);
		}
	}
	printf("\n***********************************************\n");
}

int kmp(char text[100],int n,char pat[100],int m,int f[])
{
	int i=0,j=0;
	while(i<n)
	{
		if(text[i]==pat[j])
		{
			if(j==m-1)
			{
				return i-j;
			}
			else
			{
				i++;
				j++;
			}
		}
		else
		{
			if(j>0)
			{
				j=f[j-1];
			}
			else
			{
				i++;
			}
		}
	}
	return -1;
}

void main()
{
	int i,n,m;
	printf("Enter the length of text\n");
	scanf("%d",&n);
	printf("Enter the length of pattern\n");
	scanf("%d",&m);
	if(m<n)
	{
		char text[n];
		char pattern[m];
		printf("Enter the Text\n");
		for(i=0;i<n;i++)
		{
			text[i]=getchar();
			scanf("%c",&text[i]);
		}
		printf("Enter the pattern\n");
		for(i=0;i<m;i++)
		{
			pattern[i]=getchar();
			scanf("%c",&pattern[i]);
		}
		printf("********************************************************************************\n");
		printf("Text\n");
		for(i=0;i<n;i++)
		{
			printf("%c\t",text[i]);
		}
		printf("\n");
		printf("Pattern\n");
		for(i=0;i<m;i++)
		{
			printf("%c\t",pattern[i]);
		}
		printf("\n");
		printf("********************************************************************************\n");
		failure(text,n,pattern,m);
	}
	else
	{
		printf("The PATTERN length must not be greater than or equal to the length of the TEXT!!!!!!!!!!\n");
	}
}
/*OUTPUT
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ gcc kmp.c
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ ./a.out
Enter the length of text
7
Enter the length of pattern
11
The PATTERN length must not be greater than or equal to the length of the TEXT!!!!!!!!!!
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ 


pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ gcc kmp.c
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ ./a.out
Enter the length of text
5
Enter the length of pattern
3
Enter the Text
a
a
b
b
c
Enter the pattern
a
b
c
********************************************************************************
Text
a	a	b	b	c	
Pattern
a	b	c	
********************************************************************************
***********************************************
Failure Function
F[0]=0
F[1]=0
F[2]=0
***********************************************

***********************************************
The pattern doens't exist in the given text :(

***********************************************
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ 



pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ gcc kmp.c
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ ./a.out
Enter the length of text
11
Enter the length of pattern
6
Enter the Text
a
a
a
b
a
a
b
a
a
a
b
Enter the pattern
a
a
b
a
a
a
********************************************************************************
Text
a	a	a	b	a	a	b	a	a	a	b
Pattern
a	a	b	a	a	a	
********************************************************************************
***********************************************
Failure Function
F[0]=0
F[1]=1
F[2]=0
F[3]=1
F[4]=2
F[5]=2
***********************************************

***********************************************
The pattern exists in the given text :)
It is from position 4 to 9 in the text
Pattern from text
a	a	b	a	a	a	
***********************************************
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ 


pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ gcc kmp.c
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ ./a.out
Enter the length of text
6
Enter the length of pattern
3
Enter the Text
q
w
e
r
t
y
Enter the pattern
e
r
t
********************************************************************************
Text
q	w	e	r	t	y	
Pattern
e	r	t	
********************************************************************************
***********************************************
Failure Function
F[0]=0
F[1]=0
F[2]=0
***********************************************

***********************************************
The pattern exists in the given text :)
It is from position 2 to 4 in the text
Pattern from text
e	r	t	
***********************************************
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ 
*/
