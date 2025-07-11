#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<int> &arr, int n, int m, int max_allowed_pages){//here mid is the maximum allocated pages
    int student = 1, pages=0;
    //O(n)
    for(int i=0; i<n; i++){

        if(arr[i]>max_allowed_pages) return false;//Edge case

        if(pages + arr[i] <= max_allowed_pages){
            pages += arr[i];
        }
        else{
            student++;
            pages = arr[i];
        }
    } 
    return student > m ? false : true;
}


int allocateBooks(vector<int> &arr, int n, int m){
    if(n<m) return -1;

    int sum=0; 
    //O(n)
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    
    int str=0, end=sum;//Range at which the answer exits
    int mid; int ans=-1;
    //O(logN * n)----> where N is the range and n is the total no. of books we have.
    while(str<=end){
        mid = str + (end-str)/2;
        if(isValid(arr, n, m, mid)){//True--> therefore there exit a much smaller value and valid.
            ans = mid;
            end = mid-1;
        }
        else{//Flase--> therefore there don't exit less pages it should be more and invalid.
            str = mid+1;
        }
    }
    return ans;
}


int main(){
    vector<int> arr = {2,1,3,4};
    int n=4, m=2;

    cout<<allocateBooks(arr, n, m)<<endl;
    
    return 0;
}