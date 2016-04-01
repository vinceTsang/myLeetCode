/**
 * 想要不使用除法，且O(n)时间O(1)空间
 * 将a1*a2*...*ai-1*ai+1*...*an看做两部分
 * 分别是ai之前的元素乘积和ai之后的元素乘积
 * 前者从前累乘，后者从后累乘，各扫描一趟
 */
vector<int> productExceptSelf(vector<int>& nums) {
    int len=nums.size(),i,tmp=1;
    vector<int> val(len,1);
    for(i=1;i<len;i++){
        val[i] = val[i-1]*nums[i-1]; //前面所有元素，而不包含自己
    }
    for(i=len-1;i>=0;i--){
        val[i] = val[i]*tmp;
        tmp *= nums[i];
    }
    return val;
}
