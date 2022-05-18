struct WordNode {
    char word[5];
    WordNode *next;

    WordNode(char wrd[5], WordNode* nxt): word(word), next(nxt) {}
};

Assume an API:
bool filter(const char word[5]); // returns true iff word stays in the list

Implement an algorithm that, given a filter removes all words from the linked list that don’t satisfy the filter.
WordNode *prune(WordNode *lst);

WordNode* prune(WordNode *head) {

   WordNode* Sentinel = new WordNode(-99,head);
   WordNode* prev = Sentinel;
   WordNode* curr = head;


   // -99->1->2->3->4->5...NULL
   // remove 5.
   // prev = 4, curr = 5, nxtPtr = nullptr

   // -99->1..NULL
   // remove 1
   // prev = -99, curr = 1, nxtPtr = nullptr

   while (curr) {
        if (!filter(curr->word)) {     // false
             WordNode* nxtPtr = curr->next;
             prev->next = nxtPtr;
             curr = nxtPtr;
        }
        else {
            prev = prev->next;
            curr = curr->next;
        }
   }

   // return the head of the list
   return Sentinel->next;
}

////

unordered_map<string,list<string>::iterator> Map;
list<string> List = {"river", "rover", "range", "blade",....}

void initialize() {
    for (auto curr : List) {
        Map[curr] = iteratorPosition;
    }
}///


void guess(string Word) { // player makes a guess to system
    if (Map.find(Word) != Map.end()) { // guessed word is wrong... // O(1)
        list.erase(Map[Word]); // O(1)
        Map.erase(Word); // O(1)
    }
}
//////////////////////

// dict contains all possible 5 letter words.
// guessing game: system tells you what positions of your letter goes wrong. Then, you can remove all those words from dict.

unordered_map<char,vector<list<string>::iterator>> Map1; // for position 1 // for each character as key, it stores all positions of the words that starts with this char.
// for pos 2,3,4,5 // five maps for each position.

void solve() {
    vector<string> input = {};
    for (auto word : input) {
        for (auto i=0; i<5; i++) {
            auto c = word[i];
            if (!filter(c)) { // false, then remove the words
               // all words starting with char c in pos i
               switch(i) {
                    case 1: vector<list<string>::iterator> vec = Map1[c];
                            for (auto it:vec) dict.erase(it);
                    case 2:
                    ...
                    case 5:
               }
            }
            else { // true, correct guess!
                // erase all the words that has incorrect char at pos i.
            }
        }
    }
}

// How do you improve guesses? try to guess the letter at each pos that occurs most in the dict.


