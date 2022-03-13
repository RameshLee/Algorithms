#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig)
    {
        int Extractions = 0;
        for (auto& it:artifacts)
        {
            // extract start and end point of artifact
            pair<int,int> start = make_pair(it[0],it[1]);
            pair<int,int> end = make_pair(it[2],it[3]);

            int isPossible = 1;
            for (int i=start.first; i<=end.first; i++)
                for (int j=start.second; j<=end.second; j++){
                   if (!isDigged( i,j )) {
                        isPossible = 0; goto Jump;
                    }
                }
            Jump:
            if (isPossible == 1)
                Extractions++;
        }


        return Extractions;
    }
};

int main()
{
    vector<vector<int>> artifacts = {{0,0,0,0},{0,1,1,1}};
    vector<vector<int>> dig = {{0,0},{0,1}};

    Solution S;
    return 0;
}

