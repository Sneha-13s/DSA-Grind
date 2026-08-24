#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class solution{
public:
   bool isLeaf(TreeNode* node){
     return !node->left && !node->right; // the left and right value of node is empty or null  
   }
   void addLeftBoundary(TreeNode* root,vector<int>& res){
     TreeNode* curr = root->left; // made one node curr which is having left value as it is starting from left side 
     while(curr){
       if(!isLeaf(curr)){
         res.push_back(curr->val);//storing value in the res if isleaf is not null
       }
       if(curr->left) curr = curr->left;// if left value is present then curr will store left value
       else curr = curr->right;//else it will store right value
     }
   }
   void addLeaves(TreeNode* root,vector<int>& res){
     if(!root) return;
     if(isLeaf(root)){
       res.push_back(root->val);
       return;
     }
     addLeaves(root->left,res);
     addLeaves(root->right,res);
   }
   void addRightBoundary(TreeNode* root,vector<int>&res){
     TreeNode* curr = root->right;
     vector<int>temp;
     while(curr){
       if(!isleaf(curr)){
         temp.push_back(curr->val);
       }
       if(curr->right) curr= curr->right;
       else curr = curr->lef;
     }
     for(int i= temp.size()-1;i>=0;i--){
       res.push_back(temp[i]);
     }
   }
   vector<int>boundaryTraversal(TreeNode* root){
     vector<int> res;
     if(!root) return res;
     if(!isLeaf(root)){
       res.push_back(root->val);
     }
     addLeftBoundary(root,res);
     addLeaves(root,res);
     addRightBoundary(root,res);
     return res;
   }
};
int main(){
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(8);
  root->right->right->right = new TreeNode(9);
  Solution sol;
  vector<int>res = sol.boundaryTraversal(root);
  cout<<"Boundary Traversal: ";
  for(int val : res){
    cout<<val<<" ";
  }
  cout<<endl;
  return 0;
}
