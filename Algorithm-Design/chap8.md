### 8-1

**（a） Interval Scheduling $≤_P$ Vertex Cover**

YES. Interval Scheduling takes polynomial time, so it can be solve by 

- Polynomial number of standard computational steps.
- calling oracle that solves Vertex Cover.

**(b)  Independent Set $≤_P$ Interval Scheduling**

Unknown. If P=NP then  Independent Set can be solve in polynomial time, indicate that Independent Set $≤_P$ Interval Scheduling. If Independent Set $≤_P$ Interval Scheduling, Independent Set Problem must be solved in polynomial time, which means P=NP.

### 8-21

**Prove that Fully Compatible Configuration is NP-complete.**

proof:

1. FCC $\in$ NP

   检测一个FCC解是否是正确的，需要检查每个option是否分别属于每个option set，并且对每个 incompatible set 检查两个option是否都存在FCC中。该检查显然是多项式时间可以完成的。

2. FCC $≤_P$ 3SAT

   对3SAT问题的每一个clause创造一个option set，每个literal是set中的option。将所有literal和它的negation组成的二元组一起构成 incompatible set。该构造可以在多项式时间内完成。

   对于构造的FCC问题只需要找到3SAT问题的一组解就可以。3SAT每个子句中至少有一个为true，相当于每个option set中选择了一个option。由于一个literal和它的negation不能同时为true，所以该3SAT问题的解一定满足所有pair都不属于 incompatible set 的条件。

### 8-27

**You are given positive integers $x_1,...,x_n$, and numbers k and B. You want to know whether it is possible to partition the numbers ${x_i}$ into k sets $S_1,...,S_k$ so that the squared sums of the sets add up to at most B:**
$$
\begin{equation}\sum_{i=1}^{k}\left(\sum_{x_{j} \in S_{i}} x_{j}\right)^{2} \leq B\end{equation}
$$
**Show that this problem is NP-complete.**

proof:

1. Number Partition $\in$ NP

   给定一个S划分，可以直接带入公式检验，可以在多项式时间内完成。

2. Subset sum $≤_P$ Number Partition 

   对 integer 为 W，n 个 numbers 为 $x_1,\cdots x_n$ 且 $S=\sum_{i=1}^{n} x_i$ 的 Subset sum问题，添加两个元素
$$
   \begin{equation}
\left\{
   \begin{array}{lr}
x_{n+1}=W+1 &  \\
   x_{n+2}=S+1-W &  
   \end{array}
   \right.
   \end{equation}
   $$
    构造一个 k=2，B=$(S+1)^2$ 的 Number Partition 问题。该构造可以在多项式时间内完成，且可以证明找到 Subset sum 问题的解就能找到Number Partition 的解。
   
   如果寻找到一个$S_1$和$S_2$的划分使
   $$
   \begin{equation} 
   \sum_{x_i\in S_1} x_i = (S+1)^2 \tag{1}
   \end{equation}
   $$
   和​
   $$
   \sum_{x_i\in S_2} x_i = (S+1)^2\tag{2}
   $$
   就可以满足
   $$
   \begin{equation}\sum_{i=1}^{k}\left(\sum_{x_{j} \in S_{i}} x_{j}\right)^{2} \leq B\end{equation}
   $$
   Subset sum 问题的解说明能找到一个$S_i\subset S$, 使得 $\sum_{x_i\in S_0} x_i = W \Rightarrow \sum_{x_i\in S_0\cup\{x_{n+2}\}} x_i = S+1$ 。而$\sum_{i=1}^{n+2} x_i = 2S+2$, 说明我们可以找到$S_1 = S_0\cup\{x_{n+2}\}, S_2=S-S_1$满足（1）和（2）的条件。

###  8-28

**We will call a set $I ⊂V$ strongly independent if, for any two nodes $v,u∈I$, the edge $(v,u)$ does not belong to E, and there is also no path of two edges from u to v, that is, there is no node w such that both $(u,w)∈E$ and $(w,v)∈E$. The Strongly Independent Set Problem is to decide whether G has a strongly independent set of size at least k.** 

**Prove that the Strongly Independent Set Problem is NP-complete.**

proof:

1. Strongly Independent Set  $\in$ NP

   给定一个set，只需要验证任意两个节点$u,v$是否相连，以及是否有公共的邻居就可以判断该set是否是 Strongly Independent Set，可以在多项式时间完成验证。

2. Independent Set $≤_P$ Strongly Independent Set 

   对于图G中的每条边$(u,v)$, 通过添加节点w，构造新的两条边$(u,w_{uv}),(w_{uv},v)$, 并将所有$w_{ij}$ 两两相连，得到图$G'$。构造可以在多项式时间内完成。

   可以得到G中的Independent Set等价$G'$的Strongly Independent Set。

   $\Rightarrow$ 对于 G 中的 Independent Set，由于在$G'$ 任意边添加了节点w，必然满足也没有公共邻居的条件，是 Strongly Independent Set。

   $\Leftarrow$ $G'$的 Strongly Independent Set 必然不包括任意$w_{uv}$, 因为$w_{uv}$与$G'$中任何节点要么相连 ( 直接相连的u, v )，要么可以通过公共节点$w_{xy}$ 相连（任意节点x, y）。显然这个set是G中的 Independent Set。

   

### 8-31

 **Given an undirected graph G=(V,E), *a feedback set* is a set X⊆V with the property that G−X has no cycles. The *Undirected Feedback Set Problem* asks: Given G and k, does G contain a feedback set of size at most k? Prove that Undirected Feedback Set is NP-complete.**

proof:

1. Undirected Feedback Set $\in$ NP

   给定一个无向图G和feedback set X，只需要在G-X上运行DFS检查是否存在环就可以判断X是否是UFS，可以在多项式时间完成验证。

2. Vertex Cover $≤_P$ Undirected Feedback Set

   对于无向图G(V,E), 对每一条边(u,v)，构造新的四条边$(u,w_{uv}^{1}),(u,w_{uv}^{2}),(w_{uv}^{1},v),(w_{uv}^{2},v)$, 形成新的图$G'$.可以发现图G中的vertex cover就是$G’$中的undirected feedback set.

   $\Rightarrow$ 设X是G中的vertex cover，每条边都和X中至少一个节点相连，即G‘中每个环上至少有一个点在X中，G’−X 没有环，X是undirected feedback set。

   $\Leftarrow$ 设X是undirected feedback set，对每个由$u,v,w_{uv}^{1},w_{uv}^{2}$构成的环，X应该至少含有四个点其中一个，通过$X+\{u\;or\;v\}-\{w_{uv}^{1\;or\;2}\}$构造一个不含有$w_{uv}^{1\;or\;2}$的set，此时X应该至少含有$u,v$中的至少一个，所以X是G上的vertex cover。

   构造可以在多项式时间内完成。

