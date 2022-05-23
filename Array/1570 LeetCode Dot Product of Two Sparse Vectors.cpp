// Link: https://leetcode.com/problems/dot-product-of-two-sparse-vectors/

class SparseVector {
public:
    
    SparseVector(vector<int> &nums) {
        for (auto i=0; i<nums.size(); i++)
            if (nums[i] > 0)
                Map[i] = nums[i]; // store non-zero Indices only
    }

    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& S) {
        int sum = 0;
        for (auto it:Map)
            sum += Map[it.first] * S.Map[it.first];
        return sum;
    }
private:
    unordered_map<int,int> Map; // (nonZeroIndices,value)
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);