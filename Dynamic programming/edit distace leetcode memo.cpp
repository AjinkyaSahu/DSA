int dp[501][501];
int solve(string s1,string s2,int i,int j){ ///make s1[0:i] equal to s2[0:j]
    //base case:1) s2 is empty and s1 is non-empty then just delete all characters
    if(i>=0 && j<0)
        return i+1;
    if(i==-1 && j==-1)
        return 0;
    ///base case:2.when s1 is empty and s2 is non-empty then just insert all characters
    if(i<0 && j>=0){
        return j+1;
    }

    ///if this sub-problem is already solved or not
    if(dp[i][j]!=-1)
        return dp[i][j];

    ///compare last char of both the string
    if(s1[i]==s2[j]){
        dp[i][j]=solve(s1,s2,i-1,j-1);
        return dp[i][j];
    }

    ///try all the operation and select the one with min val
    ///insert
    int x=solve(s1,s2,i,j-1)+1;

    ///delete
    int y=solve(s1,s2,i-1,j)+1;

    ///replace
    int z=solve(s1,s2,i-1,j-1)+1;

    ///take min of the three
    dp[i][j]=min(x,min(y,z));

    return dp[i][j];





}


class Solution {
public:
    int minDistance(string word1, string word2) {
        for(int i=0;i<=500;i++){
            for(int j=0;j<=500;j++)
                dp[i][j]=-1;
        }

        int n=word1.length();
        int m=word2.length();

        return solve(word1,word2,n-1,m-1);
    }
};
