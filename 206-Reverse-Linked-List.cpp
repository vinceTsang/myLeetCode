//用栈迭代实现
ListNode* reverseList(ListNode* head) {
    if(head==NULL)
        return head;
    ListNode* cur = head->next;
    stack<ListNode*> s;
    s.push(head);
    while(cur!=NULL){
        s.push(cur);
        cur=cur->next;
    }
    cur = s.top(); s.pop();
    head = cur;
    head->next=NULL;
    while(!s.empty()){
        cur->next = s.top();
        cur = cur->next;
        s.pop();
    }
    cur->next=NULL;
    return head;
}
