#include<iostream>
#include<vector>
#include<fstream>

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
    fstream myFile;
    myFile.open("q1_input.txt", ios::in);
    myFile>>n>>cap;
    vi weights(n), values(n);
    vector<vi> dp(n, vi(cap+1, -1));
    for(int i{0}; i<n; i++)myFile>>weights[i];
    for(int i{0}; i<n; i++)myFile>>values[i];
    myFile.close();
    myFile.open("q1_output.txt", ios::out);
    myFile<<helper(values, weights, 0, cap, dp);
    myFile.close();
    return 0;
}