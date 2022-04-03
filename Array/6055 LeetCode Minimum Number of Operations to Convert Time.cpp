// Link: https://leetcode.com/contest/weekly-contest-287/problems/minimum-number-of-operations-to-convert-time/

class Solution {
public:
    int convertTime(string current, string correct) {

        string current_h = current.substr(0,2);
        string current_m = current.substr(3,2);

        string correct_h = correct.substr(0,2);
        string correct_m = correct.substr(3,2);

        int now = (60 * stoi(current_h)) + stoi(current_m);
        int later =  (60 * stoi(correct_h)) + stoi(correct_m);

        int NeedToClock = later-now;

        int steps = 0;
        while (NeedToClock > 0){
            if (NeedToClock >= 60)            NeedToClock -= 60;
            else if (NeedToClock >= 15)       NeedToClock -= 15;
            else if (NeedToClock >= 5)       NeedToClock -= 5;
            else if (NeedToClock >= 1)       NeedToClock -= 1;

            steps++;
        }
        return steps;
    }
};