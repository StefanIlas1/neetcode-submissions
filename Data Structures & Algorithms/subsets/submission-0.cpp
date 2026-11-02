class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        dfs(nums, 0, res, subset);
        return res;
        
    }
private:
    void dfs(vector<int>& nums, int i, vector<vector<int>>& res, vector<int>& subset) {
        if( i >= nums.size()) {
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        dfs(nums, i + 1, res, subset);

        subset.pop_back();
        dfs(nums, i + 1, res, subset);

    }
};
