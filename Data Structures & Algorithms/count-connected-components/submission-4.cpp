class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        int res = n;
        vector<int> par(n), rank(n, 1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
        for(const auto& edge : edges){
            if(Union(par, rank, edge[0], edge[1])) {
                res--;
            }
        }
        return res;
    }
private:
    int Find(vector<int>& par, int n) {
        int p = n;
        while(p != par[p]) {
            par[p] = par[par[p]];
            p = par[p];

        }
        return p;
    }

    bool Union(vector<int>& par, vector<int>& rank, int n1, int n2) {
        int p1 = Find(par, n1);
        int p2 = Find(par, n2);

        if(p1 == p2) {return false;}
        if(rank[p1] < rank[p2]) {
            swap(p1, p2);
        }

        par[p2] = p1;
        rank[p1] += rank[p2];
        return true;

    }
};
