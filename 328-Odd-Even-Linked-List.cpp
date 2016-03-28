/**
 * 保存head2和tail2，作为odd链的头和尾
 * 每次将原链的odd位置元素加入tail2，原链位置后移
 */
ListNode* oddEvenList(ListNode* head) {
     if(head==NULL || head->next==NULL || head->next->next==NULL)
        return head;
     ListNode *cur, *tail2, *h2=head->next;
     tail2 = h2;
     cur = h2->next; //原链的当前位置
     head->next = cur;
     while(cur->next != NULL){
        tail2->next = cur->next;
        tail2=tail2->next; //tail2指向2链当前非空的偶数位元素
        if(tail2->next==NULL)
            break;
        cur->next = cur->next->next;
        cur=cur->next; //cur指向原链当前非空的奇数位元素
     }
     cur->next=h2;
     tail2->next=NULL;
     return head;
}
