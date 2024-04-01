#include<iostream>
#include<vector>
#include<queue>
#include<tuple>
#include<fstream>

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
    fstream myFile;
    myFile.open("q2_input.txt", ios::in);
    myFile>>n;
    priority_queue<ti, vector<ti>, decltype(&comp)> p(comp);
    for(int i{0}; i<n; i++){
        myFile>>a>>b>>c;
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
    myFile.close();
    myFile.open("q2_output.txt", ios::out);
    while(!seq.empty()){
        char job = seq.front();
        myFile<<job<<" ";
        seq.pop();
    }
    myFile<<endl;
    myFile<<profit<<endl;
    myFile.close();
    return 0;
}