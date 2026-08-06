#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Solution {
public:

    pair<int, bool> findRow(vector<vector<int>>& matrix, int target, int col){
        int m = matrix.size();
        int n = matrix[0].size();

        int lowrow = 0; 
        int highrow = m-1;
        int mid;

        while(lowrow<=highrow){
            mid = lowrow + (highrow-lowrow)/2;
            if(matrix[mid][col] == target) return {mid, true};
            if(target < matrix[mid][col]) highrow = mid-1;
            else lowrow = mid+1;
        }
        return {-1, false};
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int end = n-1;
        pair<int, bool> p1;
        while(end>=0){
            if(matrix[0][end] > target){
                end --;
            }
            else{
                p1 = findRow(matrix, target, end);
                if(!p1.second) end--;
                else return p1.second;
            }
        }
        return false;
    }
};