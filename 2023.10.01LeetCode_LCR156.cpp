/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    void GetString(TreeNode* root, string& s) {
        if (!root) {
            s += "nullptr,";
        } else {
            s += to_string(root->val) + ',';
            GetString(root->left, s);
            GetString(root->right, s);
        }
    }

    TreeNode* GetRoot(list<string>& slt) {
        if (slt.front() == "nullptr") {
            slt.erase(slt.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(slt.front()));
        slt.erase(slt.begin());
        root->left = GetRoot(slt);
        root->right = GetRoot(slt);

        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        GetString(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> slist;
        string now;
        for (auto& ch : data) {
            if (ch == ',') {
                slist.push_back(now);
                now.clear();
            } else {
                now += ch;
            }
        }
        return GetRoot(slist);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));