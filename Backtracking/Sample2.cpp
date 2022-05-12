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

// sum of all the nodes without a sibling in the tree

int sum = 0;

node* helper(node* root) {
    if (!root) return nullptr;

    node* left = helper(root->left);
    node* right = helper(root->right);

    if (left && !right) sum += left->val;
    if (!left && right) sum += right->val;

    return root;
}