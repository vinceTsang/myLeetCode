/**
 * 判断是否出现环
 * 即判断sum是否重复出现
 * 由于数位的平方最大为81
 * 最大整型范围内的999..99对应的和不会超过81*10
 * 即几步操作后这个sum会在两位数内震荡，偶尔过百再回来
 * 利用数组visit[200]即可，取1000空间换时间
 */
bool isHappy(int n) {
    vector<char> visit(900,0);
    int x, sum;
    while(true){
        sum=0;
        while(n!=0){
            x=n%10;
            n/=10;
            sum+=x*x;
        }
        if(sum==1)
            return true;
        else if(visit[sum]==0) {
            visit[sum]=1;
            n=sum;
        }else{
            return false;
        }
    }
}
