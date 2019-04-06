// Problem 5 -  Find Tree Element ( Knowledge Base: Data Structures )

// This function takes in a tree and value and returns
// "true" if the value is in the tree
//#include <iostream>
bool FindTreeElement( Tree * tree, int value )
{
	if (tree) {

		//std::cout << tree->data << std::endl;
		if (tree->data == value)
			return true;
		else {
			return (FindTreeElement(tree->left, value) || FindTreeElement(tree->right, value));
		}
	}
	else {
		//std::cout << "was nullptr" << std::endl;
		return false;
	}
}
