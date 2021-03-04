//Aiordachioaei Andrei
#include "node.h"

Node::Node() {
    this->value = 0;
    this->left = nullptr;
    this->right = nullptr;
}

Node::Node(int v) {
    this->value = v;
    this->left = nullptr;
    this->right = nullptr;
}

Node::~Node() {
	delete left;
	delete right;
}