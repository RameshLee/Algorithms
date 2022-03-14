class Solution 
{
public:
    int Extractions = 0;
    vector<vector<int>> grid;

    bool isDigged(int i,int j)
    {
        for (int k=0; k<grid[i].size(); k++)
            if (grid[i][k] == j)
                return true;

        return false;
    }
    
    int digArtifacts(int n, vector<vector<int>>& artifacts, vector<vector<int>>& dig) 
    {
        // make dig as adjacency matrix
        grid.resize(n, vector<int>());
        for (auto& it: dig)
            grid[it[0]].push_back(it[1]);

        
        for (auto& it:artifacts)
        {
            // extract start and end point of artifact
            pair<int,int> start = make_pair(it[0],it[1]);
            pair<int,int> end = make_pair(it[2],it[3]);
            
            
            //check whether all points within start to end have been digged!
            int isPossible = 1;
            for (int i=start.first; i<=end.first; i++)
                for (int j=start.second; j<=end.second; j++)
                {
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