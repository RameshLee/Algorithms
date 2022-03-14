// Link: https://leetcode.com/problems/power-of-two/

// Property: A number n is a power of 2, if the 2's complement of n is itself.
// O(1) space and time complexity

class Solution {
  public:
  bool isPowerOfTwo(int n) {

    if (n == 0) return false;

    long x = n;
    return (x & (-x)) == x;

  }
};