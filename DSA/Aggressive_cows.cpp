// Farmer John has built a new long barn, with N (2 ≤ N ≤ 100,000) stalls. The stalls are located along a straight line at positions x1 ... xN (0 ≤ xi ≤ 1,000,000,000).
// His C (2 ≤ C ≤ N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?

// Input
// t – the number of test cases, then t test cases follows.
// Line 1: Two space-separated integers: N and C
// Lines 2..N+1: Line i+1 contains an integer stall location, xi

// Output
// For each test case output one integer: the largest minimum distance.

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool isPossible(vector<int> &arr, int n, int c,int minAllowedDistance){
    int cows=1; int currentStallPosition = arr[0];
    for(int i=1; i<n; i++){//O(n)
        if(arr[i]-currentStallPosition >= minAllowedDistance){
            cows++;
            currentStallPosition = arr[i];           
        }
        if(cows == c){
            return true;
        }
    }
    return false;
}

int largestMinimum(vector<int> &arr, int n, int c){
    sort(arr.begin(),arr.end());//O(nLOogn)
    int maxi = arr[n-1] - arr[0];
    int str=1; int end=maxi;//Range
    int ans=-1;

    while(str<=end){//O((LogN)*n)
        int mid = str + (end - str)/2;
        if(isPossible(arr, n, c, mid)){
            ans = mid;
            str = mid+1;
        }
        else{
            end = mid-1;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,4,8,9};
    int n = arr.size(), c=3;

    cout<<largestMinimum(arr, n, c)<<endl;
    return 0;
}
