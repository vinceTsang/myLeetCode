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
