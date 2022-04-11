// Link: https://leetcode.com/discuss/interview-question/1481915/Amazon-or-OA-or-Count-distinct-characters-in-all-substrings

//Idea : counting the contribution by each alphabet to the answer i.e, If a substring has multiple a's, only '1' is contributed by 'a' to the final count per each substring.

class Solution{
public:
     int solve(char c, string s){ // Counts no.of substrings that contain atleast one of the characters as c.
            int cnt=0,n=s.length(),res=0;
            for(int i=0;i<n;i++){
                if(s[i]==c){
                    res+=(cnt)*(cnt+1)/2;
                    cnt=0;
                }
                else
                    cnt++;
            }
            res+=(cnt)*(cnt+1)/2;
            return n*(n+1)/2 - res;
        }

    int countdistinct(string s) {
        int ans=0;
        for(char c='A';c<='Z';c++)
            ans+=solve(c,s);
        return ans;
    }
};

//
/*
Idea behind solve function: to count all the substrings without atleast one of the characters as c, divide the whole string into segments and count.
Ex: string s:XXAXXXXAAXXAXX (Here X can be any alphabet other than A) ,
Suppose the character you don't want is 'A' : divide the string like this-XX |A| XXXX |AA| XX |A| XX i.e, XX-XXXX-XX-XX, now calculate substrings for each subsegment
take a segment of length 'n', no.of substrings formed by this=n*(n+1)/2. - ( 1 )
Now add for all the sub-segments.
Finally substrings with atleast one A = total substrings( len*(len+1)/2 ) - substrings without atleast one A ( res ).
Further explanation on 1: take any character at an idx 'i' ,no.of substrings that end at 'i' are 'i+1'(zero-based Indexing), now add for all such i's 1+2+3..+n=n*(n+1)/2.
*/