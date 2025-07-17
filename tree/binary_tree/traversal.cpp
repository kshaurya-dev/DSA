#include<bits/stdc++.h>
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x) , left(nullptr) , right(nullptr){}
};
TreeNode* create(int val){
    return new TreeNode(val);
}
TreeNode* construct_tree(){
/*    1
    /     \
  2          3
 /  \       /  \
4      5    6     7
/ \   / \   /  \  /  \
8  9  10 11 12 13 14 15        */

    TreeNode* root= create(1);
    TreeNode* two = create(2);
    TreeNode* three=create(3);
    TreeNode* four= create(4);
    TreeNode* five= create(5);
    TreeNode* six=create(6);
    TreeNode* seven= create(7);
    TreeNode* eight = create(8);
    TreeNode* nine=create(9);
    TreeNode* ten=create(10);
    TreeNode* eleven=create(11);
    TreeNode* twelve=create(12);
    TreeNode* thirteen=create(13);
    TreeNode* fourteen=create(14);
    TreeNode* fifteen=create(15);
    root->left=two , root->right=three;
    two->left=four , two->right=five;
    three->left=six,three->right=seven;
    four->left=eight, four->right=nine;
    five->left=ten, five->right=eleven;
    six->left=twelve, six->right=thirteen;
    seven->left=fourteen , seven->right=fifteen;
    return root;
}
void free_tree(TreeNode* root) {
    if (root == nullptr) return;
    free_tree(root->left);
    free_tree(root->right);
    delete root;
}
void inorder(TreeNode* root){

    std::vector<int>traversal;
    std::map<TreeNode* , int>map;
    std::stack<TreeNode*>stack;
    stack.push(root);

    while(!stack.empty()){
        TreeNode* node = stack.top();
        if(!node->left || map.find(node->left)!=map.end()){
            traversal.emplace_back(node->val);
            stack.pop();
            map[node]++;
            if(node->right)stack.push(node->right);
        }
        else stack.push(node->left);
    }

    std::cout<<"INORDER : ";
    for(auto& el : traversal)std::cout<<el<<' ';
    std::cout<<'\n';
}
void preorder(TreeNode* root){
    
    std::vector<int>traversal;
    std::stack<TreeNode*>stack;
    stack.push(root);

    while(!stack.empty()){
        TreeNode* node = stack.top();
        traversal.emplace_back(node->val);
        stack.pop();

        if(node->right)stack.push(node->right);//since NLR , L must be popped before R 
        if(node->left)stack.push(node->left);// hence we push R first (!! stack is LIF0 !!)
    }

    std::cout<<"PREORDER : ";
    for(auto& el : traversal)std::cout<<el<<' ';
    std::cout<<'\n';
}
void postorder(TreeNode* root){
    

    std::vector<int>traversal;
    std::stack<TreeNode*>stack;
    stack.push(root);

    while(!stack.empty()){
        TreeNode* node = stack.top();
        traversal.emplace_back(node->val);
        stack.pop();
        if(node->right)stack.push(node->left);
        if(node->left)stack.push(node->right);
        //well LRN is just NRL in reverse, kinda preorder
       // so we write preorder algo , but with a twist
        //instead of pushing R first (cause NLR) , we push L first (cause NRL)
    }
    std::reverse(traversal.begin() , traversal.end());
    std::cout<<"POSTORDER : ";
    for(auto& el : traversal)std::cout<<el<<' ';
    std::cout<<'\n';
}
void levelorder(TreeNode* root){
    std::queue<TreeNode*>que;
    que.push(root);
    std::vector<int>traversal;
    while(!que.empty()){
        int n =que.size();
        for( int i =0 ; i<n ; i++){
            TreeNode* node = que.front();
            que.pop();
            traversal.emplace_back(node->val);
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);
        }
    }
    std::cout<<"Level Order (BFS): ";
    for(auto& el : traversal)std::cout<<el<<' ';
    std::cout<<'\n';
}
int main(){
    TreeNode* root=construct_tree();
    inorder(root);
    preorder(root);
    postorder(root);
    levelorder(root);
    free_tree(root);
    return 0;
}