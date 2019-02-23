/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/
    bool checkIfWithinRange(Node* root, int min, int max){
        if(root){
            if(root->data>=max||root->data<=min){
                return false;
            }
            else{
                return checkIfWithinRange(root->left, min, root->data) && checkIfWithinRange(root->right, root->data, max);
            }
        }
        return true;
    }
	bool checkBST(Node* root) {
        return checkIfWithinRange(root, 0, 10000);
	}