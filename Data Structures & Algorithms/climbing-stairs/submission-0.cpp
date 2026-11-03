class Solution {
public:
    int climbStairs(int n) {
        int one = 1, two = 1; // this is going to be the same every time cause there's only one way of getting to the end for the last two parts of the graph ( ex: 100 and 99...)
        for(int i = 0; i < n - 1; i++) {
            // already zero indexed and then minus 1 so there's really only 3 transitions...
            int temp = one;
            one = one + two;
            two = temp;
        }
    return one;
    }
};