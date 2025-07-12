#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int mini=prices[0], maxi=0;
       for(int i=1; i<prices.size(); i++){
        if(mini<prices[i]){
            maxi = max(maxi,prices[i]-mini);
        }
        mini = min(mini,prices[i]);
       }
       return maxi;
    }
};
