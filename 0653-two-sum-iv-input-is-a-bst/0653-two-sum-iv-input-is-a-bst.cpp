class BSTiterator {
    stack<TreeNode*> st;
    bool reverse = true;

public:
    BSTiterator(TreeNode* root, bool isreverse) {
        reverse = isreverse; // ✅ Fix: assign to member, not local variable
        pushall(root);
    }

    bool hasnext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (!reverse) pushall(temp->right);
        else pushall(temp->left);
        return temp->val;
    }

private:
    void pushall(TreeNode* root) {
        while (root) {  // ✅ Fix: while(root) instead of while(!root)
            st.push(root);
            if (reverse == true) {
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (root == nullptr) return false;

        BSTiterator l(root, false); // left-to-right
        BSTiterator r(root, true);  // right-to-left

        int i = l.next();
        int j = r.next();

        while (i < j) {
            if (i + j == k) return true;
            else if (i + j < k) i = l.next();
            else j = r.next(); // ✅ Fix: this was always executed before
        }

        return false;
    }
};

