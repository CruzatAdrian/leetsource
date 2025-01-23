#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>


using std::vector;
using std::string;
using std::max;
using std::cout;

class Solution{
public:
 int maxScore(string s) {
        int total = s[0] == '0'? 1:0;
        // Get initial count 
        for (int i = 1; i < s.size(); i++){
            if (s[i] == '1'){
                total++;
            }
        }

        int best = total;

        for (int i = 1; i < s.size() - 1; i++){
            if (s[i] == '1'){
                total--;
            } else {
                total++;
            }
            best = max(best, total);
        }

        return best;
    }

};


int main(int argc, char** argv){

    Solution sol{};

    cout << sol.maxScore("011101") << " == 5"  << std::endl;
    cout << sol.maxScore("00111") << " == 5" << std::endl;
    cout << sol.maxScore("1111") << " == 3" << std::endl;

    return 0;
}