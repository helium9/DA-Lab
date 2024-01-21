#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void merge(vector<int>& v, int n, int m){
    for(int i{m}; i<n; i++){
        int j{0};
        while(i-j-1>=0 && v[i-j]<v[i-j-1]){
            int temp = v[i-j-1];
            v[i-j-1]=v[i-j];
            v[i-j]=temp;
            j++;
        }
    }
}
int main(){
    fstream myFile;
    myFile.open("in.txt", ios::in);
    int n, m;
    if (!myFile.is_open()) {
        std::cerr << "Error opening the myFile!" <<endl;
        return 1;
    }
    myFile>>n>>m;
    vector<int> v(n);
    for(int i{0}; i<n; i++)myFile>>v[i];
    myFile.close();

    merge(v, n, m);
    myFile.open("out.txt", ios::out);

    for(auto i:v){
        myFile<<i<<" ";
    }
    myFile.close();
    return 0;
}