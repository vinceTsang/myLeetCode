/**
 * 数组中仅有一个数只出现一次，其余数均出现3次
 * 视各个数均为32位，则对每一位进行统计
 * 对于当前位k，数在k位是1则count++
 * 扫描所有数一遍后k位的count要么是3N要么是3N+1
 * 为后者则表示所求的数在该位为1
 */
int singleNumber(vector<int>& nums) {
    int i,k=0,counts,ans=0,mask=1;
    while(k<32){
        counts=0;
        for(i=0;i<nums.size();i++){
            if(nums[i]&mask) counts++;
        }
        if(counts%3) ans += mask;
        mask <<= 1;
        k++;
    }
    return ans;
}
