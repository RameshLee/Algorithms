// Link: https://leetcode.com/problems/reorder-data-in-log-files/

class cmp{
public:
    bool operator()(pair<string,string>& a, pair<string,string>& b){
        return (a.second == b.second) ? a.first < b.first : a.second < b.second;
    }
};

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {

        vector<string> digitLogs;
        vector<pair<string,string>> letterLogs;

        // record the logs
        for (auto s:logs){
            int i=0; while(!isspace(s[i])) i++; // bypass the identifier

            if (isdigit(s[i+1])) {  // record digit logs
                digitLogs.push_back(s);
            }
            else { // record letter logs
                string identifier = s.substr(0,i);
                string content = s.substr(i+1);
                letterLogs.push_back(make_pair(identifier, content));
            }
        }

        // lexicographically sort the letterLogs
        sort(letterLogs.begin(), letterLogs.end(), cmp());

        // extract the result
        vector<string> result;
        for (auto s:letterLogs) result.push_back(s.first + " " + s.second);
        for (auto s:digitLogs)  result.push_back(s);
        return result;
    }
};