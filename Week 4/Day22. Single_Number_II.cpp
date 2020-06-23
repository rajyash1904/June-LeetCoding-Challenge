/*

Single Number II

Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Note:

Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

Example 1:

Input: [2,2,3,2]
Output: 3
Example 2:

Input: [0,1,0,1,0,1,99]
Output: 99

*/

class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        int seen_once = 0, seen_twice = 0;
        for (int num: nums) 
        {
            seen_once = ~seen_twice & (seen_once ^ num);
            seen_twice = ~seen_once & (seen_twice ^ num);
        }
        return seen_once;
    }
};