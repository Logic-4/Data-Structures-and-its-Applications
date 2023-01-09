#include<stdio.h>
#include<stdlib.h>

typedef struct tree_linked
{
    int info;
    struct tree_linked *left, *right;
}NODE;

NODE *root = NULL;

//iterative inorder

// void iterativeinoder(root)
// {
//     s = emptystack;
//     current = root;
//     do{
//         while (current != NULL)
//         {
//             push(s,current);
//             current = current->left;
//         }
//         poppedNode = pop(s);
//         printf("%d",poppedNode-.info);
//         current = poppedNode->right;
//     }while(!isEmpty(s) || current != NULL)
// }

//iterative preorder



//iterative postorder