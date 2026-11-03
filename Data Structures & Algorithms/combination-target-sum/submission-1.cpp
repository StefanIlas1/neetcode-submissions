class Solution {
    vector<vector<int>> res;
    vector<int> curr;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        dfs(0, curr, 0, nums, target);
        return res;
        
    }
private:
    void dfs(int i, vector<int>& curr, int total, vector<int>& nums, int& target) {
        if(total == target) {
            res.push_back(curr);
            return;
        }

        for(int j = i; j < nums.size(); j++) {
            if(total + nums[j] > target) { return;}
            curr.push_back(nums[j]);
            dfs(j, curr, total + nums[j], nums, target);
            curr.pop_back();
            }


    }
};
