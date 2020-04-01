
#include<stdio.h>
#include<math.h>
#define MAX 10
int n,i,j,k,x[MAX];
char Q[MAX][MAX];
display()
{
	for(i=1;i<=n;i++)
	{
		printf("%d\t",x[i]);
	}
	printf("\n\n");
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(x[i]==j)
			{
				Q[i][j]='Q';
			}
		}
	
	}

		for(i=1;i<=n;i++)
	{
		printf("\n--------------------------------\n");
		for(j=1;j<=n;j++)
		{
			printf("   %c   |",Q[i][j]);
		}
	
	}
		printf("\n--------------------------------\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
int nextvalue(int k)
{
//	printf("\n x[%d]=%d",k,x[k]);
	x[k]=(x[k]+1)%(n+1);
//	printf("\n x[%d]=%d",k,x[k]);
	if(x[k]==0)
	{
		return k;
	}
	for(j=1;j<k;j++)
	{
		if((x[k]==x[j])||(abs(x[k]-x[j])==abs(k-j)))
		{
			nextvalue(k);
		}
	
	}
	return k;

}

void nqueens(int k)
{
//	printf("\n x[%d]=%d",k,x[k]);
	k=nextvalue(k);
//	printf("\n After returning from nextvalue:\n");
	
//	printf("\n x[%d]=%d",k,x[k]);
		if(x[k]==0)
		{
			return(nqueens(k-1));
		}
		if(k==n)
		{
			printf("\n ALL QUEENS ARE PLACED:\n");
			display();
		}
		else
		{
		//	printf("\n%d",k);
			nqueens(k+1);
		}
}

int main()
{
	printf("\nEnter no. of queens:\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		x[i]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			Q[i][j]=' ';
		}
	
	}
	display();
	k=1;
	nqueens(k);
	return 0;
	
}
