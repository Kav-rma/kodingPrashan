#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    int maxSum=INT32_MIN;

    for(int str=0; str<n; str++){
        int sum=0;
        for(int end=str; end<n; end++){
            sum += arr[end];
            maxSum = max(sum, maxSum);
        }
    }
    cout<<"Maximum subarray sum: "<<maxSum<<endl;
    return 0;
}