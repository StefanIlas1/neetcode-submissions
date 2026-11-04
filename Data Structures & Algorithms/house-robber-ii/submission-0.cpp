class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> num1(nums.begin() + 1, nums.end());
        vector<int> num2(nums.begin(), nums.end() - 1);
        return max(nums[0], max(helper(num1), helper(num2)));
        
    }
private: 
    int helper(vector<int>& nums) {
        int rob1 = 0, rob2 = 0;
        for(int num: nums) {
            int temp = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = temp;
        }
        return rob2;
    }
};
