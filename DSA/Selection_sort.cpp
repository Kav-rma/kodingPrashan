#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> selectionSort(vector<int> &arr, int n){
    int maxi = INT32_MIN;
    for(int i=0; i<n; i++){
        int min_index=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        swap(arr[i],arr[min_index]);
    }
    return arr;
}

int main(){
    vector<int> arr = {4,1,5,2,3};
    int n = arr.size();

    for(auto x: selectionSort(arr,n)){
        cout<<x<<" ";
    }

    return 0;
}