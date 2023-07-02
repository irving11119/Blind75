#include <bits/stdc++.h>
using namespace std;

class UnionFind {  // OOP style
   public:
    vector<int> p, rank, setSize;  // vi p is the key part
    int numSets;

    UnionFind(int N) {
        p.assign(N, 0);
        for (int i = 0; i < N; ++i) p[i] = i;
        rank.assign(N, 0);     // optional speedup
        setSize.assign(N, 1);  // optional feature
        numSets = N;           // optional feature
    }

    int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
        if (isSameSet(i, j)) return;
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) swap(x, y);
        p[x] = y;
        if (rank[x] == rank[y]) ++rank[y];
        setSize[y] += setSize[x];
        --numSets;
    }
};

class Solution {
   public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int> hm;
        UnionFind uf(n);

        for (long i = 0; i < accounts.size(); i++) {
            for (long j = 1; j < accounts[i].size(); j++) {
                if (hm.find(accounts[i][j]) == hm.end()) {
                    hm[accounts[i][j]] = i;
                } else {
                    uf.unionSet(hm[accounts[i][j]], i);
                }
            }
        }

        vector<vector<string>> newMail(n);
        vector<vector<string>> ans;

        for (auto itr : hm) {
            string key = itr.first;
            int value = itr.second;

            newMail[uf.findSet(value)].push_back(key);
        }

        for (long g = 0; g < n; g++) {
            if (newMail[g].size() == 0) {
                continue;
            }

            vector<string> output;
            output.push_back(accounts[g][0]);

            for (long h = 0; h < newMail[g].size(); h++) {
                output.push_back(newMail[g][h]);
            }

            sort(output.begin() + 1, output.end());

            ans.push_back(output);
        }

        return ans;
    }
};