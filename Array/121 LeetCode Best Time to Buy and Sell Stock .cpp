// Link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    int maxProfit(vector<int>& buyPrice) {

        int result = 0; int sellPrice = 0;
        for (int i=buyPrice.size()-1; i>=1; i--){
            sellPrice = max(sellPrice, buyPrice[i]);
            result = max(result, sellPrice-buyPrice[i-1]);
        }
        return result;
    }
};