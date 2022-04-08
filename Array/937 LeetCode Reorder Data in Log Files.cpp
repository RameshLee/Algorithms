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
        vector<pair<string,string>> letterLogs; // parse the identifier and content

        for (auto& it:logs){
            int i=0;
            while(it[i] != ' ') i++;

            if (isdigit(it[i+1])) {
                digitLogs.push_back(it);
            }
            else {
                string identifier = it.substr(0,i);
                string content = it.substr(i+1,it.length());

                letterLogs.push_back(make_pair(identifier, content));
            }
        }
        sort(letterLogs.begin(), letterLogs.end(), cmp());

        /*
        // print utility
        printf("digit logs:\n");
        for (auto& it:digitLogs)
            printf("%s %s\n", it.first.c_str(), it.second.c_str());cout<<endl;
        printf("letter logs:\n");
        for (auto& it:letterLogs)
            printf("%s %s\n", it.first.c_str(), it.second.c_str());cout<<endl;*/

        vector<string> ret;
        for (auto& it:letterLogs){
            string s = it.first + " " + it.second;
            ret.push_back(s);
        }
        for (auto& it:digitLogs){
            ret.push_back(it);
        }

        return ret;
    }
};