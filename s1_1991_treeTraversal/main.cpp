#include <iostream>
#include <unordered_map>

class Node{
public:
    char value;
    Node* left;
    Node* right;

    Node(char v): value(v) {left = nullptr; right = nullptr;}
};

Node* addNode(char data, std::unordered_map<char, std::pair<char, char>>& info){
    char lhs = info[data].first;
    char rhs = info[data].second;
    Node* tmp = new Node(data);
    if(lhs!='.') tmp->left = addNode(lhs, info);
    if(rhs!='.') tmp->right = addNode(rhs, info);
    return tmp;
}

void preorder(Node* node){
    if(node==nullptr) return;
    std::cout << node->value;
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node){
    if(node==nullptr) return;
    inorder(node->left);
    std::cout << node->value;
    inorder(node->right);
}

void postorder(Node* node){
    if(node==nullptr) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->value;
}


int main(){
    int N;
    std::cin >> N;
    
    std::unordered_map<char, std::pair<char, char>> info;
    for(int i=0; i<N; i++){
        char parent, left, right;
        std::cin >> parent >> left >> right;
        info[parent] = std::make_pair(left, right);
    }
    Node* root = addNode('A', info);
    preorder(root);
    std::cout << std::endl;
    inorder(root);
    std::cout << std::endl;
    postorder(root);
    std::cout << std::endl;
}