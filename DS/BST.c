#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value){
    struct Node* newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data = value;
    return newNode;
}

struct Node* insert(struct Node* root,int value){
    if (root==NULL){
        return createNode(value);
    }

    if (value < root->data)
        root->left=insert(root->left,value);
    
    else if(value > root->data)
       root->right=insert(root->right,value);
    

    return root;
}

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf(" -> %d",root->data);
        inorder(root->right);
    }
}
void preorder(struct Node* root){
    if(root != NULL){
        printf(" -> %d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct Node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf(" -> %d",root->data);
    }
}


struct Node* search(struct Node* root , int value){
    if (root == NULL || root->data==value){
        return root;
    }
    if (value<root->data){
        return search(root->left,value);
    }
    else if (value>root->data){
        return search(root->right,value);
    }
}

struct Node* inorderSuccessor(struct Node* root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node* delete(struct Node* root , int value){
    if (root == NULL){
        return root;
    }
    if (value < root->data){
        delete(root->left , value);
    }
    else if(value > root->data){
        delete(root->right , value);
    }
    else{
        if (root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = inorderSuccessor(root->right);
        root->data=temp->data;
        root->right = delete(root->right , temp->data);

    }
    return root;
}

int main(){
    struct Node* root =NULL;

    root=insert(root,10);
    root=insert(root,6);
    root=insert(root,16);
    root=insert(root,90);
    root=insert(root,9);
    root=insert(root,8);

    printf("inorder :");
    inorder(root);

    printf("\npreorder :");
    preorder(root);

    printf("\npostorder :");
    postorder(root);

    struct Node* result=search(root,10);
    if (result != NULL){
    printf("\nresult is -> %d ",result->data);

    int key=10;
    printf("\nafter deleting %d\n",key);
    root = delete(root,key);
    inorder(root);

}
}