/**
 * 欲求n内所有非负数的二进制表示中1的个数
 * 且用高效的方式，考虑根据已求得的值来推后面的值
 * 分段求解，2-3,4-7,8-15,...,2^k-2^(k+1)-1
 * 可知val[2^k + i] = 1 + val[i], i取[0,2^k-1]之间
 */
vector<int> countBits(int num) {
    vector<int> val(num+1);
    val[0]=0;
    if(num==0) return val;
    val[1]=1;
    int lastIndex=2,i,j;
    while(lastIndex<=num){
        for(i=0,j=lastIndex;i<lastIndex&&j<=num;i++,j++){
            val[j] = val[i]+1;
        }
        lastIndex <<=1;
    }
    return val;
}
