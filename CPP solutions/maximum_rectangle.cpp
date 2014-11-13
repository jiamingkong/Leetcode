class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int n=matrix.size();
        if(n==0)return 0;
        int m=matrix[0].size();
        if(m==0)return 0;

        vector<int> dp(m,0);
        int maxarea=0;
        for(int i=0;i<n;i++)
        {
            stack<int> s;
            for(int j=0;j<=m;j++)
            {
                if(j<m)
                {
                    if(matrix[i][j]=='1')
                    dp[j]=dp[j]+1;
                    else dp[j]=0;
                }
                while(!s.empty()&&(j==m||dp[s.top()]>dp[j]))
                {
                    int h=dp[s.top()];
                    while(!s.empty()&&dp[s.top()]==h)s.pop();
                    int idx=s.empty()?-1:s.top();
                    if(maxarea<h*(j-idx-1))maxarea=h*(j-idx-1);
                }
                s.push(j);
            }
        }
        return maxarea;
    }
};