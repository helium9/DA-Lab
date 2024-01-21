#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

vector<int> merge(const vector<int>& v1, const vector<int>& v2){
    int p1{0}, p2{0};
    vector<int> v(v1.size()+v2.size());
    // cout<<"hi"<< v1.size()<<" "<<v2.size()<<"hi";
    for(int i{0}; i<v1.size()+v2.size(); i++){
        if(p1<v1.size() && p2<v2.size()){
            if(p1<v1.size() && v1[p1]>=v2[p2]){
                v[i]=v2[p2];
                p2++;
            }
            else if(p2<v2.size() && v2[p2]>v1[p1]){
                v[i]=v1[p1];
                p1++;
            }
        }
        else{
            if(p1>=v1.size() && p2<v2.size()){
                v[i]=v2[p2];
                p2++;
            }
            else if(p2>=v2.size() && p1<v1.size()){
                v[i]=v1[p1];
                p1++;
            }
        }
    }
    return v;
}
int main(){
    fstream myFile;
    myFile.open("in.txt", ios::in);
    int n, m;
    if (!myFile.is_open()) {
        std::cerr << "Error opening the myFile!" <<endl;
        return 1;
    }
    myFile>>n;
    vector<int> v1(n);
    for(int i{0}; i<n; i++)myFile>>v1[i];
    myFile>>m;
    vector<int> v2(m);
    for(int i{0}; i<m; i++)myFile>>v2[i];
    myFile.close();
    // vector<int> v1{1,4,7}, v2{2,3};
    vector<int> v3 = merge(v1, v2);
    myFile.open("out_a.txt", ios::out);

    for(auto i:v3){
        myFile<<i<<" ";
    }
    return 0;
}