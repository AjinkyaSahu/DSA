#include<iostream>
using namespace std;
int main(){
    cout<<" Enter a number of your choice: ";
    int n;
    cin>>n;
    int reverse=0;

    
     while(n>0){
         int lastdigit=n%10;           //n=19;last=9;      //step2:1%10=1
         reverse=reverse*10+lastdigit;//r=0*10+9=9      //r=9*10+1=91
         n=n/10;                        //n=1
        

     }
     cout <<" Reversed no is: "<<reverse<<endl;

}
