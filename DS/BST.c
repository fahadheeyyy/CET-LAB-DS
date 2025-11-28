#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int value){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=value;
    return newNode;
}

struct Node *insert(struct Node *root, int value){

    if(root==NULL){
        return createNode(value);
    }
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    else if(value>root->data){
        root->right=insert(root->right,value);
    }

    return root;
}

void inorder(struct Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ->",root->data);
        inorder(root->right);
    }
}

void preorder(struct Node *root){
   if(root!=NULL){
    printf("%d ->",root->data);
    preorder(root->left);
    preorder(root->right);
   }
}

void postorder(struct Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d->",root->data);
    }
}

struct Node *inorderSuccessor(struct Node *root){
    while(root && root->left!=NULL){
        root=root->left;
    }
    return root;
}

struct Node *search(struct Node *root, int value){
    if(root==NULL || value==root->data){
        return root;
    }
    else if(value<root->data){
        return search(root->left,value);
    }
    else if(value>root->data){
        return search(root->right,value);
    }
}

struct Node *delete(struct Node *root,int value){
    if(root==NULL){
        return root;
    }
    if(value < root->data){
        root->left=delete(root->left,value);
    }
    else if(value > root->data){
        root->right=delete(root->left,value);
    }
    else{
        if(root->left==NULL){
            struct Node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = inorderSuccessor(root);
        root->data=temp->data;
        root->right=delete(root->right,temp->data);
    }
    return root;
}



int main(){
    struct Node *root = NULL;
    struct Node *temp=NULL;

    int ch,c=1,value;
    


    while(c==1){
        printf("Select from the below menu :\n1.insert \n2.search \n3.delete \n4.inorder \n5.preorder \n6.postorder");
        scanf("%d",&ch);
        switch(ch){
            case 1:{
            printf("\nEnter the value to be inserted :");
            scanf("%d",&value);
            root=insert(root,value);
            break;
            }
            case 2:
            {
            printf("\nEnter the value to be searched :");
            scanf("%d",&value);
            temp=search(root,value);
            if(temp==NULL){
                printf("element is not found.");
            }
            else{
                printf("element is found.");
            }
            break;
            }
            case 3:
            {
            printf("\nEnter the value to be deleted :");
            scanf("%d",&value);
            root=delete(root,value);
            break;
            }
            case 4:
            inorder(root);
            break;
            case 5:
            preorder(root);
            break;
            case 6:
            postorder(root);
            break;
        }
        printf("do you want to continue ? 0/1");
        scanf("%d",&c);
    }


    return 0;
}