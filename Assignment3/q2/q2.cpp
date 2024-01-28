#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

long long int crossing_sum(vector<long long int>& v, long long int low, long long int mid, long long int high){
    long long int sum_left{LLONG_MIN}, sum_right{LLONG_MIN}, sum{0};
    
    for(long long int i{mid}; i>=low; i--){
        sum+=v[i];
        sum_left=max(sum_left, sum);
    }
    sum=0;
    for(long long int i{mid+1}; i<=high; i++){
        sum+=v[i];
        sum_right=max(sum_right, sum);
    }
    return (sum_left+sum_right);
}

long long int max_subarray(vector<long long int>& v, long long int low, long long int high){
    if(low==high)return v[low];
    else{
        long long int mid = low + (high-low)/2;
        return max({max_subarray(v, low, mid), crossing_sum(v, low, mid, high), max_subarray(v, mid+1, high)});
    }
}

int main(){
    // vector<long long int> v{10, -20, 3, 4, 5, -1, -1, 12, -3, 1};
    // cout<<max_subarray(v, 0, v.size()-1);

    fstream myFile;
    myFile.open("in1.txt", ios::in);
    long long int n;
    if (!myFile.is_open()) {
        std::cerr << "Error opening the myFile!" <<endl;
        return 1;
    }
    myFile>>n;
    vector<long long int> v(n);
    for(long long int i{0}; i<n; i++)myFile>>v[i];
    myFile.close();

    long long int max_sum = max_subarray(v, 0, v.size()-1);

    myFile.open("out1.txt", ios::out);
    myFile<<max_sum;
    myFile.close();
    return 0;
}