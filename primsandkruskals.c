#include<stdio.h>
#define inf 999
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}

void final_check(int edge[],int u[],int v[],int n,int visited[],int cost)
{
	int i,min,a,b,c=0,t,r;
	min = edge[0];
	for(r=0;r<n;r++)
	{
		for(i=0;i<n;i++)
		{
			if(edge[i]<min)
			{
				min=edge[i];
				a=u[i];
				b=v[i];
				t=i;
			}
		}
		if((visited[a]==0 && visited[b]==0) || (visited[a]==0 && visited[b]==1) || (visited[a]==1 && visited[b]==0))
		{
			printf("Edge: %d--->%d\tCost: %d\n",a,b,min);
			edge[t]=inf;
			visited[a]=visited[b]=1;
			cost = cost + min;
		}
		else
		{
			edge[t]=inf;
		}
	}
	printf("Minimum Spanning Tree Cost is %d\n",cost);
}

void prims(int arr[10][10],int n,int sn)
{
	int cost=0,c=0,v1[20],v2[20],edge[20],i,j,visited[10];
	printf("\n\n~~~~~~~~~~~~~~~~~~~~Prim's Algorithm~~~~~~~~~~~~~~~~~~~~\n");
	for(i=0;i<n;i++)
	{
		visited[i]=0;
		for(j=0;j<n;j++)
		{
			if(arr[i][j]==0)
			{
				arr[i][j]=inf;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(arr[i][j]!=inf)
			{
				v1[c]=i;
				v2[c]=j;
				edge[c]=arr[i][j];
				c++;
			}
		}			
		int x,min=edge[0],u=v1[0],v=v2[0],t=0;
		for(x=0;x<c;x++)
		{
			if(edge[x]<min)
			{
				min=edge[x];
				u=v1[x];
				v=v2[x];
				t=x;
			}
		}
		if((visited[u]==0 && visited[v]==0) || (visited[u]==0 && visited[v]==1) || (visited[u]==1 && visited[v]==0))
		{
			printf("Edge: %d--->%d\tCost: %d\n",u,v,min);
			edge[t]=inf;
			arr[u][v]=arr[v][u]=inf;
			visited[u]=visited[v]=1;
			cost = cost + min;
		}
		else
		{
			edge[t]=inf;
			arr[u][v]=arr[v][u]=inf;
		}
		if(i==n-1)
		{
			c=c-i;
			final_check(edge,v1,v2,c,visited,cost);
		}
	}
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
}

void kruskals(int arr[10][10],int n)
{
	int c=0,sum=0,x,y,k,i,j,parent[20],edge[20],v1[20],v2[20];
	printf("\n\n~~~~~~~~~~~~~~~~~~Kruskal's Algorithm~~~~~~~~~~~~~~~~~~\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{		
			if(arr[i][j]==0)
			{
				arr[i][j]=inf;
			}
		}
	}

	for(i=0;i<n;i++)
	{
		parent[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{	
			if(arr[i][j]!=inf)
			{
				v1[c]=i;
				v2[c]=j;
				edge[c]=arr[i][j];
				c++;
			}
		}
	}
	for(i=0;i<c;i++)
	{
		for(j=i+1;j<c;j++)
		{
			if(v1[i]==v2[j] && v2[i]==v1[j])
			{
				for(k=j;k<c;k++)
				{
					edge[k]=edge[k+1];
					v1[k]=v1[k+1];
					v2[k]=v2[k+1];
				}
			c--;
			j--;
			}
		}
	}
	for(i=0;i<c;i++)
	{
		for(j=i+1;j<c;j++)
		{
			if(edge[i]>edge[j])
			{
				swap(&edge[i],&edge[j]);
				swap(&v1[i],&v1[j]);
				swap(&v2[i],&v2[j]);		
			}
		}
	}
	for(i=0;i<c;i++)
	{
		x=v1[i];
		y=v2[i];
		if(parent[x]!=parent[y] || parent[x]==-1 && parent[y]==-1)
		{
			if(parent[parent[x]]!=parent[y] && parent[parent[y]]!=parent[x])
			{
			printf("Edge: %d--->%d\tCost: %d\n",x,y,edge[i]);
			sum = sum + edge[i];
			parent[x]=y;
			parent[y]=x;
			}
		}
	}
	printf("The Minimum Spanning Tree Cost is %d\n",sum);		
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
}

void main()
{
	int x=1,n,a[10][10],choice,i,j,sn;
	printf("Enter the number of nodes\n");
	scanf("%d",&n);
	printf("Enter matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	while(x!=0)
	{
	printf("**************************Menu**************************\n");
	printf("1)Kruskal's Algorithm\n2)Prim's Algorithm\n");
	printf("Enter you choice :)\n");
	printf("********************************************************\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1: kruskals(a,n);
			break;

		case 2: printf("Enter source node\n");
			scanf("%d",&sn);
			prims(a,n,sn);
			break;

		default: printf("Incorrect Choice\n");
	}
	printf("Press 1 to continue else press 0\n");
	scanf("%d",&x);
	}
}
/*OUTPUT
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ gcc pk.c
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ ./a.out
Enter the number of nodes
5
Enter matrix
0 1 3 0 0
1 0 3 6 0
3 3 0 4 2
0 6 4 0 5
0 0 2 5 0
**************************Menu**************************
1)Kruskal's Algorithm
2)Prim's Algorithm
Enter you choice :)
********************************************************
1


~~~~~~~~~~~~~~~~~~Kruskal's Algorithm~~~~~~~~~~~~~~~~~~
Edge: 0--->1	Cost: 1
Edge: 2--->4	Cost: 2
Edge: 1--->2	Cost: 3
Edge: 2--->3	Cost: 4
The Minimum Spanning Tree Cost is 10
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Press 1 to continue else press 0
1
**************************Menu**************************
1)Kruskal's Algorithm
2)Prim's Algorithm
Enter you choice :)
********************************************************
2
Enter source node
0


~~~~~~~~~~~~~~~~~~~~Prim's Algorithm~~~~~~~~~~~~~~~~~~~~
Edge: 0--->1	Cost: 1
Edge: 0--->2	Cost: 3
Edge: 2--->4	Cost: 2
Edge: 2--->3	Cost: 4
Minimum Spanning Tree Cost is 10
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


Press 1 to continue else press 0
0
pooja@pooja-HP-Compaq-dc7900-Convertible-Minitower:~$ 
*/
