//Basulescu Mircea
#include <iostream>
#include <algorithm>
#include <string>
#include "tree.h"

using std::string;
using std::to_string;

Tree::Tree() {
    root = new Node(0);
}

Tree::Tree(int v) {
    root = new Node(v);
}

Tree::~Tree() {
	delete root;
}

//I will insert a node in my tree
void Tree::insert(int v, Node *node) {
    if (v < node->value) {
        if(node->left == nullptr){
            node->left = new Node(v);
            return;
        }
        insert(v, node->left);

    }
    else {
        if(node->right == nullptr) {
            node->right = new Node(v);
            return;
        }
        insert(v, node->right);
    }
}
 
//I will insert my root
void Tree::insert(int v) {
    insert(v, root);
}

//I will show my tree in inorder
string Tree::inorder(Node *node) {
	if (node == nullptr)
	{
		return "";
	}
	return inorder(node->left) + to_string(node->value) + " " + inorder(node->right);
}

string Tree::inorder() {
    return inorder(root);
}

//I will show my tree in preorder
string Tree::preorder(Node *node) {
	string result;
	if (node == nullptr)
	{
		return "";
	}
	return  to_string(node->value) + " " + preorder(node->left) + preorder(node->right);
}

string Tree::preorder() {
    return preorder(root);
}

//I will show my tree in postorder
string Tree::postorder(Node *node) {
		string result;
		if (node == nullptr)
		{
			return "";
		}
		return preorder(node->left) + preorder(node->right)+ to_string(node->value) + " ";

}

string Tree::postorder() {
    return postorder(root);
}


//I will delete a node from my tree
Node *Tree::remove(int value, Node *node) {
    if(node == nullptr)
        return nullptr;

    if (value < node->value) {
            node->left = remove(value, node->left);
    }
    else if (value > node->value) {
            node->right = remove(value, node->right);
    }
    else {

        if(node->left == nullptr && node->right == nullptr)
        {
            delete node;
            node = nullptr;
        }
        else if(node->left == nullptr)
        {
            Node *temp;
            temp = node;
            node = node->right;
            delete temp;
        }
        else if(node->right == nullptr)
        {
            Node *temp;
            temp = node;
            node = node->left;
            delete temp;
        }
        else
        {
            Node *min = getMinNode(node->right);
            node->value = min->value;
            node->right = remove(min->value, node->right);
        }
    }
   return node;
}

void Tree::remove(int v) {
    root = remove(v, root);
}

Node *Tree::getMinNode(Node *node) {
    if(node == nullptr)
        return nullptr;
    Node *current = node;
    while (current->left != nullptr)
        current = current->left;
    return current;
}

//I will count the number of nodes
unsigned int Tree::countNodes(Node *node) {
    if (node == nullptr)
        return 0;
    return 1 + countNodes(node->left) + countNodes(node->right);
}

unsigned int Tree::countNodes() {
    return countNodes(root);
}

//I will count the number of edges
unsigned int Tree::countEdges(Node *node) {
    if(node == nullptr)
        return 0;
    return countNodes(root) - 1;
}

unsigned int Tree::countEdges() {
    return countEdges(root);
}

//I will count the height of my tree
unsigned int Tree::height(Node *node) {
    if(node == nullptr)
        return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

unsigned int Tree::height() {
    return height(root);
}