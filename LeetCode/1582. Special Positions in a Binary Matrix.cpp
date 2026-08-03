#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowcount(m,0);
        vector<int> colcount(n,0);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1){
                    rowcount[i]++;
                    colcount[j]++;
                }
            }
        }

        int ans=0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j]==1 && rowcount[i]==1 && colcount[j]==1) ans++;
            }
        }
        return ans;
    }
};