#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <utility>

using std::queue;
using std::unordered_set;
using std::vector;
using std::pair;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> sol(m, vector<int>(n, 0));
        unordered_set<int> locked{};
        unordered_set<int> unlocked{};

        // populate
        for (int i = 0; i < m * n; i++)
        {
            int row = i / n;
            int col = i % n;
            if (isWater[row][col] == 1)
            {
                locked.insert(i);
            }
            else
            {
                unlocked.insert(i);
            }
        }

        while (!unlocked.empty())
        {
            unordered_set<int> toLock{};
            for (int i : unlocked)
            {
                sol[i / n][i % n]++;
                if (isNeighborLocked(i, n, locked))
                {
                    toLock.insert(i);
                }
            }
            for (int i : toLock)
            {
                locked.insert(i);
                unlocked.erase(i);
            }
        }

        return sol;
    }

    vector<vector<int>> efficientHighestPeak(vector<vector<int>> &isWater)
    {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> sol(m, vector<int>(n, 0));
        unordered_set<int> locked{};
        queue<pair<int, int>> queue{};

        for (int i = 0; i < m * n; i++)
        {
            int row = i / n;
            int col = i % n;
            if (isWater[row][col] == 1)
            {
                locked.insert(i);
                queue.push({row, col});
            }
        }

        int x[] = {0, 0, 1, -1};
        int y[] = {1, -1, 0, 0};

        pair<int,int> current;
        while (!queue.empty())
        {
            current = queue.front();
            queue.pop();
            int num = current.first*n + current.second;
            int row = current.first;
            int col = current.second;
            int value = sol[row][col];

            for (int i = 0; i < 4; i++)
            {
                if (row + x[i] < m && col + y[i] < n && row + x[i] >= 0 && col + y[i] >= 0)
                {
                    if (locked.count(num + x[i]*n + y[i]) == 0)
                    {
                        sol[row + x[i]][col + y[i]] = value + 1;
                        locked.insert(num + x[i]*n + y[i]);
                        queue.push({row + x[i], col + y[i]});
                    }
                }
            }    
        }

        return sol;
    }

    bool isNeighborLocked(int pos, int n, unordered_set<int> &locked)
    {
        if (locked.count(pos + n) > 0 || locked.count(pos - n) > 0)
        {
            return true;
        }
        if ((pos % n) + 1 < n && locked.count(pos + 1) > 0)
        {
            return true;
        }
        if ((pos % n) - 1 >= 0 && locked.count(pos - 1) > 0)
        {
            return true;
        }

        return false;
    }
};

void printAnswer(vector<vector<int>> &ans)
{
    for (auto i : ans)
    {
        for (int j : i)
        {
            std::cout << j << " ";
        }
        std::cout << std::endl;
    }
}

int main(int argc, char **argv)
{

    std::cout << "foo" << std::endl;

    Solution sol{};

    vector<vector<int>> test1(2);
    test1[0].push_back(0);
    test1[0].push_back(1);

    test1[1].push_back(0);
    test1[1].push_back(0);

    // vector<vector<int>> s = sol.highestPeak(test1);
    vector<vector<int>> s = sol.efficientHighestPeak(test1);

    printAnswer(s);
    return 0;
}