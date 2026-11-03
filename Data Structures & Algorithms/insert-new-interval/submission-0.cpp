class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        addInterval(intervals, newInterval);
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i < intervals.size(); ++i) {
            if(res.empty() || res.back()[1] < intervals[i][0]) {
                res.push_back(intervals[i]);
            }

            else {
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }
        }
        return res;

        //merge intervals function
        //add intervals function
        //this looks like a priority queue
        
    }
private:
    vector<vector<int>> addInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        return intervals;
    }
};
