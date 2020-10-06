#include <iostream>
#include <vector>
using namespace std; 

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for (auto it: nums2) nums1.push_back(it);
        sort(nums1.begin(),nums1.end());
        int siz = nums1.size();
        if (siz % 2) return nums1[siz/2];
        else return (nums1[(siz/2)-1]+nums1[siz/2])/2.0;
    }   
};