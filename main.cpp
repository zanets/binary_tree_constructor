#include <iostream>
#include <fstream>
#include <nlohmann/json.hpp>
#include <queue>

using json = nlohmann::json;

using namespace std;

struct Node {
    int val;
    
    Node* left;
    Node* right;

    Node(int val) {
        this->val = val;
        this->left = nullptr;
        this->right = nullptr;
    }
};


Node* doBuildTree(vector<int>& preorder, int& index, vector<int>& inorder, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int rootVal = preorder[index];
    Node* root = new Node(rootVal);

    int inorderIdx = start;
    for (; inorderIdx <= end; inorderIdx++) {
        if (inorder[inorderIdx] == rootVal)
            break;
    }

    root->left = doBuildTree(preorder, ++index, inorder, start, inorderIdx-1);
    root->right = doBuildTree(preorder, index, inorder, inorderIdx+1, end);

    return root;
}

Node* buildTree(vector<int>& preorder, vector<int> inorder) {
    int index = 0;
    return doBuildTree(
        preorder,
        index,
        inorder,
        0,
        inorder.size()-1
    );
}

void get_preorder(Node* root, vector<int>& ret) {
    if (root == nullptr)
        return;

    ret.push_back(root->val);
    get_preorder(root->left, ret);
    get_preorder(root->right, ret);
    return;
}

void get_inorder(Node* root, vector<int>& ret) {
    if (root == nullptr)
        return;

    get_inorder(root->left, ret);
    ret.push_back(root->val);
    get_inorder(root->right, ret);
    return;
}

void get_bfs(Node* root, vector<int>& ret) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);
    while(q.size() > 0) {
        Node* n = q.front();
        q.pop();
        ret.push_back(n->val);
        if (n->left)
            q.push(n->left); 
        if (n->right)
            q.push(n->right); 
    }
    return; 
}

void coutVec(vector<int>& vec) {
    for (int& v: vec) {
        cout << v << ", ";
    }
    cout << endl;
}


int main() {
    std::ifstream f("test.json");
    json data = json::parse(f);

    for (auto& i : data) {
        vector<int> preorder = i[0].get<vector<int>>();
        vector<int> inorder = i[1].get<vector<int>>();
        Node* root = buildTree(preorder, inorder);       
        
        vector<int> ans_preorder = {};
        get_preorder(root, ans_preorder);
        coutVec(ans_preorder);
        
        vector<int> ans_inorder = {};
        get_inorder(root, ans_inorder);
        coutVec(ans_inorder);
        
        vector<int> ans_bfs = {};
        get_bfs(root, ans_bfs);
        coutVec(ans_bfs);

        cout << endl;
    }





    return 0;
}