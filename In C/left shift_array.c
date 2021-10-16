// Program to left rotate (shift) the array by one position

#include<stdio.h>
void LeftRotateArray(int *arr, int n)
{
	int temp, i;
	temp = arr[0];
	for(i=0; i<n-1; ++i)
	{
		arr[i]=arr[i+1];
	}
	arr[n-1] = temp;
}

int main()
{
	int arr[100];
	int n, i;
	printf("\nEnter the size of the array : ");
	scanf("%d", &n);
	
	printf("Enter the array elements : \n");
	for(i=0; i<n; ++i)
	{
		scanf("%d", &arr[i]);
	}
	
	LeftRotateArray(arr, n);
	printf("\nArray distribution after left rotation by one position : ");
	for(i=0; i<n; ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
