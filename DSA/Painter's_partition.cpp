// Given are N boards of length of each given in the form of array, and M painters, such that each painter takes 1 unit of time to paint 1 unit of the board.The task is to find the minimum time to paint all boards under the constraints that any painter will only paint continuous sections of boards

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int maxAllowedTime){
    int painter = 1; int time = 0;
    for(int i=0; i<n; i++){
        if(arr[i]>maxAllowedTime) return false;
        if(time + arr[i] <= maxAllowedTime){
            time += arr[i];
        }
        else{
            painter++;
            time = arr[i];
        }
    }
    return painter > m ? false : true;
}

int minimumTime(vector<int> &arr, int n, int m){
    
    int sum=0; int maxValue=INT32_MIN;
    for(int i=0; i<n; i++){
        sum += arr[i];
        maxValue = max(maxValue,arr[i]);
    }
    
    int ans = INT32_MIN;
    int str=maxValue; int end=sum;
    while(str<=end){
        int mid = str + (end-str)/2;
        if(isValid(arr, n, m, mid)){
            ans = mid;
            end = mid-1;
        }
        else{
            str = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr={10,10,10,10};
    int n=arr.size(); int m=2;

    cout<<minimumTime(arr, n, m)<<endl;
    return 0;
}