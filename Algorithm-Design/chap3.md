# Algorithm Design

#### 3-2

<img src=".\image\image-20200424231638649.png" alt="image-20200424231638649" style="zoom: 50%;" />

**answer：**

不失一般性，假设图是连通的，否则对每一个连通分量做如下算法。

任意选取一个节点做dfs，同时记录下dfs tree，当 dfs 发现一条后向边 $ (u,v) $ 时, 说明图中存在circle。从节点 $u$ 开始在 dfs tree 中不停地寻找祖先节点直到遇到节点 $v$, 这条路径的反向就是一条circle。

时间复杂度：dfs为线性时间，寻找circle也为线性时间。

#### 3-7

<img src=".\image\image-20200425104054736.png" alt="image-20200425104054736" style="zoom:55%;" />

**answer：**

The claim is true.

*proof :* Assume $G$ is not connected，then $G$ must have at least two SCC. let $S$ be the SCC with fewest nodes, then $|S|<n/2$. Consider any node $u$ in $S$, all its neighbor must also in $S$. Given the condition that every node of G has degree at least $n/2$, $u$ has at least  $n/2$ neighbors, then  $|S|=n/2+1$, which is a contradiction to $|S|<n/2$.

#### 3-9

<img src=".\image\image-20200425105615065.png" alt="image-20200425105615065" style="zoom: 55%;" />

**answer：**

If we can’t find such a node, there must be at least two paths from $s$ to $t$ in the graph and no node can both exist in both path.  Since distance is greater than $n/2$, which means there should be greater than $n$ nodes in the graph, which is a contradiction.

*algorithms :*

Consider node on every path from $s$ to $t$ belong to a layer, there will be $d$ layers. As show before, there must be a layer only contains one node. Do BFS from s to t, maintain the node we pass through on each layer, return the node that is alone at its layer. BFS and search layers both in linear time.