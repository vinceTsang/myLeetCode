/**
 * 对于一个二分查找树
 * 记p->val < q->val
 * 若节点x是p和q的最小公共祖先
 * 那么x恰好位于p和q开始分叉的地方
 * 即满足 p->val  <  x->val  <  q->val
 * 无论x再往上移必不再满足
 * 再往下移可能仍满足
 * 故从根往下寻找第一个满足上述条件的节点即可
 * 考虑到一个节点可以将自己称为自己的祖先，故上式可取等号
 */
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
