### [Find Four Elements That Sums To A Given Value](https://www.codingninjas.com/codestudio/problems/find-four-elements-that-sums-to-a-given-value_8230785?challengeSlug=striver-sde-challenge&leftPanelTab=0)

```cpp
#include <bits/stdc++.h>

string fourSum(vector<int> arr, int target, int n) {
    // Write your code here.
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n; i++){
        int a = arr[i];
        for(int j = i+1; j < n; j++){
            int b = arr[j];
            int twoSumTarget = target - a - b;

            int l = j+1, h = n-1;
            while(l < h){
                int currSum = arr[l] + arr[h];
                if(currSum < twoSumTarget) l++;
                else if(currSum > twoSumTarget) h--;
                else{
                    return "Yes";
                }
            }
        }
    }

    return "No";
    /*
    Time Complexity: O(n^3)
    Space Complexity: O(1)
    */
}

```

### [Four sum (LeetCode)](https://leetcode.com/problems/4sum/description/)

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                long long t_2 = (long long) target - nums[i] - nums[j];
                int front = j+1;
                int end = n-1;

                while(front < end){
                    int two_sum = nums[front] + nums[end];
                    if(two_sum < t_2) front++;
                    else if(two_sum > t_2) end--;
                    else {
                        vector<int> q(4, 0);
                        q[0] = nums[i];
                        q[1] = nums[j];
                        q[2] = nums[front];
                        q[3] = nums[end];
                        ans.push_back(q);
                        //ignoring the elements which has value same as the 3rd value we have taken
                        while(front < end and nums[front] == q[2]) front++;
                        //ignoring the elements which has the value same as the 4th value we have taken
                        while(front < end and nums[end] == q[3]) end--; 
                    }
                }
                while(j+1 < n and nums[j] == nums[j+1]) j++; //ignoring duplicates
            }
            while(i+1 < n and nums[i] == nums[i+1]) i++; //ignoring duplicates
        }
        return ans;
    }
};
```