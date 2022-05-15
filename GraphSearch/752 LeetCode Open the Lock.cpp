// Link: https://leetcode.com/problems/open-the-lock/

// Approach: BFS to find shortest path from source to destination

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadSet(deadends.begin(), deadends.end());
        if (deadSet.find("0000") != deadSet.end()) return -1;
        queue<string> q; q.push("0000");
        int breadth = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) { // level-order-traversal/BFS
                auto code = q.front(); q.pop();
                if (code == target) return breadth;

                // rotate each button on clockwise/counterclockwise directions
                for (auto neighbor : getNeighbors(code)) {
                    if (deadSet.find(neighbor) == deadSet.end()) {
                        q.push(neighbor);
                        deadSet.insert(neighbor);
                    }
                }
            }
            breadth++;
        }
        return -1;
    }
private:
    vector<string> getNeighbors(string code) {
        vector<string> result;
        for (int k=0; k<4; k++) {
            for (int diff = -1; diff <= 1; diff += 2) {
                string neighbor = code; // get the code

                int Integer = neighbor[k] - '0';  // convert character to integer
                Integer = (Integer+10 + diff) % 10; // rotate clockwise/antiClockwise
                char Character = Integer + '0'; // convert integer to character

                neighbor[k] = Character; // roll the digit
                result.push_back(neighbor); // append neighbor
            }
        }
        return result;
    }
};