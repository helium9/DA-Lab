#include<iostream>
#include<vector>
#include<queue>
#include<tuple>

using namespace std;
using ti = tuple<char, int, int>;

bool comp(ti t1, ti t2){
    if(get<1>(t1)<get<1>(t2))return false;
    else if(get<1>(t1)==get<1>(t2)){
        if(get<2>(t1)>get<2>(t2))return false;
        else return true;
    }
    else return true;
}

int main(){
    int n, b, c;
    char a;
    ti t;
    cin>>n;
    priority_queue<ti, vector<ti>, decltype(&comp)> p(comp);
    for(int i{0}; i<n; i++){
        cin>>a>>b>>c;
        p.push({a, b, c});
    }

    int time{1}, profit{0};
    queue<char> seq;
    while(!p.empty()){
        ti curr = p.top();
        p.pop();
        if(time<=get<1>(curr)){
            time++;
            seq.push(get<0>(curr));
            profit+=get<2>(curr);
        }
    }
    cout<<endl;
    while(!seq.empty()){
        char job = seq.front();
        cout<<job<<" ";
        seq.pop();
    }
    cout<<profit<<endl;
    return 0;
}