int findMin(vector<int>& vals) {
    int m=(1<<31)-1;
    for(int i=0;i<vals.size();i++){
        if(vals[i]<m) m = vals[i];
    }
    return m;
}

int nthSuperUglyNumber(int n, vector<int>& primes) {
    int lenP=primes.size();
    vector<int> indexs(lenP,0);
    vector<int> vals(lenP,0);
    vector<int> u(n+1);
    u[0]=1;
    int i,j,cur;
    for(i=0;i<n;){
        for(j=0;j<lenP;j++){
            vals[j] = u[ indexs[j] ] * primes[j]; //vals存储乘法结果，以免再之后的判断中再次做冗余乘法
        }
        cur = findMin(vals);
        u[++i] = cur;
        for(j=0;j<lenP;j++){
            if(cur == vals[j]) indexs[j] += 1;
        }
    }
    return u[n-1];
}
