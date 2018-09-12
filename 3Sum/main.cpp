class Solution {
public:
    //本题的解法可以推广到四数之和问题中

    vector<vector<int>> threeSum(vector<int>& nums) {
        if(nums.size() < 3){
            vector<vector<int>> retVal;
            return retVal;
        }
        
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i){
            if(i > 0 && nums[i - 1] == nums[i]){
                continue;
            }
            int start = i + 1, end = nums.size() - 1;
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(sum == 0){
                    vector<int> numContainer{nums[i], nums[start], nums[end]};
                    res.insert(numContainer);
                    ++start;
                    --end;
                }else if(sum > 0){
                    --end;
                }else{
                    ++start;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};