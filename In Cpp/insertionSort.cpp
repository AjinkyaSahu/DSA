// C++ program for insertion sort
#include <bits/stdc++.h>
using namespace std; 

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1; 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main() {
	cout<<"Enter number of elements:";
    int n; cin>>n;
	cout<<"Enter number of elements:";
	int arr[n];
	for(int i=0; i<n; ++i)cin>>arr[i];
    
    insertionSort(arr, n);
    cout <<"Sorted array: \n";
    for(auto num:arr)cout<<num<<" ";
    cout<<"\n";
    return 0;
}