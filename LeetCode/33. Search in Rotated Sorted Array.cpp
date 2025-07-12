#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int mid;
        int str=0, end=nums.size()-1;

        while(str<=end){
            mid = str + (end-str)/2;
            if(nums[mid]==target){
                return mid;
            }

            //which side sorted loop
            if(nums[str]<=nums[mid]){//left
                if(nums[str]<=target && target<=nums[mid]){
                    end = mid-1;
                }
                else{
                    str = mid+1;
                }
            }
            else{//right
                if(nums[mid]<=target && target<=nums[end]){
                    str = mid+1;
                }
                else{
                    end = mid-1;
                }
            }
        }
        return -1;
        
    }
};