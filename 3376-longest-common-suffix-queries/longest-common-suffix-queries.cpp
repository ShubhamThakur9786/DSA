class Solution {
public:

    struct TrieNode {
        int child[26];
        int idx;

        TrieNode() {
            memset(child, -1, sizeof(child));
            idx = -1;
        }
    };

    vector<TrieNode> trie;

    Solution() {
        trie.push_back(TrieNode()); // root
    }

    bool better(vector<string>& words, int a, int b) {

        if (b == -1)
            return true;

        if (words[a].size() != words[b].size())
            return words[a].size() < words[b].size();

        return a < b;
    }

    void insert(string& word, int index,
                vector<string>& words) {

        int node = 0;

        if (better(words, index, trie[node].idx))
            trie[node].idx = index;

        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1) {
                trie[node].child[c] = trie.size();
                trie.push_back(TrieNode());
            }

            node = trie[node].child[c];

            if (better(words, index, trie[node].idx))
                trie[node].idx = index;
        }
    }

    int search(string& word) {

        int node = 0;

        for (int i = word.size() - 1; i >= 0; i--) {

            int c = word[i] - 'a';

            if (trie[node].child[c] == -1)
                break;

            node = trie[node].child[c];
        }

        return trie[node].idx;
    }

    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {

        for (int i = 0; i < wordsContainer.size(); i++) {
            insert(wordsContainer[i], i, wordsContainer);
        }

        vector<int> ans;

        for (auto& q : wordsQuery) {
            ans.push_back(search(q));
        }

        return ans;
    }
};