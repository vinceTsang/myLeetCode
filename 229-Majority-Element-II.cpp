bool finalCheck(vector<int>& nums, int x){
    int counts=0, len=nums.size();
    for(int i=0; i<len; i++){
        if(nums.at(i) == x) counts++;
    }
    if(counts>len/3)
        return true;
    return false;
}

vector<int> majorityElement(vector<int>& nums) {
    /** 如果一个元素A的出现的次数k大于数组中总元素的1/3
     * 那么k-1 > n/3 - 1 = (n-3)/3
     * 即同时移除数组中三个互不相同的数，其中元素A最多被移除一个，仍满足
     * 由于最多只有两个元素满足要求
     * 借助两个栈实现，（也可以借助两个数组，大小均为2，一个记录值，一个记录count）
     * (其中用栈实现时空间不完全是O(1)而是接近n而小于n的，若最求严格O(1),则采用两个数组解法，通过累计count取代相同值压栈)
     * 两个栈各自只能存一个值，个数若干，为空则插入新值
     * 当前值与两个栈的栈顶元素都不一样时，两栈都弹栈，表示移除这3个数
     * 否则，压入与自身值相同的一个栈
     * 由于不确保存在两个值均满足，故需要再扫描判断一次
     */
    if(nums.size()==0)
        return nums;
    stack<int> s1,s2;
    vector<int> ans;
    int cur;
    s1.push(nums.at(0));
    for(int i=1; i< nums.size(); i++){
        int cur = nums.at(i);
        if(s1.empty() && s2.empty()){
            s1.push(cur);
        }else if( (!s1.empty() && cur == s1.top()) /*|| s1.empty()*/ ){
            s1.push(cur);
        }else if( (!s2.empty() && cur == s2.top()) || s2.empty() ){
            s2.push(cur);
        }else if(s1.empty()){ //s1单独判断是因为即使s1空，cur仍可能跟s2相等，必须在前面先判断
            s1.push(cur);
        }else{ //此时s1和s2均有值，且cur不等于两者，同时弹栈
            s1.pop(); s2.pop();
        }
    }
    if( !s1.empty() && finalCheck(nums, s1.top()) )
        ans.push_back(s1.top());
    if( !s2.empty() && finalCheck(nums, s2.top()) )
        ans.push_back(s2.top());
    return ans;
}
