bst_t *bst_remove(bst_t *root, int value)
{
    if (root == NULL)
        return (NULL);

    if (value < root->n)
        root->left = bst_remove(root->left, value);  
    else if (value > root->n)
        root->right = bst_remove(root->right, value);
    else 
    {
        if (remove_type(root) != 0)
            root->right = bst_remove(root->right, value);
    }
    
    return (root);
}