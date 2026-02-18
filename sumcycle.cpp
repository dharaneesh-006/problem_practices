#include <bits/stdc++.h>
using namespace std;

vector<int> dis ;
vector<int > vis;
int maxx = -1e9 ;
vector<vector<int>> adj;
void dfs(int u , int par , int level   ) { 

    
    vis[u] = true;


    for(int v : adj[u]){

        if( v == par) continue;
          if(!vis[v]){   
            dis[v] += dis[u];
            dfs( v , u , level + 1 );
        }
        else if(vis[v] == 1 ){
            maxx = max( maxx , dis[u] - (dis[v] - v )    );
        }
    }
    vis[u] = 2 ;

}

int main() {

    int n;
    cin>>n;
    
    adj.resize(n + 1);
    dis.resize( n + 1 , 0 );
    vis.resize( n + 1 ,0  );
    for(int i = 0 ;i <= n ;i++) dis[i] = i ;
    for(int u = 0 ; u < n ; u++){
        int v;
        cin>>v;
        if(v==-1)continue;

        adj[u].push_back(v);
    }   
    if( n == 1 && adj[0][0] == 0  ){
        cout<<0;
        return 0;
    }

    for(int i = 0 ; i < n ; i++){
        if( !vis[i] ){
            dfs( i , 0 , 0 );
        }
    }
    if(maxx == -1e9) cout << -1 << endl;
    else{
        cout << maxx << endl;
    }

    
    return 0;
}