#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void sortColors(vector<int>& nums) {
        int low, mid, high;
        low = 0;
        mid = 0;
        high = nums.size() - 1;

        // Using Dutch National Flag algorithm
        while (low < high) {
            if (nums[mid] == 0) {
                swap(nums[low++], nums[mid++]);
            } else if (nums[mid++] == 1) {
                continue;
            } else {
                swap(nums[mid++], nums[high--]);
            }
        }
    }
};