#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer(nums.size(),1);
    
        int pp=1;
        for(int i=1; i<nums.size(); i++){
            answer[i]=answer[i-1]*nums[i-1];
        }
        
        int sp=1;
        for(int i=nums.size()-2; i>=0; i--){
            sp *= nums[i+1];
            answer[i] *= sp; 
        }
        return answer;
    }
};