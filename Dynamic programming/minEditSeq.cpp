#include<string.h>
#include<iostream>
using namespace std;
int min(int a, int b, int c)
{
    int temp;
	temp = (a < b)    ? a : b;
    return (c < temp) ? c : temp;
}
int main()
{
    string str1, str2;
    cin>>str1>>str2;
	int m=str1.size(), n=str2.size();
    int dp[m+1][n+1];

	for(int i=0; i<=m+1; i++)
	{
		for (int j=0; j<=n+1; j++)
		{
			if(i==0)
			    dp[i][j]=j;
			else if(j==0)
			    dp[i][j]=i;
			else if(str1[i-1]==str2[j-1])
			    dp[i][j]=dp[i-1][j-1];
			else 
			    dp[i][j] = 1+min(dp[i][j-1], dp[i-1][j], dp[i-1][j-1]);
		}
	}
	cout<< dp[m][n]<<endl;
	int i=m, j=n;
	while(true)
	{
		if(i==0)
			break;
		if(j==0 && i!=0)
        {
            cout<<"delete "<<str1[i-1]<<" in str1"<<endl;
			i--;
		}
		if(str1[i-1]==str2[j-1])
        {
			i--;
            j--;
		}
		else if(dp[i][j]==dp[i-1][j-1]+1)
        {
            cout<<"edit "<<str1[i-1]<<" in str1 to "<<str2[j-1]<<" in str2"<<endl;
			i--;
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]+1)
        {
            cout<<"delete "<<str1[i-1]<<" in str1"<<endl;
			i--;
		}
		else if(dp[i][j]==dp[i][j-1]+1)
        {
            cout<<"delete "<<str2[j-1]<<" in str2"<<endl;
			j--;
		}
	}
	return 0;
}