#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

void median(vector<int>& v, int low, int high) {
    int m = (low+high)/2;
    if(v[high]<v[low]) swap(v[low], v[high]);     
    if(v[m]<v[low]) swap(v[m], v[low]);
    if(v[high]<v[m]) swap(v[high], v[m]);
    swap(v[m], v[high-1]);
}

int partition(vector<int>& v, int low, int high) {
    median(v, low, high);
    int x = v[high-1];
    int i = low-1, j = high;
    for(int j{low}; j<high-1; j++) 
        if(v[j] < x) swap(v[++i], v[j]);
    swap(v[i+1], v[high-1]);
    return i+1;
}

void quicksort(vector<int>& v, int low, int high) {
    if(high>low) {
        int p_index = partition(v, low, high);
        quicksort(v, low, p_index-1);
        quicksort(v, p_index+1, high);
    }
}

int main() {
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
    quicksort(v, 0, v.size() - 1); 

    myFile.open("out.txt", ios::out);
    for(auto i:v)myFile<<i<<" ";
    myFile.close();
}