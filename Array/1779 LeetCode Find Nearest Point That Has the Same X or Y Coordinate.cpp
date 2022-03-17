// Link: https://leetcode.com/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/

class Solution {
public:
    int manhattan_distance(int x1, int y1, int x2, int y2){
        return abs(x1-x2)+abs(y1-y2);
    }

    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {

        int MinDist = INT_MAX;
        int smallestIndex;
        for (int i=0; i<points.size(); i++){
            if (x==points[i][0] || y==points[i][1]){
                int NewDist = manhattan_distance( x,y,points[i][0],points[i][1] );
                if (NewDist < MinDist){
                    MinDist = NewDist;
                    smallestIndex = i;
                }
            }
        }
        return (MinDist==INT_MAX)?-1:smallestIndex;
    }
};