#include <iostream>

using namespace std;
void solve(int rem[],int b[],int n1,int n2,int res[])
{
    int i=0;
    while(i<n1)
    {
        if(rem[i]==0)
            i++;
        else
        {
            int c=n2;
            int j=i;
            int k=0;
            while(c--)
            {
                rem[j]^=b[k];
                j++;
                k++;
            }
        }
    }
    for(int i=n1;i<n1+n2-1;i++)
        res[i-n1]=rem[i];
}

int main()
{
    cout<<"Enter Bit Stream: ";
    int num;
    cin>>num;
    int n1=0;
    int tem=num;
    while(tem)
    {
        tem/=10;
        n1++;
    }
    int a[n1];
    for(int i=n1-1;i>=0;i--)
    {
        a[i]=num%10;
        num/=10;
    }
    cout<<"Enter Polynomial:";
    cin>>num;
    int n2=0;
    tem=num;
    while(tem)
    {
        tem/=10;
        n2++;
    }
    int b[n2];
    for(int i=n2-1;i>=0;i--)
    {
        b[i]=num%10;
        num/=10;
    }
    int rem[n1+n2-1]={0};
    for(int i=0;i<n1;i++)
        rem[i]=a[i];
    int res[n2-1]={0};
    solve(rem,b,n1,n2,res);
    cout<<"Message to be Transmitted:";
    for(int i=0;i<n1;i++)
        cout<<a[i];
    for(int i=0;i<n2-1;i++)
        cout<<res[i];
    cout<<"\nReceiver Side:";
    cout<<"\nReceived Message:";
    cin>>num;
    int msg[n1+n2-1];
    for(int i=n1+n2-2;i>=0;i--)
    {
        msg[i]=num%10;
        num/=10;
    }
    int res_r[n2-1]={0};
    solve(msg,b,n1,n2,res_r);
    cout<<"Remainder:";
    int c=0;
    for(int i=0;i<n2-1;i++)
    {
        cout<<res_r[i];
        if(res_r[i]==0)
            c++;
    }
    if(c==n2-1)
        cout<<"\nMessage Accepted.";
    else
        cout<<"\nMessage Received is Incorrect.";
    return 0;
}
