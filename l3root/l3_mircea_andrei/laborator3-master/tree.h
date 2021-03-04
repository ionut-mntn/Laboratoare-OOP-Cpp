//Basulescu Mircea
#include "node.h"
#include <string>
using std::string;

class Tree {
public:
    Tree(int v);
    Tree();
	~Tree();
    void insert(int v);
    void remove(int v);
    string inorder();
    string preorder();
    string postorder();
    unsigned int countNodes();
    unsigned int countEdges();
    unsigned int height();

private:
    void insert(int v, Node *node);
    string inorder(Node *node);
    string preorder(Node *node);
    string postorder(Node *node);
    unsigned int countNodes(Node *node);
    unsigned int countEdges(Node *node);
    unsigned int height(Node *node);
    Node *getMinNode(Node *node);
    Node *remove(int v, Node *node);
    Node *root;
};