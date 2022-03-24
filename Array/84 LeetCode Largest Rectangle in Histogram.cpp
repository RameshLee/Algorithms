// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {

        // 1) aggregate the histogram by combining successive identical pillars
        vector<pair<int,int>> hist;
        hist.push_back(make_pair(arr[0],1));
        for (int i=1; i<arr.size(); i++){
            if (arr[i] == arr[i-1]) hist[hist.size()-1].second++;
            else hist.push_back(make_pair(arr[i],1));
        }

        // 2) for every bar, perform restricted sweep on left and right sied
        int maxHeight=0; int index;
        for (int i=0; i<hist.size(); i++){

            int h=hist[i].first; int w=hist[i].second;

            // sweep left
            index=i; while (--index >= 0){
                if (hist[index].first >= h) w += hist[index].second;
                else break;
            }

            // sweep right
            index=i; while (++index < hist.size()){
                if (hist[index].first >= h) w += hist[index].second;
                else break;
            }

            // record area
            maxHeight = max(maxHeight,w*h);
        }
        return maxHeight;
    }
};