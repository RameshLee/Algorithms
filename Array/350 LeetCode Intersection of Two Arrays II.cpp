// Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        vector<int> vec;
        unordered_map<int,int> Map;
        unordered_map<int,int> Map2;
       
	   // 1) count frequencies
        for (auto& it:nums1) Map[it]++;
        for (auto& it:nums2) Map2[it]++;
        
		// 2) go through the bigger array
        if (nums1.size() < nums2.size()){
            for (auto& it:nums1)
                if (Map2[it] > 0){
                    Map2[it]--; vec.push_back(it);}
        }
        else{
            for (auto& it:nums2)
                if (Map[it] > 0){
                    Map[it]--; vec.push_back(it);}
        }
        
        return vec;
    }
};