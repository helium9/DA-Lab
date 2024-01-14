#include<iostream>
#include<vector>

using namespace std;

void permute(vector<int>& choices, vector<bool>& chosen, vector<vector<int>>& output){
    if(chosen.size()==choices.size()){
        output.push_back(choices);
        return;
    }
    for(int i{0}; i<chosen.size(); i++){
        if(chosen[i]==false){
            choices.push_back(i);
            chosen[i]=true;
            permute(choices, chosen, output);
            chosen[i]=false;
            choices.pop_back();
        }
    }
}

vector<string> TSP(vector<vector<int>>& G, vector<string>& city){
    vector<int> choices;
    vector<vector<int>> temp;
    vector<bool> chosen(city.size()-1);
    // chosen[1]=true;
    permute(choices, chosen, temp);
    int min_cost{INT_MAX};
    for(auto path:temp){
        int cost{0};
        for(int i{0}; i<path.size()-1; i++){
            cost+=G[path[i]][path[i+1]];
        }
        cost+=G[path[0]][city.size()-1]+G[path.back()][city.size()-1];
        // cout<<cost<<endl;
        if(cost<min_cost){
            min_cost=cost;
            choices=path;
        }
    }
    vector<string> output;
    for(auto i:choices){
        output.push_back(city[i]);
    }
    output.push_back(city.back());
    return output;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> G;
        vector<string> city_name(n);
        for(int i{0}; i<n; i++){
            cin>>city_name[i];
        }
        for(int i{0}; i<n ;i++){
            vector<int> temp(n);
            for(int j{0}; j<n; j++){
                cin>>temp[j];
            }
            G.push_back(temp);
        }
        vector<string> min_path = TSP(G, city_name);
        for(auto i:min_path){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    // vector<vector<int>> G={
    //     {0, 20, 42, 35},
    //     {20, 0, 30, 34},
    //     {42, 30, 0, 12},
    //     {35, 34, 12, 0}
    // };
    // vector<string> city_name = {'A', 'B', 'C', 'D'};
    return 0;
}