#include<iostream>
#include<vector>

using namespace std;
using vi = vector<int>;

int helper(vi& values, vi& weights, int ind, int cap, vector<vi>& dp){
    if(cap==0 || ind>=values.size())return 0;
    if(dp[ind][cap]!=-1)return dp[ind][cap];
    int ans = helper(values, weights, ind+1, cap, dp);
    if(cap>=weights[ind]) ans=max(ans, helper(values, weights, ind+1, cap-weights[ind], dp)+values[ind]);
    return dp[ind][cap] = ans;
}

int main(){
    int n, cap;
    cin>>n>>cap;
    vi weights(n), values(n);
    vector<vi> dp(n, vi(cap+1, -1));
    for(int i{0}; i<n; i++)cin>>weights[i];
    for(int i{0}; i<n; i++)cin>>values[i];
    cout<<helper(values, weights, 0, cap, dp);
    return 0;
}