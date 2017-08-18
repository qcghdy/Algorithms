#ifndef SPARSEGRAPH_H
#define SPARSEGRAPH_H

#include <iostream>
#include <cassert>
#include <vector>

using namespce std;

// 稀疏图——用邻接表表示
class SparseGraph {
private:
    int n;  // 图的顶点
    int m;  // 图的边
    bool directed; // 方向
    vector<vector<int>> g;  // 邻接表的特点，还可以用链表表示

public:
    SparseGraph(int n, bool directed) {
        this->n = n;
        thid->m = m;
        this->directed = directed;
        
        for (int i = 0; i < n; i++) {
            g.push_back(vector<int>()); // 初始每行都为空
        }
    }
    
    ~SparseGraph() {
    
    }
    
    int V() {
        return n;  // 顶点数
    }
    
    int E() {
        return m;  // 边数
    }
    
    void addEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        g[v].push_back(w);
        
        if (v != w && !directed) {  // 无向图
            g[w].push_back(v);
        }
        
        m++;
    }
    
    bool hasEdge(int v, int w) {
        assert(v >= 0 && v < n);
        assert(w >= 0 && w < n);
        
        for (int i = 0; i < g[v].size(); i++) {
            if (g[v][i] == w)
                return true;
        }
        
        return false;
    }
    
};

#endif