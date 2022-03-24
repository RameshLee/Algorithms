// Link: https://leetcode.com/problems/decrypt-string-from-alphabet-to-integer-mapping/

class Solution {
public:
    unordered_map<string,char> Map = {
        {"1",'a'},
        {"2",'b'},
        {"3",'c'},
        {"4",'d'},
        {"5",'e'},
        {"6",'f'},
        {"7",'g'},
        {"8",'h'},
        {"9",'i'},
        {"10",'j'},
        {"11",'k'},
        {"12",'l'},
        {"13",'m'},
        {"14",'n'},
        {"15",'o'},
        {"16",'p'},
        {"17",'q'},
        {"18",'r'},
        {"19",'s'},
        {"20",'t'},
        {"21",'u'},
        {"22",'v'},
        {"23",'w'},
        {"24",'x'},
        {"25",'y'},
        {"26",'z'},
    };

    string freqAlphabets(string s) {

        string res, A; int i = 0;
        while(i<s.size()){
            if (i+2 < s.size() && s[i+2] == '#'){
                A = {s[i],s[i+1]}, i += 3;
            }
            else{
                 A = {s[i]}, i += 1;
            }
            res.push_back(Map[A]);
        }
        return res;
    }
};