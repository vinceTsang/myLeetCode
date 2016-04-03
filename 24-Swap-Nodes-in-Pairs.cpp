ListNode* swapPairs(ListNode* head) {
    if(head==NULL) return head;
    ListNode *p=head,*q=head->next,*tmp, *lastSegment;
    if(head->next!=NULL){
        head = head->next;
    }
    else
        return head;
    bool isHead=true;
    while(q!=NULL) {
        tmp = q->next;
        q->next = p;
        p->next = tmp;
        if(!isHead){
            lastSegment->next = q;
        }else{
            isHead=false;
        }
        lastSegment = p;
        p = p->next;
        if(p!=NULL) q=p->next;
        else break;
    }
    return head;
}
