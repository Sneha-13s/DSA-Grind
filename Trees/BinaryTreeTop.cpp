#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
// Insert into a Binary Search Tree 
Node* insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}
void topView(Node* root) {
    if (root == nullptr) return;
    // map: horizontal distance -> node value (first node seen at that hd)
    map<int, int> topViewMap;
    // queue holds pair of node and its horizontal distance
    queue<pair<Node*, int>> q;
    q.push({root, 0});
    while (!q.empty()) {
        auto p = q.front();
        q.pop();
        Node* node = p.first;
        int hd = p.second;
        // only insert if this horizontal distance hasn't been seen before
        if (topViewMap.find(hd) == topViewMap.end())
            topViewMap[hd] = node->data;
        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }
    for (auto it : topViewMap)
        cout << it.second << " ";
    cout << endl;
}
int main() {
    Node* root = nullptr;
    int values[] = {20, 10, 30, 5, 15, 25, 35, 3, 7};
    int n = sizeof(values) / sizeof(values[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, values[i]);
    cout << "Top View of the Binary Tree: ";
    topView(root);
    return 0;
}
