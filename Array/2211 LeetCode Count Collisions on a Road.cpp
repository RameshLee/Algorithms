// Link: https://leetcode.com/contest/weekly-contest-285/problems/count-collisions-on-a-road/

class Solution {
public:
    enum Movement{Stop='S', Right='R', Left = 'L'};
    int countCollisions(string directions) {

        int n = directions.size();
        int collisions = 0;

        // 1) from begin to end
            for (int i=0; i<n; i++){
                if (directions[i] == Right){
                    if ((i+1)<n){
                        if (directions[i+1] == Left){
                        collisions += 2;
                        directions[i] = Stop;
                        directions[i+1] = Stop;
                        }
                        else if (directions[i+1] == Stop){
                        collisions += 1;
                        directions[i] = Stop;
                        directions[i+1] = Stop;
                        }
                    }
                }
                else if (directions[i] == Left){
                    if ((i-1)>=0){
                        if (directions[i-1] == Right){
                        collisions += 2;
                        directions[i] = Stop;
                        directions[i-1] = Stop;
                        }
                        else if (directions[i-1] == Stop){
                            collisions += 1;
                            directions[i] = Stop;
                            directions[i-1] = Stop;
                        }
                    }
                }
                //printf("collisions: %d ", collisions); for(auto& it:directions) printf("%c",it);cout<<endl;
            }

        // 2) from end to begin
            for (int i=n-1; i>=0; i--){
                if (directions[i] == Right){
                    if ((i+1)<n){
                        if (directions[i+1] == Left){
                        collisions += 2;
                        directions[i] = Stop;
                        directions[i+1] = Stop;
                        }
                        else if (directions[i+1] == Stop){
                        collisions += 1;
                        directions[i] = Stop;
                        directions[i+1] = Stop;
                        }
                    }
                }
                else if (directions[i] == Left){
                    if ((i-1)>=0){
                        if (directions[i-1] == Right){
                        collisions += 2;
                        directions[i] = Stop;
                        directions[i-1] = Stop;
                        }
                        else if (directions[i-1] == Stop){
                            collisions += 1;
                            directions[i] = Stop;
                            directions[i-1] = Stop;
                        }
                    }
                }
                //printf("collisions: %d ", collisions); for(auto& it:directions) printf("%c",it);cout<<endl;
            }

        return collisions;
    }
};