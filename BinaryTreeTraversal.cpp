class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while(cur){
            stk.push(cur);
            preorder.push_back(cur->val);
            cur = cur->left;
        }
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            stk.pop();
            tmp = tmp->right;
            while(tmp){
                stk.push(tmp);
                preorder.push_back(tmp->val);
                tmp = tmp->left;
            }
        }
        return preorder;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        TreeNode* prev = NULL;
        while(cur){
            stk.push(cur);
            cur = cur->left;
        }
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            if(tmp->right && tmp->right != prev){
                tmp = tmp->right;
                while(tmp){
                    stk.push(tmp);
                    tmp = tmp->left;
                }
            }
            else{
                postorder.push_back(tmp->val);
                prev = tmp;
                stk.pop();
            }
        }
        return postorder;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        stack<TreeNode*> stk;
        while(root){
            stk.push(root);
            root = root->left;
        }
        while(!stk.empty()){
            TreeNode* tmp = stk.top();
            inorder.push_back(tmp->val);
            stk.pop();
            tmp = tmp->right;
            while(tmp){
                stk.push(tmp);
                tmp = tmp->left;
            }
        }
        return inorder;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelorder;
        if(root == NULL)
            return levelorder;
        vector<int> level;
        int count = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp = q.front();
            q.pop();
            count--;
            level.push_back(tmp->val);
            if(tmp->left)
                q.push(tmp->left);
            if(tmp->right)
                q.push(tmp->right);
            if(count == 0){
                count = q.size();
                levelorder.push_back(level);
                level.clear();
            }
        }
        return levelorder;
    }
};