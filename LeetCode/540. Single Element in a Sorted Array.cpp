#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int str=0, end=nums.size()-1;
        int mid;
        while(str<=end){
            mid = str + (end-str)/2;
            if(nums.size()==1) return nums[0];
            if(mid==0 && nums[mid]!=nums[mid+1]) return nums[mid];
            if(mid==nums.size()-1 && nums[mid]!=nums[mid-1]) return nums[mid];
            if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]) return nums[mid];
            
            if(mid%2==0){//even no. of elements on both sides.
                if(nums[mid]==nums[mid-1]){
                    end = mid-1;
                }
                else{
                    str = mid+1;
                }
            }
            else{//odd no. of element on both sides.
                if(nums[mid]==nums[mid-1]){
                    str = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return nums[mid];
    }
};