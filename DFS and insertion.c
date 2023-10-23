#include <stdio.h>

#include <stdlib.h>



struct BTNode

{

    int value;

    struct BTNode* left;

    struct BTNode* right;

};



struct BTNode* getNode(int value)

{

    struct BTNode* New = (struct BTNode*)malloc(sizeof(struct BTNode));

    New->value = value;

    New->left = NULL;

    New->right = NULL;

    return New;

}



struct BTNode * insert(struct BTNode* root, int value)

{

    if (root == NULL)

    {

        return getNode(value);

    }

    if(root->value < value)

    {

    	root->right = insert(root->right, value);

    }

    else if(root->value > value)

    {

    	root->left = insert(root->left, value);

    	return root;

    }

}



void printInorder(struct BTNode *node)

{

    if(node == NULL)

    {

        return;

    }

    printInorder(node->left);



    printf("%d ", node->value);



    printInorder(node->right);

}



void printPreorder(struct BTNode *node)

{

    if(node == NULL)

    {

        return;

    }

    printf("%d ", node->value);



    printPreorder(node->left);



    printPreorder(node->right);

}



void printPostorder(struct BTNode *node)

{

    if(node == NULL)

    {

        return;

    }

    printPostorder(node->left);



    printPostorder(node->right);



    printf("%d ", node->value);

}



int main()

{

    struct BTNode* root = getNode(1);

    root->left = getNode(2);

    root->right = getNode(3);

    root->left->left = getNode(4);

    root->left->right = getNode(5);



    printInorder(root);

    printf("\n");

    printPreorder(root);

    printf("\n");

    printPostorder(root);



    // insert(root, 15);

    // insert(root, 31);

    // insert(root, 17);

    // insert(root, 12); 

    // insert(root, 4);

    // insert(root, 91);



    return 0;

}
