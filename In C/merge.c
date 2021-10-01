#include<stdio.h>
void main()
{
	printf("Kindly enter the number of elements you want to print.\n");
	int n;int a[n];int i=0,j=0;int b[n];
	scanf("%d",&n);
	printf("Please enter the array elements of 1st array. !!!!\n");
    while(i<n)
	{
		scanf("%d",&a[i]);
		i++;
    }
    printf("Please enter the array elements of 2nd array. !!!!\n");
    while(j<n)
	{
		scanf("%d",&b[j]);
		j++;
    }
    int m=n+n; int c[m];int k=0;int p=0;
    printf("Displaying the array elements. !!!!\n");
    while(k<m)
    {
    	if(k<n)
    	{
    		c[k]=a[k];
    		printf("%d\n",c[k]);
        }
        else
        {
        	c[k]=b[p];
        	p++;
        	printf("%d\n",c[k]);
		}
		k++;
	}
}
