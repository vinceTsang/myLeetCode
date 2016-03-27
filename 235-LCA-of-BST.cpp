TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL)
        return root;
    if(p==NULL)
        return q;
    else if(q==NULL)
        return p;
    TreeNode* cur = root;
    int small,big;
    if(p->val > q->val){
        small=q->val;
        big=p->val;
    }else{
        small=p->val;
        big=q->val;
    }
    while(true){
        int v=cur->val;
        if(v >= small && v <= big)
            return cur;
        if(v <small)
            cur = cur->right;
        else
            cur = cur->left;
    }
}
