// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// tnode STRUCTURE IS DEFINED BY DEFAULT
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED
using namespace std;
bool isSameTree(tnode* n1, tnode* n2){
    if(!n1&&!n2)
        return true;
    if((!n1&&n2)||(!n2&&n1)||(n1->value!=n2->value))
        return false;
    return isSameTree(n1->left, n2->left) && isSameTree(n1->right, n2->right);
}
/*
bool inorder(tnode* root1, tnode* root2){
    if(root1->left && inorder(root1->left, root2))
        return true;
    if(isSameTree(root1, root2))
        return true;
    if(root1->right && inorder(root1->right, root2))
        return true;
    else return false;
}
*/
int isSubTree(tnode* root1, tnode* root2)
{
    if(!root2)
        return 1;
   if(!root2&&!root1)
        return 1;
    if(!root1&&root2)
        return -1;
    if(isSameTree(root1, root2))
        return 1;
    else{
        if(isSubTree(root1->left, root2)==1||isSubTree(root1->right, root2)==1){
            return 1;
        }
        else return -1;
    }
}

// FUNCTION SIGNATURE ENDS
