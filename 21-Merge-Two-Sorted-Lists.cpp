ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    ListNode *a, *t, *p=l1, *q=l2;
    if(l1->val < l2->val){
        a = l1;
        p = p->next;
    }else{
        a = l2;
        q = q->next;
    }
    t = a;
    while(p!=NULL && q!=NULL){
        if(p->val < q->val){
            t->next = p;
            p = p->next;
        }else{
            t->next = q;
            q = q->next;
        }
        t = t->next;
    }
    if(p==NULL) t->next = q;
    else t->next = p;
    return a;
}
