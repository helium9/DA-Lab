#include<iostream>
#include<vector>

using namespace std;

int nth_largest(vector<int> vec, int pass){
    for(int i{0}; i<pass; i++){
        for(int j{0}; j<vec.size()-i-1; j++){
            if(vec[j+1]<vec[j]){
                int temp = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = temp;
            }
        }
    }
    // for(auto i:vec){
    //     cout<<i<<" ";
    // }
    return vec[vec.size()-pass];
}
int main(){
    // vector<int> input={3, 1, 4, 6, 8, 2, 5};
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> input(n);
        for(int i{0}; i<n; i++){
            cin>>input[i];
        }
        // nth_largest(input, 1);
        cout<<nth_largest(input, 1)+nth_largest(input, 2)<<endl;
    }
    return 0;
}