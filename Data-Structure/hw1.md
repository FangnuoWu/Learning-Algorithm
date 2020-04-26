## Homework 1

> @SE121  518021911015 吴方诺

### 1. 计算跳表空间复杂度

#### 1.1 平均空间复杂度

第 k 层的 key 生长到第 k+1 层的概率为 $1-p$ 记作 $q$，各塔的高度 $h$ 满足：
$$
\operatorname{Pr}\left(\begin{array}{c}h = k\end{array}\right)=q^{k-1} \cdot(1-q)
$$
塔高的期望:   

$$
E[h]=\sum_{k=1}^{\infty} k\cdot q^{k-1} \cdot(1-q)=\frac{1-q}{q} \sum_{k=1}^{\infty} k q^{k}=\frac{1-q}{q} \lim _{n \rightarrow \infty} \sum_{k=1}^{n} k q^{k}
$$
其中:
$$
\begin{aligned}
\lim _{n \rightarrow \infty} \sum_{k=1}^{n} k q^{k} &= \lim _{n \rightarrow \infty} \frac{q\left(1-q^{n}-n q^{n}+n q^{n+1}\right)}{(1-q)^{2}} \\
&=\frac{q}{(1-q)^{2}}\left(\lim _{n \rightarrow \infty} 1-\lim _{n \rightarrow \infty} q^{n}-\lim _{n \rightarrow \infty} n q^{n}+\lim _{n \rightarrow \infty} n q^{n+1}\right) \\
&=\frac{q}{(1-q)^{2}}(1-0-0+0) \\
&=\frac{q}{(1-q)^{2}}
\end{aligned}
$$
化简可以得到，塔高的期望: 

$$
E[h]=\frac{1}{1-q} = \frac{1}{p} = 2
$$
于是，所有节点的期望的总数(即每个塔高度的和)为：
$$
E\left(\Sigma_{k}\left|h_{k}\right|\right)= \sum_{k=1}^{n}E[h_{k}] = 2n
$$
**平均空间复杂度为**：  $O(n)$



#### 1.2 跳表的层数期望

由定义：事件 E 以高概率发生是指：对任意 $\alpha \geq 1$, 可以找到一个常数让 $E$ 以至少 $1-O\left(1 / n^{\alpha}\right)$ 的概率发生

设跳表的高度为 $h$,第 $i$ 个塔 $(i = 1,2,...,n)$ 高度为 $h_{i}$,
$$
\operatorname{Pr}\{ h>\operatorname{clog} n\} \leqslant n \operatorname{Pr}\left\{h_{i}>c \log n\right\}=n \cdot\left(\frac{1}{2}\right)^{c \lg n}
=\frac{1}{n^{c-1}}
$$
所以跳表层数为 $O(logn)$ 的概率极大，即:

**跳表的层数期望为:**  $O(logn)$





### task2：Bloom Filter
#### 2.1 实现方案
1. 哈希函数:
   
   |     order     |    1     |   2    |    3    |   4    |
   | :-----------: | :------: | :----: | :-----: | :----: |
   | hash function | BKDRHash | APHash | DJBHash | JSHash |
   
2. 哈希表的长度: 10M 和 100M

3. 生成数据的方式：
   利用 `random` 库生成均匀分布在 (`0`, `UINT32_MAX`) 上的数据。

   ```c++
    #include <random>
    default_random_engine e;
    uniform_int_distribution<unsigned> u(0, UINT32_MAX);

    char* data = new char[32];
    _itoa_s(u(e), data, 32, 10);
   ```
   
   插入数据前查询是否存在来判断假阳性率，每插入10个数据将相应的结果写入文件。

#### 2.2 比较结果

读取文件中的数据，利用 python 将两种类型所得的数据画在同一张图上。

核心代码：

```python
data = np.loadtxt("100M.txt") //第一列为总插入数，第二第三列对应总插入数的假阳性节点个数
pow = 2**20 //化横轴单位为MB
L1,= plt.plot(data[:,0]/pow,data[:,1]/data[:,0],linewidth=1,color="r")
L2,= plt.plot(data[:,0]/pow,data[:,2]/data[:,0],linewidth=1,color="b",linestyle='--', dashes=(10, 10))
```



选取哈希表的长度为10M时：
<img src="https://s2.ax1x.com/2020/03/07/3XmAiT.png" alt="3XmAiT.png" style="zoom: 30%;" />

选取哈希表的长度为100M时：
<img src="https://s2.ax1x.com/2020/03/07/3XI6Xt.png" alt="3XI6Xt.png" style="zoom: 30%;" />

可见两种 bloom filter 的假阳性率十分接近。

由于数据选取的比较大，在图上看起来两种 bloom filter 的假阳性率几乎相等。统计了一下文件中实际的数据，总体来说第一种方法的假阳性率一直比第二种高一些。

事实上，由理论分析：
									Bloom Filter的假阳性率 $f=\left(1-\left(1-\frac{1}{m}\right)^{k n}\right)^{k} \approx\left(1-\mathrm{e}^{-\frac{k n}{m}}\right)^{k}$

设第一种 filter 的大小为 $m$，第二种则为 $2m$. 此处第一种的假阳性率 		
$$
f_{1} = f_{11}\cdot f_{12}\approx\left(1-\mathrm{e}^{-\frac{2 n}{m}}\right)^{2}\cdot \left(1-\mathrm{e}^{-\frac{2 n}{m}}\right)^{2} = \left(1-\mathrm{e}^{-\frac{2 n}{m}}\right)^{4}
$$
第二种的假阳性率
$$
f_{2} \approx \left(1-\mathrm{e}^{-\frac{4 n}{2m}}\right)^{4}=\left(1-\mathrm{e}^{-\frac{2 n}{m}}\right)^{4}
$$
两者相同。