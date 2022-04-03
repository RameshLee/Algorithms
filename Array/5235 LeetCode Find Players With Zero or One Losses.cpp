// Link: https://leetcode.com/contest/weekly-contest-287/problems/find-players-with-zero-or-one-losses/

// Ans vector-1: Players with no incoming edges. Ans vector-2: Players with only one incoming edge.

class Solution {
public:
    map<int,int> Map;

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {

        vector<vector<int>> ret;
        set<int> players;

        for (auto& it:matches){
            int winner = it[0];
            int loser = it[1];

            players.insert(it[0]);
            Map[winner] += 0;
            Map[loser] += 1; //player,incomingEdge
        }

        vector<int> first,second;
        for (auto it=Map.begin(); it!=Map.end(); it++){
            if (it->second == 0) first.push_back(it->first);
            if (it->second == 1) second.push_back(it->first);
        }

        ret.push_back(first);
        ret.push_back(second);
        return ret;
    }
};