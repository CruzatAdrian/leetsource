#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>

using std::vector;
using std::unordered_set;

class Solution{
public:
        int countServers(vector<vector<int>>& grid) {
        int n = grid[0].size();
        unordered_set<int> talkingbuds{};

        // Check rows
        for (int i = 0; i < grid.size(); i++){
            unordered_set<int> maybes{};
            for (int j = 0; j < grid[i].size(); j++){
                if (grid[i][j] > 0){
                    maybes.insert(n*i + j);
                }
            }
            if (maybes.size() > 1){
                talkingbuds.merge(maybes);
            }
        }

        // Check columns
        for (int i = 0; i < grid[0].size(); i++){
            unordered_set<int> maybes{};
            for (int j = 0; j < grid.size(); j++){
                if (grid[j][i] > 0){
                    maybes.insert(n*j + i);
                }
            }
            if (maybes.size() > 1){
                talkingbuds.merge(maybes);
            }
        }

        return talkingbuds.size();
    }


};


int main(int argc, char** argv){

    Solution sol{};

    vector<vector<int>> test1(2);
    test1[0].push_back(0);
    test1[0].push_back(1);

    test1[1].push_back(1);
    test1[1].push_back(1);


    std::cout << sol.countServers(test1);

    return 0;
}