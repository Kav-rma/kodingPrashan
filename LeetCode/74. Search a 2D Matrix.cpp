#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:

    int findRow(vector<vector<int>>& matrix, int target){
        int m = matrix.size();
        int n = matrix[0].size();

        int low_row = 0;
        int high_row = m-1;
        int mid;

        int low_cols = 0;
        int high_cols = n-1;

        while(low_row<=high_row){
            mid = low_row + (high_row - low_row)/2;

            if(matrix[mid][low_cols] <= target && target <= matrix[mid][high_cols]) return mid;
    
            if(target < matrix[mid][0]){
                high_row = mid-1;
            }
            else{
                low_row = mid+1;
            }
        }
        return -1;
    }

    int findCol(vector<vector<int>>& matrix, int target, int row){
        int low_col=0;
        int high_col=matrix[0].size();
        int mid;

        while(low_col <= high_col){

            mid = low_col + (high_col-low_col)/2;

            if(matrix[row][mid] == target) return mid;

            if(target < matrix[row][mid]) high_col = mid-1;
            else low_col = mid+1;
        }
        return -1;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row;
        int col;

        row = findRow(matrix, target);
        if(row == -1) return false;
        col = findCol(matrix, target, row);

        if(col!=-1 && matrix[row][col]==target) return true;
        else return false;
    }
};