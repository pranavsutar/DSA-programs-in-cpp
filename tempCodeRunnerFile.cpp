
    int ic = chooseLeast(s);
    char c = s[ic];
    node* root = new node(c);
    root->left = BuildExpTree(s.substr(0,ic));
    root->right = BuildExpTree(s.substr(ic+1));
    return root;
}
