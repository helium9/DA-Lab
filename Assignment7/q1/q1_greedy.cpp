#include<iostream>
#include<vector>
#include<queue>
#include<fstream>

using namespace std;
using vi = vector<int>;
using pdi = pair<double, int>;

int main(){
    int n, cap;
    fstream myFile;
    myFile.open("q1_input.txt", ios::in);
    myFile>>n>>cap;
    vi weights(n), values(n);
    vector<vi> dp(n, vi(cap+1, -1));
    for(int i{0}; i<n; i++)myFile>>weights[i];
    for(int i{0}; i<n; i++)myFile>>values[i];
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
    myFile.close();
    myFile.open("q1_output.txt", ios::out);
    myFile<<(int)ans;
    myFile.close();
    return 0;
}