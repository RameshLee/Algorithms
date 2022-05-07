// set<int> Set; // complexities

// in-place erase: remove even numbers

int i=0;
while (1) {
    if (i >= vec.size()) break;
    if (vec[i] % 2 == 0) {
        vec.erase(vec.begin() + i); // Time=O(N), Space=O(1) ->space-efficient
        continue;
    }
    i++;
}

// summation of childs of the tree without siblings

int sum = 0;

node* helper(node* root) {
    if (!root) return nullptr;

    node* left = helper(root->left);
    node* right = helper(root->right);

    if (!left || !right) {
        if (left) sum += left->val;
        if (right) sum += right->val;
    }
    return root;
}