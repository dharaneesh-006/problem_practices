#include <bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node* left;
    node* right;
    node(int num)
    {
        val = num;
        left = right = nullptr;
    }
};

vector<int> vec;
map<int,vector<int>> mp;

node* insert(int val,node* root)
{
    if(root == nullptr){
        root = new node(val);
        return root;
    }
    queue<node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        node* curr = q.front();
        q.pop();


        if(curr -> left != nullptr)
        {
            insert(val,curr->left);
        }
        else{
            curr -> left = new node(val);
            return root;
        }

        if(root -> right != nullptr)
        {
            insert(val,root->right);
        }
        else{
            root -> right = new node(val);
            return root;
        }
    }

}





int main() {
    int n,k;
    cin >> n >> k;
    vec.resize(n+1);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> vec[i];
    }
    for(int i = 1 ; i < n ; i++)
    {
        int u,v;
        cin >> u >> v;
        mp[u].push_back(v);
    }


    return 0;
}