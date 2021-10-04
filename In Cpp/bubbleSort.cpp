// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;
 
void bubbleSort(int arr[], int n) {
    int i, j;
    bool swapped;
    for (i = 0; i < n-1; i++) {
        swapped = false;
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (swapped == false)
        break;
    }
}
 
// Driver program to test above functions
int main() {
	cout<<"Enter number of elements:";
    int n; cin>>n;
	cout<<"Enter number of elements:";
	int arr[n];
	for(int i=0; i<n; ++i)cin>>arr[i];
    
    bubbleSort(arr, n);
    cout <<"Sorted array: \n";
    for(auto num:arr)cout<<num<<" ";
    cout<<"\n";
    return 0;
}