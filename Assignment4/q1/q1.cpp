#include<iostream>
#include<vector>
using namespace std;
int _count{0};

vector<int> merge(const vector<int>& v1, const vector<int>& v2){
    int p1{(int)(v1.size()-1)}, p2{(int)(v2.size()-1)};
    vector<int> v(v1.size()+v2.size());
    for(int i{(int)(v1.size()+v2.size()-1)}; i>=0; i--){
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

vector<int> mergeSort(vector<int>& v, int low, int high){
    if(low==high)return vector<int>{v[low]};
    int mid = low+(high-low)/2;
    vector<int> v1 = mergeSort(v, low, mid);
    vector<int> v2 = mergeSort(v, mid+1, high);
    return merge(v1, v2);
}

int main(){
    int N;
    cin>>N;
    vector<int> A(N);
    for(int i{0}; i<N; i++)cin>>A[i];
    // vector<int> v1{1,2,3,5,6,7,8};
    // vector<int> v2{1,2,3,10};
    vector<int> out = mergeSort(A, 0, A.size()-1);
    cout<<_count<<endl;
    for(auto i:out)cout<<i<<" ";
    return 0;
}