// Link: https://leetcode.com/problems/keys-and-rooms/

class Solution {
private: int count = 0;
public:
    void dfs(int i, vector<vector<int>>& rooms, vector<int> &visited){
        if (visited[i] == 0){
            visited[i] = 1;
            count++;

            for (auto it:rooms[i])
                dfs(it, rooms, visited);
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), 0);
        dfs(0, rooms, visited);
        return (count == rooms.size()) ? true : false;
    }
};