class Solution:
    def findMedianSortedArrays(self, nums1: List[int], nums2: List[int]) -> float:
        for i in range(len(nums2)):
            nums1.append(nums2[i])
        size = len(nums1)
        nums1.sort()
        if size % 2 == 1:
            return nums1[size//2]
        else:
            return (nums1[size//2 - 1] + nums1[size//2])/2
