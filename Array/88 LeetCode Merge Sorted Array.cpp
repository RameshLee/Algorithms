// Link: https://leetcode.com/problems/merge-sorted-array/

// 1) Recursive approach: T=O(m+n)

class Solution {
public:
    void mergeVectors(vector<int>& A, vector<int>& B, int i, int j, int m, int n, vector<int>& vec){
        if (i>=m && j>=n) return;

        if (i>=m)           vec.push_back(B[j]), mergeVectors(A,B,i,j+1,m,n,vec);
        else if (j>=n)      vec.push_back(A[i]), mergeVectors(A,B,i+1,j,m,n,vec);
        else if (A[i]<B[j]) vec.push_back(A[i]), mergeVectors(A,B,i+1,j,m,n,vec);
        else                vec.push_back(B[j]), mergeVectors(A,B,i,j+1,m,n,vec);

    }

    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        vector<int> vec;
        mergeVectors(A,B,0,0,m,n,vec);
        A = vec;
    }
};


// 2) Iterative approach: T=O(m+n)

/*class Solution {
public:
    vector<int> vec;
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=0;
        int j=0;

        while (1){

            if (i>=m && j>=n) break;
            else if (i>=m) {vec.push_back(nums2[j]); j++;}
            else if (j>=n) {vec.push_back(nums1[i]); i++;}
            else if (nums1[i]<nums2[j]) {vec.push_back(nums1[i]); i++;}
            else {vec.push_back(nums2[j]); j++;}

        }

        nums1 = vec;

    }
};*/