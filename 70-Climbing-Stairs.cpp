/**
 * 考虑递归时，第一步走1阶后，剩n-1阶，第一步走2阶，剩n-2阶
 * 即f(n) = f(n-1) + f(n-2)
 * 也即斐波那契，可迭代实现
 */
int climbStairs(int n) {
    int a=1,b=1,ans=0;
    if(n==0 || n==1) return 1;
    for(int i=2; i<n+1; i++){
        ans = a+b;
        a=b; b=ans;
    }
    return ans;
}
