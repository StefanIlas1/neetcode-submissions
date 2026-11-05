class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[n] = true;
        for(int i = s.size() - 1; i >= 0; --i) {
            for(const auto& word : wordDict) {
                if(i + word.size() <= n && s.substr(i, word.size()) == word){
                dp[i] = dp[i + word.size()];

                    if(dp[i]) {
                        break;
                    }
                }

            }
        }
        return dp[0];
        
    }
};
