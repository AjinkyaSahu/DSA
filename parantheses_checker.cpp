#include<iostream>
using namespace std;
class Solution {
public:
bool isValid(string s) {
stack<char >stack;
int l=s.length();
for(int i=0;i<l;i++)
{
if(s[i]=='('||s[i]=='{'||s[i]=='[')
{
stack.push(s[i]);//store only open brace and continue compare s[i] with stack top
continue;
}
if(stack.empty())
return false;
char x = stack.top();
if((x=='(' && s[i]==')') || (x=='{' && s[i]=='}') || (x=='[' && s[i]==']'))
stack.pop();
else
return false;
}
if(stack.empty())
{
return true;
}
else
return false;

}
};
int main()
{
  cout>>"enter the parantheses as string"<<endl;
  string s;
  cin>>s;
  if(isValid(s))
    cout<<"valid"<<endl;
  else
    cout<<"invalid"<<endl;
  return 0;
}
