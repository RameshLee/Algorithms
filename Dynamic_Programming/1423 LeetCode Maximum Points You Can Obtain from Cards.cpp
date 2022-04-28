// Link: https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/

// 1) brute-force: TLE

/*
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        this->cardPoints = cardPoints;
        return helper(0, cardPoints.size()-1, k);
    }
private:
    vector<int> cardPoints;

    int helper(int start, int end, int k){
        // base-case
        if (k == 0) return 0;
        if (start > end) return 0;

        // recursion
        int option_1 = cardPoints[start] + helper(start+1, end, k-1);
        int option_2 = cardPoints[end] + helper(start, end-1, k-1);
        return max(option_1, option_2);
    }
};
*/

// 2) dynamic programming: (using prefix sum concept)

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int front[k+1], rear[k+1];
        front[0] = 0, rear[0] = 0;

        // calculate prefix sums from front and rear
        for (int i=0; i<k; i++){
            front[i+1] = front[i] + cardPoints[i];
            rear[i+1]  =  rear[i] + cardPoints[cardPoints.size()-1 - i];
        }

        // find result
        int result = 0;
        for (int i=0; i<=k; i++){
            int sum = front[i] + rear[k-i];
            result = max(result, sum);
        }
        return result;
    }
};

// 3) sliding window

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int result = 0, currSum = 0;
        if (k >= cardPoints.size()){
            for (auto e:cardPoints)
                result += e;
            return result;
        }

        // sweep right from the beginning
        int tailIndex;
        for (int i=0; i<k; i++){
            currSum += cardPoints[i];
            result = max(result, currSum);
            tailIndex = i;
        }

        // sweep left from the end while reducing the tail
        int count=0;
        for (int i=cardPoints.size()-1; i>=0; i--){

            currSum += cardPoints[i] - cardPoints[tailIndex--];
            result = max(result, currSum);

            if (++count >= k) break;
        }
        return result;
    }
};