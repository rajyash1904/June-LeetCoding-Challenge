/*

Find the Duplicate Number

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.

*/


class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
       if(nums.size() <= 1) return -1; // if head or head.next is null -> null
        int slow = nums[0], fast = nums[nums[0]]; //slow = head.next, fast = head.next.next
        while(slow != fast){            //check for loop
            slow = nums[slow];   //slow = head.next
            fast = nums[nums[fast]]; //fast = head.next.next
        }
        slow = 0; //reset one pointer
        while(slow != fast){ //find starting point of loop
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};