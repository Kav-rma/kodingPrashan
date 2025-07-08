#include<iostream>
#include<vector>
using namespace std;

//USING ARRAY
// int main(){
//     int arr[4]={2,7,11,15};
//     int target=9;

//     for(int str=0; str<4; str++){
//         for(int sec=str+1; sec<4; sec++){
//             int pairSum=0;
//             pairSum = arr[str]+arr[sec];
//             if(pairSum==target){
//                 cout<<"("<<arr[str]<<","<<arr[sec]<<")";
//                 return 0;
//             }
//         }
//     }
//     return 0;
// }


//USING VECTOR
vector<int> pairSum(vector<int>& vec, int& target){
    vector<int> ans;
    for(int str=0; str<vec.size(); str++){
        for(int sec=str+1; sec<vec.size(); sec++){
            int pairSum=0;
            pairSum = vec.at(str) + vec.at(sec);
            if(pairSum==target){
                ans.push_back(vec.at(str));
                ans.push_back(vec.at(sec));
                return ans;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> vec = {2,7,11,15};
    int target=9;

    for(auto x: pairSum(vec,target)){
        cout<<x<<" ";
    };

    return 0;
}