class Solution {
public:
    long long solve(int si, int ei, vector<int>& cuts, vector<vector<int>>& dp){   
        if(si>ei){
            return 0;
        }
        
        if(dp[si][ei] != -1){
            return dp[si][ei];
        }
        
        long long mini = INT_MAX;
        for(long long idx = si; idx<=ei; idx++){
            long long cost = cuts[ei+1] - cuts[si-1] + solve(si, idx-1, cuts, dp) + solve(idx+1, ei, cuts, dp);
            mini = min(mini, cost);
        }
        
        return dp[si][ei] = mini;
    }
    
    int minCost(int n, vector<int>& cuts) {
        long long c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size()+2, vector<int>(cuts.size()+2, -1));
        return solve(1, c, cuts, dp);
    }
};