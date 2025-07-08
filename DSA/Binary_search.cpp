#include<iostream>
#include<vector>
using namespace std;

int binarySearch(vector<int>& arr, int tar){
    int str=0, end=arr.size()-1;
    while(str<=end){
        int mid = (str + end)/2;

        if(tar<arr[mid]){
            end = mid-1;
        }
        else if(tar>arr[mid]){
            str = mid+1;
        }
        else{
            return mid;
        }
    }
    return -1;
}

int main(){
    vector<int> arr1 = {-1, 0, 3, 4, 5, 9, 12};//ODD
    int tar1 = 12;

    vector<int> arr2 = {-1, 0, 3, 5, 9, 12};//EVEN
    int tar2 = 0;

    cout<<binarySearch(arr1, tar1)<<endl;
    cout<<binarySearch(arr2, tar2)<<endl;

    return 0;
}