class Solution {
public:
    string minWindow(string s, string t) {
        if(t.empty()) { return "";}

        int l = 0;

        pair<int,int> res{-1,-1};
        int resLen = INT_MAX;
        unordered_map<char, int> countT, window;
        for(char c : t) {
            countT[c]++;
        }

        int have = 0, need = countT.size();
        for(int r = 0; r < s.size(); r++) {
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]) {
                have++;
            }

            while(have == need) {
                if(r - l + 1 < resLen) {
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;

                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]) {
                    have--;
                }
                l++;
            }
            
        }
        return resLen == INT_MAX ? "" :
            s.substr(res.first, resLen);


        
    }
};

/*
So the way you want to think of it is. We start with two hashmaps, with the characters as values and the amount of times they appear as the indices.

They also have - attached to them - the need and have --> the windows hashamp as have and the string t's hashmap as have.

You then also have a a resLength that is initalized at infinity, and a res{starting index, end index};

YOu htne filter thorugh the list, if you find a char that fits, you add it to the windows hashmap and then if it's the amount of times it has to come up in the string t, you increment the have number.
--> ONCE the have number equals the need number.
you start popping from the back and moving forward, 
    -> but you ahve to ensure everything is in sync, as in: if you're popping something in t count hashmap it has to decrement the have integer as well. and ONCE the integer have. is less than the integer need, you start itterating through the right side again, until you're full.

    and you keep doing it, until you've gotten to the end of the array,

    go right -> fill have -> pop left until have < need; then update res{first, second} and resLen --> then go right again...

    It's a loop.
*/