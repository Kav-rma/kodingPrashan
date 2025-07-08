//Optimised pair sum apporoch with linear time compleaxity
#include<iostream>
#include<vector>
using namespace std;

vector<int> pairSum(vector<int>& num, int& trgt){
    int i=0, j=num.size()-1;
    vector<int> ans;
    while(i<j){
        int pairSum = num[i]+num[j];
        if(pairSum > trgt){
            j--;
        }
        else if(pairSum < trgt){
            i++;
        }
        else{
            ans.push_back(num[i]);
            ans.push_back(num[j]);
            return ans;
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {2,7,11,15};
    int target = 26;
    for(int x: pairSum(vec,target)){
        cout<<x<<" ";
    }
    return 0;
}