// Link: https://leetcode.com/problems/search-in-a-sorted-array-of-unknown-size/\

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

// Approach: binary search: T=O(logN), S=O(1)
class Solution {
public:
    int search(const ArrayReader& reader, int target) {

        // binary search
        int l = 0, r = pow(10,4);
        while (l<=r) {
            int i = (l+r)/2;
            if (reader.get(i) == target) return i;
            if (reader.get(i) > target || reader.get(i) == INT_MAX) r = i - 1;
            else l = i + 1;
        }
        return -1;
    }
};