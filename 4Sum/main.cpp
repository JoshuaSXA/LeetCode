class Solution {
public:
/*
    // This is an original version which cost about 1616ms to pass all the test dataset.
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int len = nums.size();
        if(len <= 4){
            //debugger
        }
        quickSort(nums, 0, len - 1);
        set<vector<int>> res;
        vector<int> numContainer;
        dfs(nums, numContainer, res, 0, target);
        return vector<vector<int>>(res.begin(), res.end());
    }
    
    void quickSort(vector<int>& nums, int start, int end){
        if(start < end){
            int i = start, j = end, store = nums[start];
            while(i < j){
                while(i < j && nums[j] >= store){
                    --j;
                }
                if(i < j){
                    nums[i] = nums[j];
                }
                while(i < j && nums[i] < store){
                    ++i;
                }
                if(i < j){
                    nums[j] = nums[i];
                }
            }
            nums[i] = store;
            quickSort(nums, i + 1, end);
            quickSort(nums, start, i - 1);
        }
    }
    
    void dfs(vector<int>& nums, vector<int>& numContainer, set<vector<int>>& res, int index, int& target){
        
        if(numContainer.size() == 4){
            if(sum(numContainer) == target){
                /*
                for(int i = res.size() - 1; i >= 0; --i){
                    int j;
                    for(j = 0; j < 4 && numContainer[j] == res[i][j]; ++j);
                    if(j == 4){
                        return;
                    }
                }
                res.push_back(numContainer);

                if(res.find(numContainer) == res.end()){
                    res.insert(numContainer);
                }
            }
            return;
        }
        
        if(index == nums.size()){
            return;
        }
        
        dfs(nums, numContainer, res, index + 1, target);
        
        numContainer.push_back(nums[index]);
        
        
        dfs(nums, numContainer, res, index + 1, target);
        numContainer.pop_back();
        
        return;
    }
    
    int sum(vector<int>& numContainer){
        int sum = 0;
        for(int i = 0; i < numContainer.size(); ++i){
            sum += numContainer[i];
        }
        return sum;
    }
*/

    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) {
            for (int j = i + 1; j < int(nums.size() - 2); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};