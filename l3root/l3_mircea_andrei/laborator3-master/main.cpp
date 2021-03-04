//Aiordachioaei Andrei
#include <iostream>
#include "tree.h"

//I test the number of Nodes
int test_countNodes() {
	Tree tree(10);
	tree.insert(5);
	tree.insert(12);
	if (tree.countNodes() == 3)
		return 1;
	return 0;
}

//I test the number of Edges
int test_countEdges() {
	Tree tree(10);
	tree.insert(5);
	tree.insert(12);
	if (tree.countEdges() == 2)
		return 1;
	return 0;
}

//I test the height of my binary tree
int test_countHeight() { 
	Tree tree(10);
	tree.insert(5);
	tree.insert(12);
	if (tree.height() == 2)
		return 1;
	return 0;
}

int main() {
    int ok = 0;
    //I set my root
    Tree tree(50); 
    unsigned int n;
    tree.insert(30);
    tree.insert(20);
    tree.insert(5);
    tree.insert(500);
    tree.insert(10);
    tree.insert(900);
    tree.insert(90);
    
    if (test_countEdges() == 1) { ok++; std::cout << "It works." << std::endl;
    }
	else std::cout << "It doesn't work."<<std::endl;

	if (test_countNodes() == 1) { ok++; std::cout << "It works." << std::endl;
	}
	else std::cout << "It doesn't work." << std::endl;

	if (test_countHeight() == 1) { ok++; std::cout << "It works." << std::endl;
	}
	else std::cout << "It doesn't work." << std::endl;
	
	if (ok == 3) std::cout << "All tests have been executed successfully." << std::endl;
	else std::cout << "One or more tests failed. Error." << std::endl;
    
	std::cout << std::endl << "The Binary tree"<< std::endl;
	
	std::cout << "Inorder: " << std::endl;
    std::cout << tree.inorder() << std::endl;
	
	std::cout << "Postorder: " << std::endl;
	std::cout << tree.postorder() << std::endl;
	
	std::cout << "Preorder: " << std::endl;
	std::cout << tree.preorder() << std::endl;

    n = tree.countNodes();
	std::cout << "Nodes: " << n << std::endl;
  
    n = tree.countEdges();
	std::cout << "Edges: " << n << std::endl;

    n = tree.height();
	std::cout << "Height: " << n << std::endl;
	
	return 0;
}