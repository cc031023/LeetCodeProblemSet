class Codec {
private:
    TreeNode* Ldfs(list<string>& datalist) {
        if (datalist.front() == "nullptr") {
            datalist.erase(datalist.begin());
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(datalist.front()));
        datalist.erase(datalist.begin());
        root->left = Ldfs(datalist);
        root->right = Ldfs(datalist);
        return root;
    }

    void Sdfs(TreeNode* root, string& ans) {
        if (!root) {
            ans += "nullptr,";
        } else {
            ans += to_string(root->val) + ',';
            Sdfs(root->left, ans);
            Sdfs(root->right, ans);
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        Sdfs(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> datalist;
        string str;
        for (auto& ch : data) {
            if (ch == ',') {
                datalist.push_back(str);
                str.clear();
            } else {
                str += ch;
            }
        }
        return Ldfs(datalist);
    }
};
