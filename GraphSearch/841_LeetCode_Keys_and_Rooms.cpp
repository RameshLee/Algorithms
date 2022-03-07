// Link: https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    int Count;
    void DFS(vector<vector<int>>& rooms, vector<int> &visited, int i)
    {
        if (visited[i] == 0)
        {
            visited[i] = 1;
            Count++;

            for (int j=0; j<rooms[i].size(); j++)
                DFS(rooms, visited, rooms[i][j]);
        }

    }

    bool canVisitAllRooms(vector<vector<int>>& rooms)
    {
        vector<int> visited(rooms.size(), 0);
        DFS(rooms, visited, 0);

        if (Count == rooms.size()) return true;
        else return false;
    }
};