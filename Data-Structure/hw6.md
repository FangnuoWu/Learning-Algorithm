

# Homework 6

> @SE121  518021911015 吴方诺

### Task1

给定字符串 T=BABCDABCDABEABCDABD;P=ABCDABD,请给出P的next表，并简要给出匹配过程(为了简单，可以给出匹配过程中字符匹配失败且next[j]不为0 时T,P,i,j的状态)。

- next表 

  |        | 0    | 1    | 2    | 3    | 4    | 5    | 6    |
  | ------ | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
  | P[]    | A    | B    | C    | D    | A    | B    | D    |
  | next[] | -1   | 0    | 0    | 0    | 0    | 1    | 2    |

- 匹配过程

  ![image-20200411193606466](https://gitee.com/fangnuowu/img/raw/master///20200509223425.png)

### Task2

编写一段程序，随机生成10^4 ,10^5, 10^6个随机数，并分别在这三者中，分别使用快排和linearSelect()方法，选择出第100大的数字(需给出)，并给出三者的运行时间（可以表格形式给出），给出linearSelect()关键代码并解释。

随机数：0-INT_MAX

| 方法 | quickSelect() |           | linearSelect() |           |
| ---- | ------------- | --------- | -------------- | --------- |
|      | 第100大的数   | 运行时间  | 第100大的数    | 运行时间  |
| 10^4 | 300           | 5.518ms   | 297            | 7.092ms   |
| 10^5 | 32            | 18.187ms  | 32             | 83.177ms  |
| 10^6 | 3             | 0.172322s | 3              | 0.811344s |

linearSelect()代码

```c++
#define Q 5

/* 数组规模不大时蛮力求第k大的数 */
int trivialSelect(int* A, size_t n, size_t k) {
	sort(A, A + n);
	return A[k - 1];
}

/* 寻找乱序数组的中位数 */
int findMedian(int* A, size_t n){
	sort(A, A + n);
	return A[n/2];
}

/* linearSelect：寻找乱序数组中第k大的值， n为数组长度 */
int linearSelect(int* A, size_t k, size_t n) {
	/* 递归基，数组规模不大时蛮力求第k大的数 */
	if (n <= Q)return trivialSelect(A, k, n);

	size_t i;
	for (i = 0; i < n / Q; i++) /* 将A均匀划分为 n/Q 个子序列 */
		median[i] = findMedian(A + i * Q, Q); /* 寻找该序列中位数并计入median */
	if (i * Q < n) /* 对最后不满Q的数组 */
		median[i] = findMedian(A + i * Q, n % Q);
	int medOfMed = findMedian(median, (n + 4) / Q); /* 寻找中位数的中位数 */

	/* 根据相对medofMed的大小，将A中元素划分为三个子集 */
	int l = 0, e = 0, g = 0; /* 记录三个子集的大小，子集数组为全局变量 */
	for (size_t i = 0; i < n; ++i) {
		if (A[i] < medOfMed) {L[l] = A[i]; l++;}
		else if (A[i] > medOfMed) {G[g] = A[i]; g++;}
		else {E[e] = A[i]; e++;}
	}
	/* L足够长，第k个元素与子序列E、G的存在与否无关，将其剪除在L中做选择 */
	if (l >= k) return linearSelect(L, k, l); 
	/* L<k，加入E后可以覆盖k，E中每个元素必然都是要寻找的对象，直接返回 medOfMed */
	else if (l + e >= k) return medOfMed;
	/* L和E长度总和仍不够长，第k个元素必然在G中且应该位于第 k-l-e 个 */
	else return linearSelect(G, k - l - e, g);
}
```

