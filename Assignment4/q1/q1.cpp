#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
long long int _count{0};

vector<long long int> merge(const vector<long long int>& v1, const vector<long long int>& v2){
    long long int p1{(long long int)(v1.size()-1)}, p2{(long long int)(v2.size()-1)};
    vector<long long int> v(v1.size()+v2.size());
    for(long long int i{(long long int)(v1.size()+v2.size()-1)}; i>=0; i--){
        if(p1>=0 && p2>=0){
            if(v1[p1]>v2[p2]){
                v[i]=v1[p1];
                _count+=p2+1;
                p1--;
            }
            else{
                v[i]=v2[p2];
                p2--;
            }
        }
        else{
            if(p2<0){
                v[i]=v1[p1];
                p1--;
            }
            else if(p1<0){
                v[i]=v2[p2];
                p2--;
            }
        }
    }
    return v;
}

vector<long long int> mergeSort(vector<long long int>& v, long long int low, long long int high){
    if(low==high)return vector<long long int>{v[low]};
    long long int mid = low+(high-low)/2;
    vector<long long int> v1 = mergeSort(v, low, mid);
    vector<long long int> v2 = mergeSort(v, mid+1, high);
    return merge(v1, v2);
}

int main(){
    fstream myFile;
    myFile.open("in2.txt", ios::in);
    long long int N;
    if (!myFile.is_open()) {
        std::cerr << "Error opening the myFile!" <<endl;
        return 1;
    }
    myFile>>N;
    vector<long long int> A(N);
    for(long long int i{0}; i<N; i++)myFile>>A[i];
    // vector<long long int> v1{1,2,3,5,6,7,8};
    // vector<long long int> v2{1,2,3,10};
    myFile.close();
    vector<long long int> out = mergeSort(A, 0, A.size()-1);
    myFile.open("out2.txt", ios::out);
    myFile<<_count;
    myFile.close();
    // for(auto i:out)cout<<i<<" ";
    return 0;
}