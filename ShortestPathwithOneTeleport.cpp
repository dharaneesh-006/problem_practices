#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> mat;
vector<pair<int,int>> tvec;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

bool check(int i,int j){
    return i>=0 && i<n && j>=0 && j<m;
}

void dijkstra(){

    vector<vector<int>> dis(n, vector<int>(m, 1e9));

    priority_queue<
        pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>
    > pq;

    

    dis[0][0] = 0;

    pq.push({0,{0,0}});

    bool teleportUsed = false;

    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();

        int d = it.first;
        int i = it.second.first;
        int j = it.second.second;

        if(d > dis[i][j]) continue;

        // Normal moves
        for(int p=0;p<4;p++){
            int ni = i + dx[p];
            int nj = j + dy[p];

            if(check(ni,nj) && mat[ni][nj] != '#'){
                if(d + 1 < dis[ni][nj]){
                    dis[ni][nj] = d + 1;
                    pq.push({d+1,{ni,nj}});
                }
            }
        }

        // Teleport
        if(mat[i][j] == 'T' && !teleportUsed){
            teleportUsed = true;

            for(auto &cell : tvec){
                int ni = cell.first;
                int nj = cell.second;

                if(d + 1 < dis[ni][nj]){
                    dis[ni][nj] = d + 1;
                    pq.push({d+1,{ni,nj}});
                }
            }
        }
    }

    int ans = dis[n-1][m-1];
    if(ans == 1e9) ans = -1;

    cout << ans;
}

int main(){

    cin >> n >> m;

    mat.resize(n);

    for(int i=0;i<n;i++){
        cin >> mat[i];
        for(int j=0;j<m;j++){
            if(mat[i][j] == 'T')
                tvec.push_back({i,j});
        }
    }

    if(mat[0][0] == '#' || mat[n-1][m-1] == '#'){
        cout << -1;
        return 0;
    }

    dijkstra();
}




// Shortest Path with One Teleport


// You are given a grid of size N × M.
// Cells can be:
// ● '.' → free cell
// ● '#' → blocked
// ● 'T' → teleport cell
// You start at (0,0) and must reach (N-1, M-1).
// Rules:
// ● Move up/down/left/right
// ● If you step on a teleport cell, you can teleport to any other teleport cell instantly
// (cost = 1 total move)
// Find the minimum steps required.
// Input Format
// N M
// Grid row 1
// Grid row 2
// ...
// Grid row N
// Output Format
// Minimum steps or else print -1
// Constraints
// ● 1 ≤ N, M ≤ 1000
// Sample Input
// 3 3
// ...
// .T.
// ...
// Sample Output
// 4
// Explanation
// Teleport helps reduce distance.
// Test Cases:
// Input:
// 3 3
// ...
// .#.
// ...
// Output:
// 4
// Input:
// 4 4
// .T..
// ####
// ..T.
// ....
// Output:
// 6
// Input:
// 3 4
// TTTT
// ....
// TTTT
// Output:
// 2
// Input:
// 1 1
// .
// Output:
// 0
// Input:
// 2 2
// ##
// ##
// Output:
// -1
