// Check Palindrome (recursive)

// Check whether a given String S is a palindrome using recursion. Return true or false.
// Input Format :
// String S
// Output Format :
// 'true' or 'false'
// Constraints :
// 0 <= |S| <= 1000
// where |S| represents length of string S.
// Sample Input 1 :
// racecar
// Sample Output 1:
// true

// Solution-

#include <iostream>

using namespace std;



 bool helper(char input[],int start,int end){
    
     if(start>=end){
        return true;
   }
     
       if(input[start]!=input[end]){
        return false;
    }
     
   
bool k=helper(input,start+1,end-1);
    if( k==true){
        return true;
    }
     else{return false;}
 }


bool checkPalindrome(char input[]) {
    
  
int count =0;
    for(int i=0;input[i]!='\0';i++){
        count++;
    }
    int start=0;
    int len=count -1;
    bool a=helper(input,start,len); //calling helper function
    if(a==false){
        return false;
    }
    else{return true;}
    
}



int main() {
    char input[50];
    cin >> input;
    
    if(checkPalindrome(input)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}
