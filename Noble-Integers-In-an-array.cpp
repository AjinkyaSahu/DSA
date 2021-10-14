// C++ program to find Noble elements
// in an array.
#include <bits/stdc++.h>
using namespace std;

// Returns a Noble integer if present,
// else returns -1.
int nobleInteger(int arr[], int size)
{
	for (int i = 0; i < size; i++ )
	{
		int count = 0;
		for (int j = 0; j < size; j++)
			if (arr[i] < arr[j])
				count++;
				
		// If count of greater elements
		// is equal to arr[i]
		if (count == arr[i])
			return arr[i];
	}
	
	return -1;
}

// Driver code
int main()
{
	int arr[] = {10, 3, 20, 40, 2};
	int size = sizeof(arr) / sizeof(arr[0]);
	int res = nobleInteger(arr, size);
	
	if (res != -1)
		cout<<"The noble integer is "<< res;
	else
		cout<<"No Noble Integer Found";
}

// This code is contributed by Smitha.
