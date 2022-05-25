// Link: https://leetcode.com/problems/connecting-cities-with-minimum-cost/

// Approach: Kruskal's algorithm for MST
class DisjointSet {
public:
    void makeset(int n) {
        for (int i=0; i<n; i++) {
            parent[i] = i, rank[i] = 1, groups++;
        }
    }

    int find(int i) {
        if (parent[i] == i) return i;
        return parent[i] = find(parent[i]);
    }

    void unify(int x, int y) {
        int i = find(x), j = find(y);
        if (rank[i] < rank[j])          parent[i] = j;
        else if (rank[i] > rank[j])     parent[j] = i;
        else if (rank[i] == rank[j])    parent[j] = i, rank[i]++;
        groups--;
    }

    int findGroups() {
        return groups;
    }
private:
    unordered_map<int,int> parent, rank;
    int groups = 0;
};

class mySort {
public:
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[2] < v2[2];
    }
};

class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {

        // sort edges based on weights
        std::sort(connections.begin(), connections.end(), mySort());

        // make disjoint set
        DisjointSet DS; DS.makeset(n);

        // repeatedly insert least weighted edge to construct MST
        auto SpanningTreeCost = 0;
        for (auto e:connections) {
            auto i=e[0], j=e[1], weight=e[2];
            if (DS.find(i) != DS.find(j)) { // add edge into the MST
                DS.unify(i,j);
                SpanningTreeCost += weight; // update spanningtreeCost
            }
            if (DS.findGroups() == 1) break;
        }
        return (DS.findGroups() == 1) ? SpanningTreeCost : -1;
    }
};