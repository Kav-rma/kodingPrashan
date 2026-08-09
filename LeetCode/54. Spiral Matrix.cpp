#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int srow = 0; 
        int erow = matrix.size()-1;
        int scol = 0;
        int ecol = matrix[0].size()-1;
        vector<int> ans;

        while(srow<=erow && scol<=ecol){
            //right
            for(int i=scol; i<=ecol; i++){
                ans.push_back(matrix[srow][i]);
            }

            //down
            for(int i=srow+1; i<=erow; i++){
                ans.push_back(matrix[i][ecol]);
            }

            //left
            if(srow < erow){
                for(int i=ecol-1; i>=scol; i--){
                    ans.push_back(matrix[erow][i]);
                }
            }

            //up
            if(scol < ecol){
                for(int i=erow-1; i>srow; i--){
                    ans.push_back(matrix[i][scol]);
                }
            }

            srow++; ecol--; erow--; scol++;
        }
        return ans;
    }
};