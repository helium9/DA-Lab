#include<iostream>
#include<vector>
#include<queue>

using namespace std;
using vi = vector<int>;
using pdi = pair<double, int>;

int main(){
    int n, cap;
    cin>>n>>cap;
    vi weights(n), values(n);
    vector<vi> dp(n, vi(cap+1, -1));
    for(int i{0}; i<n; i++)cin>>weights[i];
    for(int i{0}; i<n; i++)cin>>values[i];
    priority_queue<pdi> specific_value;
    for(int i{0}; i<n; i++)specific_value.push({(double)values[i]/(double)weights[i], weights[i]});
    double ans{0};
    while(!specific_value.empty()){
        pdi curr=specific_value.top();
        specific_value.pop();
        if(cap>=curr.second){
            cap-=curr.second;
            ans+=(curr.first*curr.second);
        }
        else continue;
    }
    cout<<(int)ans;
    return 0;
}