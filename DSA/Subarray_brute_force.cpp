#include<iostream>
using namespace std;

int main(){
    int arr[]={1,2,3,4,5};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int str=0; str<n; str++){
        for(int end=str; end<n; end++){
            for(int k=str; k<=end; k++){
                cout<<arr[k]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}