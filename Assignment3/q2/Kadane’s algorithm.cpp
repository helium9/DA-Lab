//O(n) algorithm
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

long long int max_subarray(vector<long long int>& v){
    long long int max_sum{INT_MIN}, sum{0};
    for(long long int i{0}; i<v.size(); i++){
        sum+=v[i];
        max_sum=max(max_sum, sum);
        if(sum<0)sum=0;
    }
    return max_sum;
}

int main(){
    // vector<long long int> v{10, -20, 3, 4, 5, -1, -1, 12, -3, 1};
    // cout<<max_subarray(v, 0, v.size()-1);

    fstream myFile;
    myFile.open("in2.txt", ios::in);
    long long int n;
    if (!myFile.is_open()) {
        std::cerr << "Error opening the myFile!" <<endl;
        return 1;
    }
    myFile>>n;
    vector<long long int> v(n);
    for(long long int i{0}; i<n; i++)myFile>>v[i];
    myFile.close();

    long long int max_sum = max_subarray(v);

    myFile.open("out2k.txt", ios::out);
    myFile<<max_sum;
    myFile.close();
    return 0;
}