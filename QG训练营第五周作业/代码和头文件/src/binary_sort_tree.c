#include "binary_sort_tree.h"
#include "LinkStack.h"
#include "LinkStack.c"

void visit (NodePtr p)
{
    if (p->value != 0x7fffffff)
    {
        printf(" %d ",p->value);
    }	
}

status BST_init(BinarySortTreePtr bst){
    //bst = (BinarySortTree*)malloc(sizeof(BinarySortTree));
    bst->root = (Node*)malloc(sizeof(Node));
    bst->root->value = 0x7fffffff;
    bst->root->left = NULL;
    bst->root->right = NULL;
    return succeed;
}

status BST_insert(BinarySortTreePtr bst, ElemType value){
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    NodePtr p = bst->root;
    while (1)
    {
        if (bst->root->value == 0x7fffffff)
        {
            bst->root->value = value;
            bst->root->left = (Node*)malloc(sizeof(Node));
            bst->root->right = (Node*)malloc(sizeof(Node));
            bst->root->left->value = bst->root->right->value = 0x7fffffff;
            break;
        }else{
            if (value < bst->root->value)
            {
                bst->root = bst->root->left;
            }else if (value == bst->root->value)
            {
                printf("该值已存在于树中！\n");
                return failed;
            }else if (value > bst->root->value)
            {
                bst->root = bst->root->right;
            }
        }
    }
    bst->root = p;
    return succeed;
}

status BST_delete(BinarySortTreePtr bst, ElemType value){
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        printf("树为空树！\n");
        return failed;
    }        
    NodePtr p = bst->root;
    while (1)
    {
        if (bst->root->value == 0x7fffffff)
        {
            return failed;
        }else{
            if (bst->root->value == value)
            {
                bst->root->left = bst->root->right = NULL;
                bst->root->value = 0x7fffffff;
                break;
            }
            if (value < bst->root->value)
            {
                bst->root = bst->root->left;
            }
            if (value > bst->root->value)
            {
                bst->root = bst->root->right;
            }
        }
    }
    bst->root = p;
    return succeed;
}

status BST_search(BinarySortTreePtr bst, ElemType value){
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        printf("树为空树！\n");
        return failed;
    }     
    NodePtr p = bst->root;
    while (1)
    {
        if (bst->root->value == 0x7fffffff)
        {
            printf("树中不存在此元素");
            return failed;
        }else{
            if (bst->root->value == value)
            {
                break;
            }
            if (value < bst->root->value)
            {
                bst->root = bst->root->left;
            }
            if (value > bst->root->value)
            {
                bst->root = bst->root->right;
            }
        }
    }
    bst->root = p;
    return succeed;    
}

status BST_preorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        printf("树为空树！\n");
        return failed;
    }
    LinkStack s;
    initLStack(&s);
    pushLStack(&s,bst->root);
    while (!isEmptyLStack(&s))
    {
        NodePtr n = popLStack(&s);
        visit(n);
        if (n->right->value != 0x7fffffff)
        {
            pushLStack(&s,n->right);
        }
        if (n->left->value != 0x7fffffff)
        {
            pushLStack(&s,n->left);
        }        
    }
    return succeed;
}

status BST_preorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        return failed;
    }
    visit(bst->root);
    BinarySortTreePtr b = (BinarySortTree*)malloc(sizeof(BinarySortTree));
    b->root = bst->root->left;
    BST_preorderR(b, visit);
    b->root = bst->root->right;
    BST_preorderR(b, visit);
    return succeed;
}

status BST_inorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        return failed;
    }
    NodePtr n = bst->root;
    LinkStack s;
    initLStack(&s);
    pushLStack(&s,n);
    while (!isEmptyLStack(&s))
    {
        if (n->left->value != 0x7fffffff)
        {
            pushLStack(&s,n->left);
            n = n->left;
        }else{
            NodePtr p = popLStack(&s);
            visit(p);
            if (p->right->value != 0x7fffffff)
            {
                n = p->right;
                pushLStack(&s,n);
            }
        }
    }
    return succeed;
}

status BST_inorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        return failed;
    }
    BinarySortTreePtr b = (BinarySortTree*)malloc(sizeof(BinarySortTree));
    b->root = bst->root->left;
    BST_inorderR(b, visit);
    visit(bst->root);
    b->root = bst->root->right;
    BST_inorderR(b, visit);
    return succeed;
}

status BST_postorderI(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        return failed;
    }
    LinkStack s1;
    LinkStack s;
    initLStack(&s);
    initLStack(&s1);
    pushLStack(&s,bst->root);
    while (!isEmptyLStack(&s))
    {
        NodePtr n = popLStack(&s);
        pushLStack(&s1,n);
        if (n->left->value != 0x7fffffff)
        {
            pushLStack(&s,n->left);
        }
        if (n->right->value != 0x7fffffff)
        {
            pushLStack(&s,n->right);
        }        
    }
    while (!isEmptyLStack(&s1))
    {
        NodePtr n = popLStack(&s1);
        visit(n);
    }
    return succeed;
}

status BST_postorderR(BinarySortTreePtr bst, void (*visit)(NodePtr)) {
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        return failed;
    }
    BinarySortTreePtr b = (BinarySortTree*)malloc(sizeof(BinarySortTree));
    b->root = bst->root->left;
    BST_postorderR(b, visit);
    b->root = bst->root->right;
    BST_postorderR(b, visit);
    visit(bst->root);
    return succeed;
}

status BST_levelOrder(BinarySortTreePtr bst, void (*visit)(NodePtr)){
    if (bst->root == NULL || bst == NULL)
    {
        printf("树未初始化！\n");
        return failed;
    }
    if (bst->root->value == 0x7fffffff)
    {
        printf("树为空树！\n");
        return failed;
    }
    Node* Queue[100] = {NULL};
    Node* left = NULL;
    Node* right = NULL;
    int i = 1,j = 0;
    Queue[0] = bst->root;
    while (i > j)
    {
        if (Queue[j]->value != 0x7fffffff)
        {
            visit(Queue[j]);
            left = Queue[j]->left;
            right = Queue[j]->right;
            if (left){Queue[i++] = left;}
            if (right){Queue[i++] = right;}
        }
        j++;
    }
    return succeed;
}