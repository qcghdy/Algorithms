#include <iostream>
#include <cassert>
#include <ctime>
#include <cstdlib>

using namespace std;

#define N 100

class UnionFind
{
private:
    int *parent;  // 使用一个数组构建一棵指向父节点的树
    int count;
    
public:
    UnionFind(int n)
    {
        parent = new int[n];
        count = n;
        
        for (int i = 0; i < count; i++)
        {
            parent[i] = i;  // 每一个 parent[i] 指向自己，表示根节点
        }
    }
    
    ~UnionFind()
    {
        delete[] parent;
    }
    
    // 查找过程，根节点的特点: parent[p] == p
    int find(int p)
    {
        assert(p >= 0 && p < count);
        
        // 不断去查找自己的父亲节点, 直到到达根节点
        while (p != parent[p])
        {
            p = parent[p];
        }
        
        return p;  // 最终根节点
    }
    
    // 查看元素 p 和 元素 q 是否连接, 当 arr[p] == arr[q], 表示连接
    bool isConnected(int p, int q)
    {
        return find(p) == find(q);
    }
    
    // 合并元素 p 和 元素 q
    void unions(int p, int q)
    {
        int pID = find(p);  // p 的根节点
        int qID = find(q);  // q 的根节点
        
        if (pID == qID)
        {
            return;
        }
        
        parent[pID] = qID;
    }  
};

int main()
{
    srand(time(NULL));
   
    UnionFind uf = UnionFind(N);
    
    for (int i = 0; i < N; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        
        cout << uf.isConnected(a, b) << " ";  // 随机选择两个元素，看是否连接
    }
    
    for (int i = 0; i < N; i++)
    {
        int a = rand() % N;
        int b = rand() % N;
        
        uf.unions(a, b);  // 随机选择两个元素，合并
    }  
}
