
//240 SEarch in 2D marix ||
class Solution {
public:
int n;
bool solve(int i,int j,vector<vector<int>>&mat,int t){
    while(i<n && j>=0){
        if(mat[i][j]==t){
            return true;
            break;
        }
        else if(mat[i][j]<t) i++;
        else if(mat[i][j]>t) j--;
    }
    return false;
}
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       n=matrix.size();
        int m=matrix[0].size();

        bool ans=solve(0,m-1,matrix,target);
        if(ans)
        return true;
        else
        return false;
    }
};