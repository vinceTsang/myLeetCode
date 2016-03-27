const int N = 130;
bool isAnagram(string s, string t) {
    int a[N]={0};
    const char* cs=s.c_str();
    const char* ct=t.c_str();
    int len=s.length();
    if(t.length()!=len) return false;
    for(int i=0;i<len;i++) a[cs[i]-0]++;
    for(int i=0;i<len;i++) a[ct[i]-0]--;
    for(int i=0;i<N;i++) if(a[i]!=0) return false;
    return true;
}
