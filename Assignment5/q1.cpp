#include<iostream>
#include<vector>

using namespace std;

int dfs(int i,int j,vector<vector<char>>& grid){
    grid[i][j]=0;
    int ans{1};
    if(i-1 >= 0 && grid[i-1][j] == '1') ans+=dfs(i-1,j,grid);
    if(i+1 < grid.size() && grid[i+1][j] == '1')  ans+=dfs(i+1,j,grid);
    if(j-1 >= 0 && grid[i][j-1] == '1') ans+=dfs(i,j-1,grid);
    if(j+1 < grid[0].size() && grid[i][j+1] == '1') ans+=dfs(i,j+1,grid);
    if(i-1 >= 0 && j-1>=0 && grid[i-1][j-1] == '1') ans+=dfs(i-1,j-1,grid);
    if(i+1 < grid.size() && j+1<grid[0].size() && grid[i+1][j+1] == '1')  ans+=dfs(i+1,j+1,grid);
    if(j-1 >= 0 && i+1 < grid.size() && grid[i+1][j-1] == '1') ans+=dfs(i+1,j-1,grid);
    if(j+1 < grid[0].size() && i-1 >= 0 && grid[i-1][j+1] == '1') ans+=dfs(i-1,j+1,grid);
    return ans;
}

int main(){
    vector<vector<char>> grid{
        {'1','1','0','1','0'},
        {'1','1','0','1','0'},
        {'1','1','1','0','0'},
        {'0','0','0','0','1'}
    };
    int n=grid.size();
    int m=grid[0].size();
    int ans=0;

    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == '1'){
                ans=max(ans, dfs(i,j,grid));
            }
        }
    }
    cout<<ans;
    return 0;
}