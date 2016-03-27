int titleToNumber(string s) {
  int k,ans=0;
  for(int i=0;i<s.length();i++){
      k=s[i]-'A'+1;
      ans = 26*ans + k;
  }
  return ans;
}
    
