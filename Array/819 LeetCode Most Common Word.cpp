// Link: https://leetcode.com/problems/most-common-word/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {

        // put the banned words into map
        unordered_map<string,int> banMap;
        for (auto& it:banned) banMap[it] = 1;

        // transform all characters to lower case
        transform(paragraph.begin(), paragraph.end(), paragraph.begin(), ::tolower);

        // remove any symbols other than character
        string s;
        for (int i=0; i<paragraph.size(); i++){
            if (std::isalpha(paragraph[i])) s.push_back(paragraph[i]);
            else                            s.push_back(' ');
        }
        paragraph = s;

        // read all words in the paragraph
        unordered_map<string,int> wordMap;
        stringstream line(paragraph); string word;
        while (line >> word) wordMap[word]++;

        // put all the pairs: (string,repetition) into priority queue
        priority_queue<pair<int,string>> pq;
        for (auto it=wordMap.begin(); it!=wordMap.end(); it++)
            pq.push(make_pair((*it).second, (*it).first));

        // find the most repeated non-banned word
        while (!pq.empty()){
            int a=pq.top().first;
            string b=pq.top().second; pq.pop();
            if (banMap.find(b) == banMap.end()) return b;
        }
        return string("");
    }
};