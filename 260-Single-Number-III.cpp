/**
 * 数组中除了两个数a、b以外，各元素均出现两次
 * 欲找出这两个数，只需对所有元素求异或，得到x
 * x实为a和b的异或值，该值代表的是a和b之间所有不相同的位数取1
 * 那么任取当中一位，比如第k位，分别取0和1时要么为a要么为b
 * 故对所有k位为1者取异或得到a或者b中的一个
 * 对其余k位为0者取异或得到另一个
 */
vector<int> singleNumber(vector<int>& nums) {
    int x=0,y=0,i,k,len=nums.size();
    for(i=0;i<len;i++)
        x ^= nums[i];
    k = x&-x; //lowest 1
    x=0;
    for(i=0;i<len;i++){
        if(nums[i]&k)
            x ^= nums[i];
        else
            y ^= nums[i];
    }
    vector<int> res(2);
    res[0]=x; res[1]=y;
    return res;
}
