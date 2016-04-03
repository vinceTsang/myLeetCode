/**
 * dp
 * 从头部扫描，dp[i]表示i及此前的所有财产和的最大值
 * dp[i] = max(dp[i-1], nums[i)]+dp[i-2])
 * 表示当前值或者不选去，或者选取
 */
int rob(vector<int>& nums) {
    int len = nums.size(),i;
    if(len==0) return 0;
    vector<int> dp(len+1,0);
    dp[1]=nums[0];
    for(i=2;i<len+1;i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]); //dp的实际下标从1起，nums的下标从0起
    }
    return dp[len];
}
