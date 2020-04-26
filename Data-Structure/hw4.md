## Homework 4

> @SE121  518021911015 吴方诺

### task 1

编写一段程序，比较红黑树在随机生成的节点数为N=10^4, 10^5, 10^6的树中进行随机插入的比较，并给出树的高度。

i) 对于节点数为N的树进行N/100次随机插入操作，给出插入的时间。

ii) 给出插入操作中双红修正的总次数。

| 节点数     | 高度 | 双红修正总次数 | 插入时间 |
| ---------- | :--: | :------------: | :------: |
| $N = 10^4$ |  8   |       84       | 0.650ms  |
| $N = 10^5$ |  10  |      1078      | 1.235ms  |
| $N = 10^6$ |  12  |     11094      | 13.159ms |

### task 2

i) 对于如下一段数字 $(10,12),  (1, 2),  (4, 7),  (1, 20), (25, 27), (29, 22),  (24, 31),  (4,15)$建立一颗2-d树，给出建树后从根节点开始从左至右顺序每个节点存储的数据.形式$(10，12) - (x,x) - (x,x)$。

$(1, 2) - (4,7) - (1,20) - (4,15) - (10,12) - (29,22)- (24,32) - (25,27)$

ii) 给出若确定中位点时间复杂度能够在线性时间内确定，则 kd-树构造算法总体时间复杂度可被优化至$O(nlogn)$的说明。

```c++
#构造的伪代码为
if (p={p}) return createleaf(p) 					    	#O(1)
root = createKDNode();     									#O(1)
root->splitDirection = (depth&1)?H:V;						#O(1)  
root->splitLine = median(root->splitDirection,p);   		#设定为O(n)
(P1,P2) = divide(P,root->splitDirection,root->splitLine)    #O(1)
root->lc = createKdTree(P1,depth+1);
root->rc = createKdTree(P2,depth+1);
```

每个子树都可以在常数时间内完成，设节点数为n的树所需要的时间为 $T(n)$

可以写出递推式: 
$$
T(n)=\left\{\begin{array}{ll}
1 & n=1 \\
2 T(n / 2)+n & n>1
\end{array}\right.
$$

$$
T(n) =2 \cdot T(n / 2)+n =2\left[2\cdot T\left(n / 2^{2}\right)+\frac{n}{2}\right]+n =\cdots=2^{k}\cdot T(n /2^{k})+k n
$$

$$
T\left(\frac{n}{2^{k}}\right)=T(1)\Rightarrow n=2^{k}, k=\log n
$$

$$
T(n) =2^{\log n} T\left(n / 2^{\log n}\right)+n \log n = n+n \log n
$$

所以复杂度为$O(nlogn)$