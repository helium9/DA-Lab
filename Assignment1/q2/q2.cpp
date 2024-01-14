#include <iostream>
#include <vector>

using namespace std;

int knapsack(int capacity, const vector<int>& weights, const vector<int>& values, int n) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i){
        for (int w = 0; w <= capacity; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> values(n);
        vector<int> weights(n);
        for(int i{0}; i<n; i++){
            cin>>weights[i];
        }
        for(int i{0}; i<n; i++){
            cin>>values[i];
        }
        int capacity;
        cin>>capacity;

        int result = knapsack(capacity, weights, values, n);
        cout <<result<<endl;
    }
    return 0;
}
