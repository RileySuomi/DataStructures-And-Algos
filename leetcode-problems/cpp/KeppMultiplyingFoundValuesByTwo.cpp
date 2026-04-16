/* 

You are given an array of integers nums. You are also given an integer original which is the first number that needs to be searched for in nums.

You then do the following steps:

If original is found in nums, multiply it by two (i.e., set original = 2 * original).
Otherwise, stop the process.
Repeat this process with the new number as long as you keep finding the number.
Return the final value of original.

*/

/*

Achieved a 0ms runtime. Beats 100% and memory usage of 13.95mb which beats 93.07% (idk if that is all for c++ answers)

*/

/* 
heres a test case :
[8,19,4,2,15,3]

*/

#include <vector>
using namespace std;


/* 
    tricky- bcuz directions werent necessarily clear that the loop restarts everytime original is found. so i switch to a while loop which would either reset or not
*/
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int i = 0;

        while (i != nums.size()) {
            if (nums[i] == original) {
                original *= 2;
                i = 0;
            }else {
                i++;
            }
        }

        return original;
    }
};