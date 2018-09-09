class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int len1 = A.size(), len2 = B.size(), retVal = 0;
        vector<vector<int>> dp(len1, vector<int>(len2, 0));
        for(int i = 0; i < len1; ++i){
            if(A[i] == B[0]){
                ++dp[i][0];
            }
        }
        for(int i = 1; i < len2; ++i){
            if(A[0] == B[i]){
                ++dp[0][i];
            }
        }
        
        for(int i = 1; i < len1; ++i){
            for(int j = 1; j < len2; ++j){
                if(A[i] == B[j]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    retVal = max(retVal, dp[i][j]);
                }else{
                    continue;
                }
            }
        }
        
        return retVal;
    }
};