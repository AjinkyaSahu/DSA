#include<bits/stdc++.h>
using namespace std;
int groupAnagrams(vector<string>& strs){
    unordered_map<string,vector<string>> mymp;
    int n=strs.size();
    for(int i=0;i<n;i++)
    {
        string temp=strs[i];
        sort(strs[i].begin(),strs[i].end());
        mymp[strs[i]].push_back(temp);
    }
    vector<vector<string>> res;
    for(auto j=mymp.begin();j!=mymp.end();j++)
        res.push_back(j->second);
    return res.size();
}
int main()
{
    vector<string> strs;
    string s;
    int ans,num;
    cout<<"enter no. of strings\n";
    cin>>num;
    cout<<"enter the strings\n";
    while(num--)
    {
      cin>>s;
      strs.push_back(s);
    }
    ans=groupAnagrams(strs);
    cout<<ans;
}
