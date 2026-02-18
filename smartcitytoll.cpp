#include<bits/stdc++.h>
using namespace std;

int main(){
    int q;
    cin>>q;
    int res=0;
    map<long long,long long> tree;
    while(q--){
        int t; cin>>t;
        if(t==1){
            int u,v,w;
            cin>>u>>v>>w;
            while(u!=v){
                if(u>v){
                    tree[u]+=w;
                    u/=2;
                }
                else{
                    tree[v]+=w;
                    v/=2;
                }
            }
        }
        else{
            int u,v,w;
            int cost=0;
            cin>>u>>v>>w;
            while(u!=v){
                if(u>v){
                    cost+=tree[u];
                    u/=2;
                }
                else{
                    cost+=tree[v];
                    v/=2;
                }
            }
            res+=cost;
        }
    }
    cout<<res;
}