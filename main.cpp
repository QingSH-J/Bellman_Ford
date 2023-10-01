//
//  main.cpp
//  Bellman_Ford
//
//  Created by 金心羽 on 2023/10/1.
//

#include <iostream>
#define MAXN 20
#define INF 10000 //无穷大
int n;
int dist[MAXN];
int path[MAXN];
int Edge[MAXN][MAXN];

void Bellman_Ford(int v0){ //v0点进入
    int i, j, k, u; //循环变量
    for(i = 0; i < n; i ++)
    {
        dist[i] = Edge[v0][i];
        if(i != v0 && dist[i] < INF){
            path[i] = v0;
        }
        else{
            path[i] = -1;
        }
    }
    for(k = 2; k < n; k ++){
        for(u = 0; u < n; u ++){
            if(u != v0){
                for(j = 0; j < n; j ++){
                    if(Edge[j][u] < INF && dist[j] + Edge[j][u] < dist[u]){
                        dist[u] = dist[j] + Edge[j][u];
                        path[u] = j;
                    }
                }
            }
        }
    }
}
