#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e5 + 5;

int n;

vector<int> g[maxn];
int subsz[maxn];

void dfs(int u, int par){
    subsz[u] = 1;
    
    for(int v : g[u]){
        if(v != par){
            dfs(v, u);
            subsz[u] += subsz[v];
        }
    }
}

void solve(){
    cin >> n;
    
    for(int v = 2; v <= n; v += 1){
        int u;
        cin >> u;
        
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    dfs(1, 0);
    
    for(int i = 1; i <= n; i += 1)
        cout << subsz[i] - 1 << " ";
    cout << endl;
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    solve();
    
    return 0;
}
