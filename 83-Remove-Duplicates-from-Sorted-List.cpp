ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL)
        return head;
    ListNode *cur=head, *p;
    while(cur!=NULL){
        p=cur->next;
        while(p!=NULL && p->val == cur->val)
            p = p->next;
        cur->next = p;
        cur = p;
    }
    return head;
}
