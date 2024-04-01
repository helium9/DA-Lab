#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<algorithm>
#include<fstream>

using namespace std;
using ti = tuple<char, int, int>;

bool comp(ti t1, ti t2){
    if(get<1>(t1)>get<1>(t2))return false;
    else if(get<1>(t1)==get<1>(t2)){
        if(get<2>(t1)>get<2>(t2))return false;
        else return true;
    }
    else return true;
}

int helper(vector<ti>& v, int ind, int time, int n, int max_t, vector<vector<int>>& dp){
    if(ind>=n)return 0;
    if(time>max_t)return INT_MIN;
    if(dp[ind][time]!=-1)return dp[ind][time];
    int ans = helper(v, ind+1, time, n, max_t, dp);
    if(time<=get<1>(v[ind]) && time<=max_t) ans = max(ans, helper(v, ind+1, time+1, n, max_t, dp)+get<2>(v[ind]));
    return dp[ind][time] = ans;
}

int main(){
    int n, b, c, max_t{0};
    char a;
    ti t;
    fstream myFile;
    myFile.open("q2_input.txt", ios::in);
    myFile>>n;
    vector<ti> v(n);
    for(int i{0}; i<n; i++){
        myFile>>a>>b>>c;
        max_t=max(max_t, b);
        v[i] = {a, b, c};
    }
    // cout<<max_t<<endl;
    sort(v.begin(), v.end(), comp);
    vector<vector<int>> dp(n, vector<int>(max_t+1, -1));
    myFile.close();
    myFile.open("q2_output.txt", ios::out);
    myFile<<helper(v, 0, 1, n, max_t, dp)<<endl;
    myFile.close();
    return 0;
}

//time complexity: O(n*max_t)