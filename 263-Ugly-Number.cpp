int reduce(int n,int x){
    while(true){
        if(n%x==0) n /= x;
        else break;
    }
    return n;
}
bool isUgly(int num) {
    if(num==1) return true;
    if(num<1) return false;
    num = reduce(num, 2);
    num = reduce(num, 3);
    num = reduce(num, 5);
    if(num==1) return true;
    return false;
}
