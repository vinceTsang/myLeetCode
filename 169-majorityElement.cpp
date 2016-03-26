//#include <vector>
//#include <stack>
int majorityElement(vector<int>& nums) {
    /**
     * 如果一个元素A的出现的次数k大于数组中总元素的一半n/2
     * 那么k-1 > n/2 - 1 = (n-2)/2
     * 即同时移除数组中两个不同的数，其中元素A最多被移除一个，仍为大多数
     * 借助栈高效实现，初始压入一个元素，随后每次拿当前元素跟栈顶元素比较
     * 相同则继续压栈，不同则弹栈，表示移除这两个数
     * 由于保证有唯一解，最后栈顶元素即所求
     * （否则，如果题目不保证有解，只需看是否空栈或者对栈顶元素再进行一次扫描判断即可）
     */
    stack<int> s;
    s.push(nums.at(0));
    for(int i=1; i< nums.size(); i++){
        if( s.empty() || s.top() == nums.at(i) )
            s.push(nums.at(i));
        else
            s.pop();
    }
    return s.top();
}
