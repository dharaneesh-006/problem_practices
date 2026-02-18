#include <bits/stdc++.h>
using namespace std;

int n,m;
pair<int,int> apos,bpos;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int minlen = INT_MAX;
string final = ""

bool check(int i,int j,vector<vector<char>>& mat){
    return i >= 0 && i < n && j >= 0 && j < m && mat[i][j] == '.';
}

bool solve(int i,int j, vector<vector<char>> &mat, string &s)
{
    
}


int main() {
    cin >> n >> m;
    vector<vector<char>> mat;
    mat.resize(n,vector<char>(m));
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cin >> mat[i][j];
            if(mat[i][j] == 'A'){
                apos.first = i;
                apos.second = j;
            }
            if(mat[i][j] == 'B'){
                bpos.first = i;
                bpos.second = j;
            }
        }
    }
    string s = "";
    solve(apos.first,apos.second,mat,s);
    if(s.empty()) cout << "NO" << endl;
    else cout << "YES" << endl;
    cout << s.length() << endl;
    cout << s << endl;
    return 0;
}