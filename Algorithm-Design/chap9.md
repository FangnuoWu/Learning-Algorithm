### 9-1

**We define Monotone QSAT to be the decision problem**
$$

\exists x_{1} \forall x_{2} \cdots \exists x_{n-2} \forall x_{n-1} \exists x_{n} \Phi\left(x_{1}, \ldots, x_{n}\right) ?
$$
**where the formula $\Phi$ is monotone.**

**Do one of the following two things: **

**(a) prove that Monotone QSAT is PSPACE-complete**

**(b) give an algorithm to solve arbitrary instances of Monotone QSAT that runs in time polynomial in n. (the goal is polynomial time, not just polynomial space.)**

**answer：**

把  Monotone QSAT 问题看作 Competitive 3-SAT 问题，让 Player1 控制部分的literals，Player2控制剩下的 literals，上述 decision problem 变为 是否存在一个算法让 Player1能够赢得比赛。

当每个clause都包含至少一个由Player1控制的literal时，显然Player1可以获胜只要他将所有自己控制的都指派为true，其他情况Player1一定不能获胜，因为Player2至少可以通过将Player1不能控制的clause设为法拉瑟来阻止Player1赢得比赛。

在多项式时间内可以完成上述问题。

### 9-2

**Geography on a Graph: we have a directed graph G = (V, E), and a designated start node s ∈ V. Players alternate turns starting from s; each player must, if possible, follow an edge out of the current node to a node that hasn’t been visited before. The player who loses is the first one who cannot move to a node that hasn’t been visited earlier in the game. **

**Prove that it is PSPACE-complete to decide whether the first player can force a win in Geography on a Graph**.

**answer：**

如果 Quantified 3-SAT $\leq_P$ Generalized Geography，由于 QSAT 是 PSPACE-complete，可以证明上述问题也是 PSPACE-complete 的。

**证明Quantified 3-SAT $\leq_P$ Generalized Geography：**

1. 构造：

选取一个奇数个变量的的QSAT问题 $$\exists x_{1} \forall x_{2} \cdots \exists x_{n-2} \forall x_{n-1} \exists x_{n} \Phi\left(x_{1}, \ldots, x_{n}\right)$$，构造的Generalized Geography如下图所示。

每个变量对应左边的一个node，两条分支True或False对应给该变量赋值。A和B玩家从b点开始游戏，A先走，走过的点即将对应的变量设置为true，由于菱形的设置可以直观地看出A和B依次选择分支，由于奇数个顶点，A将选择最后一个分支，接着在c点B选择分支。

![Generalized geography 3.png](https://upload.wikimedia.org/wikipedia/commons/e/eb/Generalized_geography_3.png)

2. A赢得比赛等价于QSAT问题成立。

如果QSAT不成立，说明有一个clause的所有变量都为false，B玩家只需要选择这个clause，接下来A任意走到一个变量，B继续走到变量对应的节点，由于变量为false，其对应的节点一定是未被访问过的，而周围的两个节点一定是被访问过的，B获得胜利。相反如果QSAT成立，A只要选择一个值为true的变量，那么B接下来只能选择的唯一节点一定是被访问过的，所以B获得胜利。

因此Quantified 3-SAT $\leq_P$ Generalized Geography，得证。

### 9-3

**Give a polynomial-time algorithm to decide whether a player has a forced win in Geography on a Graph, in the special case when the underlying graph G has no directed cycles (in other words, when G is a DAG).**

**answer：**

对G做一次拓扑排序, 得到序列$v_1,v_2,\cdots v_n$.

构造一个动态规划表格M[], 定义M[i] = 1表示在点 $v_i$ 有选择权的玩家可以获胜，M[i]=0表示在i点没有选择权的玩家可以获胜。

对于出度为0的节点，说明没有选择权的玩家可以获胜，我们将所有出度为零的节点i对应的M[i]置为0。对于节点$v_i$，如果有选择权的玩家可以获胜，说明存在一个可以选择的节点 $v_k$，接下来要在 $v_k$ 选择的另一个玩家不能获胜，即M[k] = 0。(由于按拓扑序列排序，此时M[k]必然是已知的)。所以我们可以得出方程：
$$
M[i]=\left\{\begin{array}{ll}
0 &  v_{i} \text { 出度为 } 0 \\
1 &  \exists k>i,\left(v_{i}, v_{k}\right) \in E, M[k]=0
\end{array}\right.
$$
上述过程都可以在多项式内完成。