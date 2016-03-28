/**
 * 考虑从小的Ugly数来生成大的Ugly数
 * 除了Ugly数组外，另外维护3个数组，每个数组存放小Ugly分别乘2、3、5所得的数
 * 每次从这3个数组头部取最小的数作为新数加入到Ugly数组中
 */
int nthUglyNumber(int n) {
    vector<int> uglys(n+1);
    vector<int> v2, v3, v5;
    uglys[0]=1;
    int i=0,j2=0,j3=0,j5=0;
    int cur,c2,c3,c5;
    while(i<n){
        cur = uglys[i];
        v2.push_back(cur*2);
        v3.push_back(cur*3);
        v5.push_back(cur*5);
        c2 = v2[j2]; c3 = v3[j3]; c5 = v5[j5];
        if(c2<=c3 && c2<=c5){
            cur = c2; j2++;
            if(c2==c3) j3++;
            if(c2==c5) j5++;
        }else if(c3 <= c2 && c3 <= c5){
            cur = c3; j3++;
            if(c2==c3) j2++;
            if(c3==c5) j5++;
        }else if(c5 <= c2 && c5 <= c3){
            cur = c5; j5++;
            if(c2==c5) j2++;
            if(c3==c5) j3++;
        }
        uglys[++i]=cur;
    }
    return uglys[n-1];
}

/**************************优化****************************************************
 * 由于每次在三个数组中选最小的都是在头部选取的
 * 头部以后的数都是暂时不需要的，实际会有大量冗余
 * 考虑到数组中每一个数都是从原数组中某一个数乘2、3、5得到的
 * 那么只需要记录三个头元素分别是从原数组中的哪个数产生的
 * 即只需原数组的下标即可，无需额外的3个数组
 */
int nthUglyNumber(int n) {
    vector<int> uglys(n+1);
    uglys[0]=1;
    int i=0,p2=0,p3=0,p5=0;
    int cur,v2,v3,v5;
    for(;i<n;) {
        v2=uglys[p2]*2; v3=uglys[p3]*3; v5=uglys[p5]*5;
        cur = min(v2, min(v3,v5));
        uglys[++i] = cur;
        if(cur==v2) p2++;
        if(cur==v3) p3++; //将相等的情况统一考虑，而不是在三者间冗余地比较
        if(cur==v5) p5++;
    }
    return uglys[n-1];
}
