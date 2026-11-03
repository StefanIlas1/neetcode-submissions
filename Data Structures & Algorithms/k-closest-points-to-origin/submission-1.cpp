class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [] (const auto& a, const auto& b) {
            return (pow(a[0],2) + pow(a[1], 2)) < (pow(b[0],2) + pow(b[1], 2));
        });

        return vector<vector<int>> (points.begin(), points.begin() + k);
        
    }
};
