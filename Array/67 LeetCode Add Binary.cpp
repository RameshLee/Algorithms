// Link: https://leetcode.com/problems/add-binary/

// classic summation (100% faster)

class Solution {
public:
    string addBinary(string a, string b) {

        string c; enum numbers{ZERO='0', ONE='1'};

        // make the size of the strings as identical
        int count = abs((int)a.size()-(int)b.size());
        if (a.size() > b.size()) while (count-- > 0) b.insert(b.begin(), ZERO);
        else while (count-- > 0) a.insert(a.begin(), ZERO);

        // perform school book summation
        auto sum = ZERO, carry = ZERO;
        for (int i=a.size()-1; i>=0; i--){
            char A = a[i];
            char B = b[i];

            if (a[i] == ONE && b[i] == ONE && carry == ONE){
                carry = ONE; sum = ONE;
            }
            else if (a[i] == ONE && b[i] == ONE && carry == ZERO){
                 carry = ONE; sum = ZERO;
            }
            else if ( (a[i] == ONE || b[i] == ONE) && carry == ONE){
                 carry = ONE; sum = ZERO;
            }
            else if ( (a[i] == ONE || b[i] == ONE) && carry == ZERO){
                carry = ZERO; sum = ONE;
            }
            else if (a[i] == ZERO && b[i] == ZERO && carry == ONE){
                carry = ZERO; sum = ONE;
            }
            else if (a[i] == ZERO && b[i] == ZERO && carry == ZERO){
                carry = ZERO; sum = ZERO;
            }
            c.insert(c.begin(), sum);
        }
        if (carry == ONE) c.insert(c.begin(), ONE);

        return c;
    }
};