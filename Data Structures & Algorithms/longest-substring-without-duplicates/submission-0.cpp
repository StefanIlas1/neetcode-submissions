class Solution {
    // the way this works is that we have to itterate through this string, find the longest string without one of these chars being repeated, then return that longest string

    // This is done by:
    //Storing the characters within a hashSet, ensuring that we have a basis to compare to
    //Cycling through the string, comparing as we go along...
        //This "cycling" is done with two pointers, sectioning out parts of the string with no repeats and then resetting once there's a repeat bringing us back to the sliding window type of question.. 
    // And storing the longest string length thus far as an integer
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, res = 0;
        unordered_map<char, int> mp;

        for(int r = 0; r < s.size(); r++){
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1, l);
                //this function is how we itterate through if there's a repeat.. that is if there's a repeat, we move l to the end of the string, hence starting a new window
                // so what's this comparison?? -> you just move one over the last repeat, or you stay where you are... the max ensures we don't move bckwd.
            }
            mp[s[r]] = r; // here we're updating the hashSet otherwise
            res = max(res, r - l + 1);
        }
        return res;
        
    }
};
