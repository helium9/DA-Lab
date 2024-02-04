#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    vector<int> heap;
    int N{0};
    void max_heapify(int i){
        int left = 2*i+1;
        int right = 2*i+2;
        int largest{i};
        if(left<N && heap[left]>heap[i]){
            largest=left;
        }
        if(right<N && heap[right]>heap[largest]){
            largest=right;
        }
        if(largest!=i){
            swap(heap[i], heap[largest]);
            max_heapify(largest);
        }
    }
    Heap(const vector<int>& v){
        this->N=v.size();
        this->heap=v;
        buildHeap();
    }
    void buildHeap(){
        for(int i{(N-2)/2}; i>=0; i--){
            max_heapify(i);
        }
    }
    void HeapSort(int passes){
        buildHeap();
        if(passes<=N)
        while(passes--){
            swap(heap[0], heap[N-1]);
            N--;
            max_heapify(0);
        }
        N=heap.size();
    }
};
int main(){
    int N, k;
    cin>>N>>k;
    vector<int> nums(N);
    for(int i{0}; i<N; i++)cin>>nums[i];
    Heap H = Heap(nums);
    H.HeapSort(k);
    cout<<H.heap[N-k]; 
    return 0;
}