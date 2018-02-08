#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void print_menu()
{
 
    printf(" 1 - Обход дерева\n");
    printf(" 2 - Вставить слово\n");
    printf(" 3 - Удалить слово\n");
    printf(" 4 - Максимальное\n");
    printf(" 5 - Минимальное\n");
    printf(" 6 - Вывести дерево\n");
    printf(" 7 - Поиск слова\n");
    printf(" 0 - Выход\n");
 
}

typedef struct tree_node
{
    const char *name;

    // меньшие
    struct tree_node *left;
    // большие
    struct tree_node *right;
} tree_node;


void print_Tree(tree_node *tree, int level)
{
    if(tree != NULL)
    {
        print_Tree(tree->left,level + 1);
        for(int i = 0;i < level;i++) 
            printf("      ");
        printf("%s\n",tree->name); 
        print_Tree(tree->right,level + 1);
    }
}


tree_node* create_node(const char *name)
{
    tree_node *node = malloc(sizeof(tree_node));
    if (node)
    {
        node->name = name;
        node->left = NULL;
        node->right = NULL;
    }

    return node;
}

tree_node* insert(tree_node *tree, tree_node *node)
{
    int cmp;

    if (tree == NULL)
        return node;

    cmp = strcmp(node->name, tree->name);
    if (cmp == 0)
        assert(0);
    else if (cmp < 0)
        tree->left = insert(tree->left, node);
    else
        tree->right = insert(tree->right, node);

    return tree;
}

tree_node* lookup_1(tree_node *tree, const char *name)
{
    int cmp;

    if (tree == NULL)
        return NULL;

    cmp = strcmp(name, tree->name);
    if (cmp == 0)
        return tree;
    else if (cmp < 0)
        return lookup_1(tree->left, name);
    else
        return lookup_1(tree->right, name);
}

tree_node* lookup_2(tree_node *tree, const char *name)
{
    int cmp;

    while (tree != NULL)
    {
        cmp = strcmp(name, tree->name);
        if (cmp == 0)
            return tree;
        else if (cmp < 0)
            tree = tree->left;
        else
            tree = tree->right;
    }

    return NULL;
}

void apply(tree_node *tree, void (*f)(tree_node*, void*), void *arg)
{
    if (tree == NULL)
        return;

    // pre-order
    // f(tree, arg);
    apply(tree->left, f, arg);
    // in-order
    f(tree, arg);
    apply(tree->right, f, arg);
    // post-order
    // f(tree, arg);
}

int main(int argc, char** argv)
{
    setbuf(stdout, NULL);

    print_menu();

    tree_node tree_node;

    return 0;
}
