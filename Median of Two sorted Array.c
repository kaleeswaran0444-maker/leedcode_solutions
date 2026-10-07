#include <stdio.h>
#include <math.h>

// Helper macro to find min and max
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    // Ensure nums1 is always the smaller array to keep the binary search space small O(log(min(m, n)))
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int m = nums1Size;
    int n = nums2Size;
    int low = 0, high = m;
    int totalLeft = (m + n + 1) / 2; // Middle index split point

    while (low <= high) {
        int i = low + (high - low) / 2; // Partition index for nums1
        int j = totalLeft - i;          // Partition index for nums2
        
        // Edge cases handled with extreme values if partition cuts off at array boundaries
        int left1 = (i == 0) ? -1e9 : nums1[i - 1];
        int right1 = (i == m) ? 1e9 : nums1[i];
        
        int left2 = (j == 0) ? -1e9 : nums2[j - 1];
        int right2 = (j == n) ? 1e9 : nums2[j];
        
        // Perfect partition found
        if (left1 <= right2 && left2 <= right1) {
            // If total length is odd, median is the max element of the left half
            if ((m + n) % 2 == 1) {
                return MAX(left1, left2);
            }
            // If total length is even, median is average of center boundary elements
            return (MAX(left1, left2) + MIN(right1, right2)) / 2.0;
        }
        // We are too far right in nums1, move left boundary
        else if (left1 > right2) {
            high = i - 1;
        }
        // We are too far left in nums1, move right boundary
        else {
            low = i + 1;
        }
    }
    
    return 0.0;
}
