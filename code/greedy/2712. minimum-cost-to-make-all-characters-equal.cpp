/*
You are given a 0-indexed binary string s of length n on which you can apply two types of operations:

Choose an index i and invert all characters from index 0 to index i (both inclusive), with a cost of i + 1
Choose an index i and invert all characters from index i to index n - 1 (both inclusive), with a cost of n - i
Return the minimum cost to make all characters of the string equal.

Invert a character means if its value is '0' it becomes '1' and vice-versa.
*/

//Greedy: local optimal is the global optimal - subproblem has the same propertiy as the original problem
#include <string>
using namespace std;
class Solution {
public:
    long long minimumCost(string s) {
        long long ans = 0;
        for (int i = 0; i < s.size()-1; i++) {
            if (s[i] != s[i+1]) {
                ans += (i+1 < s.size()-i-1? i+1: s.size()-i-1);
            }
        }
        return ans;
    }
};