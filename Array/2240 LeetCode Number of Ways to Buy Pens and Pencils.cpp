// Link: https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/

class Solution {
public:
    long long waysToBuyPensPencils(int total, int penCost, int pencilCost) {

        printf("pen %d, pencil %d\n", penCost, pencilCost);

        long long ret = 0; int i = 0;
        while(1){
            long long remaining = (long long)(  total - (i * penCost)  );
            long long ways = (long long)(   remaining/pencilCost   );

           // printf("For %d pen, with RC %d buy pencil in %d ways\n", i,remaining, ways);

            if (remaining>=0 && pencilCost>=0) ret += (1 + ways);
            if (remaining < 0) break;

            i++;
        }
        return ret;
    }
};