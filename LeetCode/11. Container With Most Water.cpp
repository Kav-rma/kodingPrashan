#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0, right=height.size()-1;
        int l,h;
        int ans = INT32_MIN;
        while(left<right){
            h = min(height[left],height[right]);
            l = right-left;
            ans = max(ans, l*h);

            if(height[left]<height[right]){
                left++;
            }
            else{
                right--;
            }
        }
        return ans;
    }
};