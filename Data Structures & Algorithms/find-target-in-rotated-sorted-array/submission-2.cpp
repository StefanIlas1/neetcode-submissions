class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while( l <= r) {
            int m = l + ( r - l)/2;
            if( nums[m] == target) {
                return m;
            }
            //left sorted portion
            if(nums[m] >= nums[l]){ // because we're starting on the left side but obv including it.. 
                if(target > nums[m] || target < nums[l]) {
                    l = m + 1; //spillage case: handles the overflow from the sorted portion into the other sorted portion
                }
                else {
                    r = m - 1;
                }
            }
            else { //if nums[m] < nums[l] --> which means we switched pointers and NOW l is on the other side
                if(target < nums[m] || target > nums[r]){
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }
        }
        return -1;
        
    }
};
