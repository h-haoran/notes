/*
 * @lc app=leetcode id=496 lang=cpp
 *
 * [496] Next Greater Element I
 */

// @lc code=start
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        // mono stack
        unordered_map<int, int> m;
        vector<int> rtn;
        stack<int> s;
        for (int i = 0; i < nums2.size(); i++) {
            while (!s.empty() && nums2[i] > nums2[s.top()]) {
                m[nums2[s.top()]] = nums2[i];
                s.pop();
            }
            s.push(i);
        }
        for (int n: nums1) {
            rtn.push_back(m.count(n)?m[n]:-1);
        }
        return rtn;
    }
};
// @lc code=end

