### 7-1

（a）<img src="upload\image-20200520160411333.png" alt="image-20200520160411333" style="zoom:50%;" />

- A={s}, B={u, v, t}
- A={s,v}, B={u, t}
- A={s, u, v}, B={t}

(b)     <img src="upload\image-20200520160529031.png" alt="image-20200520160529031" style="zoom:50%;" />

 minimum capacity : 4

### 7-2

<img src="upload\image-20200520160633665.png" alt="image-20200520160633665" style="zoom:67%;" />

**(a) What is the value of this flow? Is this a maximum (s,t) flow in this graph?** 

- the value of this flow: 18
- no

**(b) Find a minimum s-t cut in the flow network, and also say what its capacity is.**

A={s, the top node} cap(A,V-A)=21

### 7-10

**Suppose we pick a specific edge $e^∗\in E$ and reduce its capacity by 1unit. Show how to find a maximum flow in the resulting capacitated graph in time O(m+n).**

**answer:**

Let $e^*=(u,v)$, if $e^*$ is not on the original given maximum flow, then reduce its capacity will not have any effect, so we assume that this edge is on the original given flow.

We find the path from s to t which pass $e^* $ on the original flow, reduce the flow on these paths by 1 to satisfy the capacity requirement of $e^*$. Since the original  flow f is acyclic, this path will have at most n nodes, so it can finish in O(n).

Now we get a new flow $f'$, whose value is exactly one unit less than value of original flow $f$. Given that all capacities are integer value, any flow will also be integer-valued. If $f'$ is not the max flow, the value of max flow must be one unit greater than $f'$, we do one `Augment()` operation on the residual graph, if we can find an augmenting path, than we find the max flow, otherwise $f'$ is the max flow. This operate can be finish within O(m).

The total time is O(m+n).

### 7-11

**Forward-Edge-Only Algorithm:**

*There is an absolute constant b > 1 (independent of the particular input ﬂow network), so that on every instance of the Maximum-Flow Problem, the Forward-Edge-Only Algorithm is guaranteed to ﬁnd a ﬂow of value at least 1/b times the maximum-ﬂow value (regardless of how it chooses its forward-edge paths).* 

**Decide whether you think this statement is true or false, and give a proof of either the statement or its negation.**

**answer:**

$\forall b>1$, we can consruct a graph which can find a flow whose value is less than 1/b times the maximum-ﬂow value.

<img src="https://gitee.com/fangnuowu/img/raw/master///20200526094245.png" alt="example" style="zoom:67%;" title="fig1"/>

This graph contain (b+1) verticles out of s and (b+1) verticles go into t, every capacity is 1. If the first path is like the red path in the picture, as all these edges are delete in $G'$, we can only find this one path, so the flow is 1. But we can easily known that the max flow we can find is b+1, this value is less than $\frac{1}{b}\cdot(b+1) = 1 +\frac{1}{b}$.



### 7-12

 **Consider the following problem. You are given a flow network with unit capacity edges: It consists of a directed graph $G=(V,E)$, a source $s∈V$, and a sink $t∈V$; and $c_e=1$ for every $e∈E$. You are also given a parameter k.** 

**The goal is to delete k edges so as to reduce the maximum s-t flow in G by as much as possible. In other words, you should find a set of edges $F ⊆E$ so that $|F|=k$ and the maximum $s-t$ flow in $G'=(V,E−F)$ is as small as possible subject to this. Give a polynomial-time algorithm to solve this problem.**

**algorithm:** 

- Find the min cut (A,B) and delete k edges from f edges out of A.
   (If the number of edges out of A f is less than k, delete all edges). 
- Now the resulting graph has a max flow at most $max(f-k,0)$(which is clearly as at most $max(f-k,0)$ path from s to t). 
- We claim that this flow is the maximum $s-t$ flow.

**correctness:**

We can prove the algorithm to be true by proving that the maximum $s-t$ flow is at least $max(f-k,0)$ , namely, the minimum cut is at least $max(f-k,0)$.

Consider any cut (A, B) of the new graph $G'$. There are at least f edges out of A in G, and at most k of them have been deleted, so there are at least $f-k$ edges out of A in G'. Thus, the min cut in G' has value at least $max(f-k,0)$.

**time complexity:**

find the min cut can be done by:

**1)** Run Ford-Fulkerson algorithm and consider the final residual graph. O(mn), as c=1

**2)** Find the set of vertices that are reachable from the source s in the residual graph. O(n)

**3)** All edges which are from a reachable vertex to non-reachable vertex are minimum cut edges. 

This algo can finish in O(mn)