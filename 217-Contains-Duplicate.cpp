//查看数组是否有重复元素，快排O(nlogn)后，遍历一遍O(n)，看前后元素是否有相同的
bool containsDuplicate(vector<int>& nums) {
    int len=nums.size();
    if(len==0 || len==1)
        return false;
    sort(nums.begin(), nums.begin()+len);
    for(int i=1; i<len; i++){
        if(nums[i-1]==nums[i])
            return true;
    }
    return false;
}
