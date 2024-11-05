
#include <iostream>
#include <vector>

using namespace std;

/*
THIS SOLUTION BEATS 100% OF SUBMISSIONS!!!
Meaning the runtime is top tier!! It achieved 0ms during tests
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
            for (int i = 0; i < nums.size()-1; ++i) {
                if (target <= nums[i+1] && target > nums[i]) {
                    return i+1;
                }
            }
        if (target <= nums.front()) {
            return 0;
        }
        else{
            return nums.size();
        }
        
    }
};