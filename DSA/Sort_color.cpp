//SORT ARRAY WWITH 0'S, 1'S, 2'S.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//Optimized approch
vector<int> sortArray(vector<int> &arr){
    int c_zero=0, c_one=0, c_two=0;
    //first we take the count of the numbers.
    for(int i=0; i<arr.size(); i++){//O(n)
        if(arr[i]==0) c_zero++;
        
        else if(arr[i]==1) c_one++;
        
        else c_two++;
    }

    //Now we overwrite
    int idx=0;
    for(int i=0; i<c_zero; i++){//O{n}
        arr[idx++]=0;
    }
    for(int i=0; i<c_one; i++){//O(n)
        arr[idx++]=1;
    }
    for(int i=0; i<c_two; i++){//O(n)
        arr[idx++]=2;
    }
    return arr;
}

//Dutch National Flag Algorith
vector<int> sortColors(vector<int> &arr){
    int low=0, mid=0, high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid]==1){
            mid++;
        }
        else{
            swap(arr[high],arr[mid]);
            high--;
        }
    }
    return arr;
}

int main(){
    vector<int> arr = {2,0,2,1,1,0,1,2,0,0};
    //sort(arr.begin(),arr.end());  this is O(nlogn),O(1).
    for(auto x : sortColors(arr)){
        cout<<x<<" ";
    }
    return 0;
}