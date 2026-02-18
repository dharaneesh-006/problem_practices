#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define inf 1e9

int n, m, k;
vector<vector<pair<int,int>>> mat;

void print_mat()
{
    for(int i = 1; i <= n; i++)
    {
        for(auto &edge : mat[i])
        {
            cout << "u : " << i 
                 << " v : " << edge.first 
                 << " w : " << edge.second << endl;
        }
    }
}


int main() {


    cin >> n >> m >> k;

    mat.resize(n + 1);   

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        mat[u].push_back({v, w});
        mat[v].push_back({u, w});  
    }

    vector<vector<int>> dist(n+1,vector<int>(k+1,inf));
    priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>, greater<tuple<int,int,int>>>pq; // {cost,node, upgrade}

    dist[1][0] = 0;
    pq.push({0,1,0});

    while(!pq.empty())
    {
        auto [cost,u, used] = pq.top();
        pq.pop();

        if(cost > dist[u][used]) continue;
        
        for(auto &[v,w] : mat[u])
        {
            if(dist[v][used] > cost+w)
            {
                dist[v][used] = cost+w;
                pq.push({dist[v][used], v, used});
            }

            if(used < k && dist[v][used+1] > cost)
            {
                dist[v][used+1] = cost;
                pq.push({cost,v,used+1});
            }
        }

    }




    int ans = inf;
    for(int i = 0 ; i <= k ; i++)
    {
        ans = min(ans,dist[n][i]);
    }

    cout << ans;

    return 0;
}
