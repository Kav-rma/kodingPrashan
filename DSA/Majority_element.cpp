#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Brute force O(n^2)
// int majorityElement(vector<int>& nums){
//     int n=nums.size();
//     for(auto x: nums){
//         int freq=0;
//         for(auto y: nums){
//             if(x==y){
//             freq++;
//             }
//         }
//         if(freq>n/2){
//             return x;
//         }
//     }
//     return -1;
// }

//Optimized O(nLogn+n)=O(nLogn)
// int majorityElement(vector<int>& nums){
//     sort(nums.begin(),nums.end());
//     int freq=1, ans=nums[0];
//     for(int i=1; i<nums.size(); i++){
//         if(nums[i-1]=nums[i]){
//             freq++;
//         }
//         else{
//             freq=1;
//             ans = nums[i];
//         }
//         if(freq > nums.size()/2){
//             return ans;
//         }
//     }
//     return -1;
// }

//Moore's Algorithm
int majorityElement(vector<int>& nums){
    for(int i =0; i<nums.size(); i++){
        int freq=0;
        int ans=0;
        
        if(freq == 0){
            ans = nums[i];
        }
        if(ans == nums[i]){
            freq++;
        }
        else{
            freq--;
        }
        return ans;
    }
    
}


//Body
int main(){

    vector<int> vec={1,2,2,1,1,1};
    cout<<majorityElement(vec);

    return 0;
}