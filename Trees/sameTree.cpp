#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    // Base case 1: both null -> same
    if (p == nullptr && q == nullptr) return true;

    // Base case 2: exactly one is null -> different
    if (p == nullptr || q == nullptr) return false;

    // Both exist: check value + recurse on both subtrees
    if (p->val != q->val) return false;

    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main() {
    // Tree 1:    1
    //           / \
    //          2   3
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    // Tree 2:    1
    //           / \
    //          2   3
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    if (isSameTree(p, q))
        cout << "Same Tree" << endl;
    else
        cout << "Not Same Tree" << endl;
    return 0;
}
