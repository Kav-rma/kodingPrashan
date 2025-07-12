#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT32_MIN;
        int currSum=0;
        for(auto x : nums){
            currSum += x;
            maxSum = max(currSum, maxSum);
            if(currSum<0){
                currSum = 0;
            }
        }
        return maxSum;
    }
};