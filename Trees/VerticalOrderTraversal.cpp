#include <bits/stdc++.h>
using namespace std;

// Binary Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to perform vertical order traversal
vector<vector<int>> verticalOrder(Node* root) {
    vector<vector<int>> result;
    if (!root) return result;

    // map<column, map<row, multiset<values>>> to keep order & handle ties
    map<int, map<int, multiset<int>>> nodes;

    // queue holds {node, {row, col}}
    queue<pair<Node*, pair<int,int>>> q;
    q.push({root, {0, 0}});

    while (!q.empty()) {
        auto p = q.front();
        q.pop();

        Node* node = p.first;
        int row = p.second.first;
        int col = p.second.second;

        nodes[col][row].insert(node->data);

        if (node->left)
            q.push({node->left, {row + 1, col - 1}});
        if (node->right)
            q.push({node->right, {row + 1, col + 1}});
    }

    // Build final result column by column
    for (auto& colPair : nodes) {
        vector<int> colVals;
        for (auto& rowPair : colPair.second) {
            for (int val : rowPair.second) {
                colVals.push_back(val);
            }
        }
        result.push_back(colVals);
    }

    return result;
}

// Driver / main function
int main() {
    /*
        Example tree:
                3
               / \
              9   20
                 /  \
                15    7
    */
    Node* root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);

    vector<vector<int>> result = verticalOrder(root);

    cout << "Vertical Order Traversal:" << endl;
    for (auto& col : result) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
