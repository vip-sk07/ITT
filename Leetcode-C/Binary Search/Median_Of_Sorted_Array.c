#include <stdio.h>
#include <math.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 1e9

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;
    
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (m + n + 1) / 2 - partitionX;
        
        double maxLeftX = (partitionX == 0) ? -INF : nums1[partitionX - 1];
        double minRightX = (partitionX == m) ? INF : nums1[partitionX];
        
        double maxLeftY = (partitionY == 0) ? -INF : nums2[partitionY - 1];
        double minRightY = (partitionY == n) ? INF : nums2[partitionY];
        
        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 1) {
                return MAX(maxLeftX, maxLeftY);
            } else {
                return (MAX(maxLeftX, maxLeftY) + MIN(minRightX, minRightY)) / 2.0;
            }
        } else if (maxLeftX > minRightY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    
    return 0.0;
}
