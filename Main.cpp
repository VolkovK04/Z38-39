class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        bool dp[n+1][m+1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;
        
        for(int i=0; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(p[j-1] == '*'){
                    dp[i][j] = dp[i][j-2] || (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
                }
                else{
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
            }
        }
        
        return dp[n][m];
    }
};

class Solution {
public:

    bool solve(string &s,string &p,int i,int j,vector<vector<int>> &dp){

        if(i<0 && j<0){
            return 1;
        }

        if(i>=0  && j<0) return 0;
     
        
        if(i<0 && j>=0) {
            while(j>=0) {
                if(p[j]!='*') return 0;
                j--;
            }
            return 1;
        };
        if(dp[i][j]!=-1) return dp[i][j];
        if(p[j]==s[i] || p[j]=='?'){
           return dp[i][j]=solve(s,p,i-1,j-1,dp);

        }



        if(p[j]=='*'){
            int t=solve(s,p,i-1,j,dp);
            
            int neglect=solve(s,p,i,j-1,dp);
            return dp[i][j]=t||neglect;
        }
        return dp[i][j]=0;
    }
    bool isMatch(string &s, string &p) {
     
        int n=s.size();
        int m=p.size();
       

        vector<vector<int>> dp(n,vector<int>(m,-1));
       
        return solve(s,p,n-1,m-1,dp);
    }
};
