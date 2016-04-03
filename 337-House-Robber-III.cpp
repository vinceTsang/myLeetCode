/**
 * unordered_map记忆化
 * 对每个节点，分两种情况，即两个儿子节点同时取与不去
 * 当前节点能取得的最大值为两儿子节点的最大值和
 * 或者自身加上4个孙子节点之和
 */
unordered_map<TreeNode*, int> tmap;
int rob(TreeNode* root) {
    if(root==NULL) return 0;
    if(tmap.find(root)!=tmap.end()) return tmap[root];
    int ls=0,rs=0;
    if(root->left)
        ls = rob(root->left->left) + rob(root->left->right);
    if(root->right)
        rs = rob(root->right->left) + rob(root->right->right);
    return tmap[root] = max(root->val+ls+rs, rob(root->left)+rob(root->right));
}
