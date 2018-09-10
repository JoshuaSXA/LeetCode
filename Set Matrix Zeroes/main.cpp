class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      
        bool ifFirstRowContain0 = false, ifCurrentRowContain0 = false;
        
        for(int i = 0; i < matrix[0].size(); ++i){
            if(matrix[0][i] == 0){
                ifFirstRowContain0 = true;
                break;
            }
        }
        
        for(int j = 1; j < matrix.size(); ++j){
            ifCurrentRowContain0 = false;
            for(int i = 0; i < matrix[j].size(); ++i){
                if(matrix[j][i] == 0){
                    ifCurrentRowContain0 = true;
                    matrix[0][i] = 0;
                }
            }
            if(ifCurrentRowContain0){
                for(int i = 0; i < matrix[j].size(); ++i){
                    matrix[j][i] = 0;
                }
            }
        }
        
        for(int i = 0; i < matrix[0].size(); ++i){
            if(matrix[0][i] && ifFirstRowContain0){
                matrix[0][i] = 0;
                continue;
            }else if(matrix[0][i] == 0){
                for(int j = 1; j < matrix.size(); ++j){
                    matrix[j][i] = 0;
                }
            }
        }
        
        return;
    }
};