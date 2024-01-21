#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

void merge(vector<int>& v, int low, int mid, int high){
    for(int i{mid-low}; i<high-low+1; i++){
        int j{0};
        while(i-j-1>=0 && v[low+i-j]<v[low+i-j-1]){
            int temp = v[low+i-j-1];
            v[low+i-j-1]=v[low+i-j];
            v[low+i-j]=temp;
            j++;
        }
    }
}

void mergeSort(vector<int>& v, int low, int high){
    if(high==low)return;
    mergeSort(v, low, low+(high-low)/2);
    mergeSort(v, low+(high-low)/2+1, high);
    merge(v, low, low+(high-low)/2+1, high);
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
    // vector<int> v{3,5,2, 5, 8, 11, 1, 23};
    mergeSort(v, 0, v.size()-1);
    double median = (v.size()%2==0)?((double)(v[v.size()/2]+v[v.size()/2-1])/2.0):v[v.size()/2];
    myFile.open("out.txt", ios::out);
    myFile<<median;
    myFile.close();
    return 0;
}