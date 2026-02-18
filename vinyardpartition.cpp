//Vienyard partition
#include <bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>&str , vector<vector<int>>&vis,vector<vector<int>> dir , int r , int c){
     int m = str[0].size();
     vis[r][c] = 1;
     
     queue<pair<int,int>> q;
     q.push({r,c});
     
     while(!q.empty()){
         auto [i,j] = q.front();
         q.pop();
         
         for(int d = 0 ; d < 4 ; d++){
             int nr = i + dir[d][0];
             int nc = j + dir[d][1];
             
             if(nr >= 0 && nr < 2 && nc >= 0 && nc < m && vis[nr][nc] == 0 && str[nr][nc] == 'o'){
                 vis[nr][nc] = 1;
                 q.push({nr,nc});
             }
         }
     }
}

int main() {
	int n;
	cin >> n;
	int res = 0;
	
	vector<vector<char>> str(2,vector<char>(n));
	
	for(int i = 0 ; i < 2 ; i++){
	    for(int j = 0 ; j < n ; j++){
	         cin >> str[i][j];
	    }
	}
	
	vector<vector<int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
	
	for(int i = 0 ; i < 2 ; i++){
	    for(int j = 0 ; j < n ; j++){
	         if(str[i][j] == 'o'){
	             str[i][j] = 'x';
	             
	             vector<vector<int>> vis(2,vector<int>(n,0));
	             int cnt = 0;
	             
	             for(int r = 0 ; r < 2 ; r++){
	                for(int c = 0 ; c < n ; c++){
	                     if(str[r][c] == 'o' && vis[r][c] == 0){
	                         cnt++;
	                         
	                         bfs(str , vis ,dir , r , c);
	                     }
	                }
	             }
	             str[i][j] = 'o';
	             if(cnt == 3) res++;
	         }
	    }
	}
    cout << res;
}