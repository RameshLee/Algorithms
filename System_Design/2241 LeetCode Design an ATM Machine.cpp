// Link: https://leetcode.com/problems/design-an-atm-machine/

class ATM {
public:
    vector<int> Values = {20,50,100,200,500};
    vector<long long> bankNotes; //20,50,100,200,500

    ATM() {
        for (auto i=0; i<5; i++) bankNotes.push_back(0);
    }

    void deposit(vector<int> banknotesCount) {
        for (auto i=0; i<5; i++) bankNotes[i] += banknotesCount[i];
    }

    vector<int> withdraw(int amount) {

        vector<int> result = {0,0,0,0,0};

        int current = 0, required = amount-current;
        for (auto i=4; i>=0; i--){

            if (required == 0) break;

            // get MaxNotes that we can take from chunk i
            int TakeNotes = required/ Values[i];
            TakeNotes = (bankNotes[i] < TakeNotes) ? bankNotes[i] : TakeNotes;

            // update bankNotes after taking some notes from the chunk i
            if (TakeNotes > 0) {
                current += (TakeNotes * Values[i]);
                required = amount-current;

                result[i] += TakeNotes;
                bankNotes[i] -= TakeNotes;
            }
        }
        // refurbish notes
        if (required > 0) {
            deposit(result);
            return vector<int>({-1});
        }
        return result;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */