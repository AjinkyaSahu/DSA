#include <iostream>
#include<queue>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
};
 
struct node* CreateNode(int data)
{
    struct node* temp = new struct node;
    temp->data = data;
    temp->left = nullptr;
    temp->right = nullptr;
    return temp;
};
 
int main()
{
    struct node* root = new struct node;
    cout<<"Enter level at which you want to get the sum"<<'\n';
    int k;
    cin>>k;
    root = CreateNode(50);
    root->left = CreateNode(30);
    root->right = CreateNode(70);
    root->left->left = CreateNode(20);
    root->left->right = CreateNode(40);
    root->right->left = CreateNode(60);
    int ans = sumatlevelk(root, k);
 
    // Printing the result
    cout << ans;
 
    return 0;
}