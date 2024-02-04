#include <iostream>
#include <vector>
#include<fstream>

using namespace std;

long double findMedianSortedArrays(const vector<long long int>& nums1, const vector<long long int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    long long int x = nums1.size();
    long long int y = nums2.size();

    long long int low = 0;
    long long int high = x;

    while (low <= high) {
        long long int partitionX = (low + high) / 2;
        long long int partitionY = (x + y + 1) / 2 - partitionX;

        long long int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        long long int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        long long int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        long long int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            } else {
                return max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    return 0;
}

int main() {
    long long int n, m;
    fstream myFile;
    myFile.open("in2.txt", ios::in);
    myFile>>n>>m;
    vector<long long int> nums1(n), nums2(m);
    for(long long int i{0}; i<n; i++)myFile>>nums1[i];
    for(long long int i{0}; i<m; i++)myFile>>nums2[i];
    myFile.close();
    long double median = findMedianSortedArrays(nums1, nums2);
    myFile.open("out2.txt", ios::out);
    myFile << "Median: " << median << endl;
    myFile.close();
    return 0;
}
