/**
 * dp
 * 从头部扫描，dp[i]表示i及此前的所有财产和的最大值
 * dp[i] = max(dp[i-1], nums[i)]+dp[i-2])
 * 表示当前值或者不选去，或者选取
 * 当房子围成了一圈，头尾相接
 * 分两种情况，第一个房子取或者不取
 * 取的时候，dp至倒数第二个房子
 * 不取的时候，dp至最后一个房子
 * 最后求两种情况最大值
 */
int rob(vector<int>& nums) {
    int len = nums.size(),i,MAX;
    if(len==0) return 0;
    if(len==1) return nums[0];
    vector<int> dp(len+1,0);
    //取第一个房子
    dp[1]=nums[0];
    for(i=2;i<len;i++){
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]); //dp的实际下标从1起，nums的下标从0起
    }
    MAX = dp[len-1];
    dp[1]=0;
    for(i=2;i<len+1;i++)
        dp[i] = max(dp[i-1], dp[i-2]+nums[i-1]);
    MAX = max(MAX,dp[len]);
    return MAX;
}
