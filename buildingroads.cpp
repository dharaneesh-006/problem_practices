#include <bits/stdc++.h>
using namespace std;

vector<bool> visi;

void dfs(int num,vector<vector<int>> &adj)
{
    visi[num] = true;

    for(int nei : adj[num])
    {
        if(!visi[nei])
        {
            dfs(nei,adj);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n+1);

    visi.resize(n+1,false);

    for(int i = 0 ; i < m ; i++)
    {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> rep;

    for(int i = 1 ; i <= n ; i++)
    {
        if(!visi[i])
        {
            rep.push_back(i);
            dfs(i,adj);
        }
    }

    int siz = rep.size()-1;
    cout << siz << endl;

    for(int i = 1 ; i <= siz ; i++)
    {   
        cout << rep[i-1] << " "<< rep[i] << endl; 

    }




    return 0;
}