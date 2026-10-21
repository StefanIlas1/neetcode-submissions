class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int maxB = prices[0];

        for( const auto& sell : prices){
            maxP = max(maxP, sell - maxB);
            maxB = min(sell, maxB);

        }

        return maxP;
        
    }
};
