#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> insertionSort(vector<int> &arr, int n){
    for(int i=1; i<n; i++){//Rum (n-1) times
        int prev = i-1;
        int curr = arr[i];
        while(prev>=0 && arr[prev]>curr){
            arr[prev+1]=arr[prev];
            prev--;
        }
        arr[prev+1] = curr;
    }
    return arr;
}

vector<int> selectionSort(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i],arr[min_idx]);
    }
    return arr;
}

vector<int> bubbleSort(vector<int> &arr, int n){
    for(int i=0; i<n-1; i++){
        bool isSwap = false;//little optimization but won't effect the time complexity.If in case the input array is already sorted then it will.
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

    for(auto x: insertionSort(arr,n)){
        cout<<x<<" ";
    }

    return 0;
}