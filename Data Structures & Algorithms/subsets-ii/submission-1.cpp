class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, subset, res);
        return res;
        
    }
private:
    void dfs(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res) {
        if(i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1, subset, res);

        subset.pop_back();
        while( i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            i++;
        }
        dfs(nums, i + 1, subset, res);
    }
};
