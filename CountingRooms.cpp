#include <bits/stdc++.h>
using namespace std;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int n,m;
bool check(int i,int j,vector<vector<char>>& mat){
    return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == '.';
}

void solve(int i,int j, vector<vector<char>> &mat)
{
    mat[i][j] = '#';
    for(int k = 0 ; k < 4 ; k++)
    {
        if(check(i+dx[k],j+dy[k],mat))
        {
            solve(i+dx[k],j+dy[k],mat);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    int cnt = 0;
    vector<vector<char>> mat(n,vector<char>(m));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> mat[i][j];
        }
    }
    for(int i = 0 ;i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            if(mat[i][j] == '.')
            {
                cnt++;
                solve(i,j,mat);
            }
        }
    }
    cout << cnt << endl;
    

    return 0;
}