#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void selectionSort(vector<int>& v, int passes){
    for(int i{0}; i<passes && i<v.size()-1; i++){
        int minIndex = i;
        for(int j{i+1}; j<v.size(); j++){
            if(v[j]<v[minIndex]){
                minIndex = j;
            }
        }
        swap(v[i], v[minIndex]);
    }
}

int main(){
    fstream myFile;
    myFile.open("in.txt", ios::in);
    int n;
    if(!myFile.is_open()) {
        std::cerr << "Error opening the myFile!" <<endl;
        return 1;
    }
    myFile>>n;
    vector<int> v(n);
    for(int i{0}; i<n; i++)myFile>>v[i];
    myFile.close();
    // for(auto i:v)cout<<i<<" ";
    selectionSort(v, 2);
    
    myFile.open("out.txt", ios::out);
    myFile<<v[0]<<" "<<v[1];
    myFile.close();
    return 0;
}