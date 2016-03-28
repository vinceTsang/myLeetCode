int compareVersion(string version1, string version2) {
    int b1,b2,i=0,j=0;
    while(i<version1.length() || j<version2.length()){ //只要有一个没到末端就继续处理
        b1=0; b2=0;
        while(version1[i]!='.' && i<version1.length()) b1 = b1*10 + version1[i++]-'0';
        while(version2[j]!='.' && j<version2.length()) b2 = b2*10 + version2[j++]-'0';
        if(b1<b2) return -1;
        else if(b1>b2) return 1;
        if(version1[i]=='.') i++;
        if(version2[j]=='.') j++;
    }
    return 0;
}
