class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[x] stores the fewest coins needed to make total x
        //Create a box for every total from 0 through the amount
        //Fill each box with amount + 1, meaning "no solution found yet"
        vector<int> dp(amount + 1, amount + 1);

        dp[0] = 0; //making a total of 0 requires 0 coins
        for(int i = 1; i <= amount; i++) { //solve each total i. starting at 1 and ending in amount
            for(int j = 0; j < coins.size(); j++) {// Try each available coin as the last coin used to make i
                if(coins[j] <= i) { 
                //Using this coin leaves i - coins[j] still to make.
                //dp[ i - coins[j]] already holds the best answer for that smaller total
                // Add 1 to count the coin we're choosing now, keep whichever option uses fewer coins...



                    dp[i] = min(dp[i], 1 + dp[i - coins[j]]);
                    //the dp at that index will then be either the value right now, OR the former coin count + 1 bc you already know the result
                }
            }
        }
        // If the target's box still holds the placeholder, return -1. Otherwise, return the fewest coins needed for the target.
        return dp[amount] > amount ? -1 : dp[amount];
      

        
    }
};
