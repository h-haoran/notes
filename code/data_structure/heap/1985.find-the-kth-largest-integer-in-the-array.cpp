/*
 * @lc app=leetcode id=1985 lang=cpp
 *
 * [1985] Find the Kth Largest Integer in the Array
 */

// @lc code=start
#include <string>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        int n = nums.size()-k + 1;
        priority_queue<pair<int,string>,vector<pair<int,string>>,less<pair<int,string>>> pq;
        for (string s: nums) {
            if (pq.size() < n) {
                pq.push({s.size(), s});
            } else if (pq.top() > make_pair((int)s.size(), s) ) {
               pq.pop();
               pq.push({s.size(), s}); 
            }
        }
        return pq.top().second;
    }
};
// @lc code=end

