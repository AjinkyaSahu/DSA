#include<bits/stdc++.h>
using namespace std;

int main (){
	int n;
  cin >> n;
  
  int dp[n+2];
  
	dp[0]=0;
  dp[1]=1;
  for (int i=2;i<=n;i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  
  cout << n << "th fibonacci number is " <<  dp[n] << '\n';
  
	return 0;
}
