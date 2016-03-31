/**
 * 链表不知总长，而想要只扫描一遍就删除从尾部数起的第n个数
 * 只需制造两个指针a,b，使得两者的间隔为n，那么两者同时往尾部移动
 * 且b到达尾部NULL时，a到达所要删除元素的前一个。
 */
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* a=head, *b, *cur=head;
    for(int i=0;i<n;i++){
        cur = cur->next;
    }
    if(cur==NULL){ //链表总长为n，此时删头元素
        head = head->next;
        return head;
    }
    b=cur;
    while(b->next!=NULL){
        a = a->next;
        b = b->next;
    }
    a->next = a->next->next;
    return head;
}
