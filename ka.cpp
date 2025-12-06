//Kruskal’s algorithm
//Minimum Spanning Tree
#include <iostream>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

int parent[100];
int rankArr[100];

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rankArr[i] = 0;
    }
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    
    if (rootX != rootY) {
        if (rankArr[rootX] < rankArr[rootY]) {
            parent[rootX] = rootY;
        } else if (rankArr[rootX] > rankArr[rootY]) {
            parent[rootY] = rootX;
        } else {
            parent[rootY] = rootX;
            rankArr[rootX]++;
        }
    }
}

bool compareEdge(Edge a, Edge b) {
    return a.weight < b.weight;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;
    
    Edge* edges = new Edge[E];
    
    cout << "Enter edges (source destination weight):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    
    sort(edges, edges + E, compareEdge);
    
    makeSet(V);
    
    Edge* result = new Edge[V - 1];
    int edgeCount = 0;
    int totalWeight = 0;
    
    for (int i = 0; i < E && edgeCount < V - 1; i++) {
        int srcRoot = find(edges[i].src);
        int destRoot = find(edges[i].dest);
        
        if (srcRoot != destRoot) {
            result[edgeCount++] = edges[i];
            totalWeight += edges[i].weight;
            unionSets(srcRoot, destRoot);
        }
    }
    
    cout << "\nMinimum Spanning Tree edges:" << endl;
    for (int i = 0; i < edgeCount; i++) {
        cout << result[i].src << " -- " << result[i].dest << " : " << result[i].weight << endl;
    }
    cout << "Total MST weight: " << totalWeight << endl;
    
    delete[] edges;
    delete[] result;
    return 0;
}
