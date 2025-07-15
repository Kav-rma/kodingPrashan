#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> bubbleSort(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        bool isSwap = false;//little optimization but won't effect the time complexity. In case the input array is already sorted then it will.
        for(int j=0; j<n-1-i; j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSwap = true;
            }
        }
        if(!isSwap){//That means array is already sorted.
            return arr;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {4,1,5,2,3};
    int n = arr.size();

    for(auto x: bubbleSort(arr,n)){
        cout<<x<<" ";
    }

    return 0;
}