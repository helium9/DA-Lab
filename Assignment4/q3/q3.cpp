#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

class Heap{
    public:
    vector<long long int> heap;
    long long int N{0};
    void max_heapify(long long int i){
        long long int left = 2*i+1;
        long long int right = 2*i+2;
        long long int largest{i};
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
    Heap(const vector<long long int>& v){
        this->N=v.size();
        this->heap=v;
        buildHeap();
    }
    void buildHeap(){
        for(long long int i{(N-2)/2}; i>=0; i--){
            max_heapify(i);
        }
    }
    void HeapSort(long long int passes){
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
    long long int N, k;
    fstream myFile;
    myFile.open("in2.txt", ios::in);
    myFile>>N>>k;
    vector<long long int> nums(N);
    for(long long int i{0}; i<N; i++)myFile>>nums[i];
    myFile.close();
    Heap H = Heap(nums);
    H.HeapSort(k);
    myFile.open("out2.txt", ios::out);
    myFile<<H.heap[N-k];
    myFile.close();
    return 0;
}