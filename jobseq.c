#include <stdio.h>
#define max 10
int id[max];
int n,d[max],p[max],slot[max],dmax;
void jobsequence()
{
	int c=0,i,k;
	int sump=0;
	dmax=d[0];
	for(i=0;i<n;i++)
	{
		if(dmax<d[i])
		dmax=d[i];
	}
	printf("Max deadline is %d",dmax);
	for(i=1;i<=dmax;i++)
	{
		slot[i]=-1;
	}
	for(i=0;i<n;i++)
	{
		k=dmax>d[i]?d[i]:dmax;
		while(k>0)
		{
			if(slot[k]==-1)
			{
				slot[k]=i;
				c++;
				sump+=p[i];
				break;
			}
			k--;
		}
		if(c==dmax)
		break;
	}
	printf("maximum profit is %d",sump);
}
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void main()
{
	int i,j;
	printf("Enter number of jobs");
	scanf("%d",&n);
	printf("Enter id");
	for(i=0;i<n;i++)
	{
		scanf("%d",&id[i]);
	}
	printf("Enter deadlines");
	for(i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	printf("Enter profit");
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	for (i = 0; i < n-1; i++)     
    {
	  for (j = 0; j < n-i-1; j++)
        {
		   if (p[j] < p[j+1])
		    {
              swap(&p[j],&p[j+1]);
              swap(&d[j],&d[j+1]);
              swap(&id[j],&id[j+1]);
          	}
      	}
  	}
	jobsequence();
  	printf("Selected jobs are \n");
  	for(i=1;i<=dmax;i++)
  	{
  		if(slot[i]!=-1)
		  printf("\n %d",id[slot[i]]);
	  }
  }
