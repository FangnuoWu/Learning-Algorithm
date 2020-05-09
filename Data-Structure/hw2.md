## Homework 2

> @SE121  518021911015 吴方诺

### task1

**证明对于任意等价的BST树（n个节点），都能通过O(n)次旋转（zig/zag）相互转化。(任意一次zig/zag都能增加右/左子树的高度)；**

将BST树从根节点开始向右的每一个连续的右儿子看作一条链，每一个这条链上节点的左子节点（如果有的话）都可以通过一次旋转进入这条链且这条链上的本来节点不会变少（如下图）。不在这条链上的节点最多有n-1个（根节点一定在这条链上），最多n-1次旋转可以将任意BST树变为一条链，由左旋右旋对称可知，最多n次旋转也可以将这条链变成任意一颗可以转化成这条链的BST。由于等价BST的中序遍历相同，即对应的链相同，所以任意等价BST都能通过 `O(n) ` 次旋转相互转化。

### task2

对于如下一棵splay树，依次访问节点3,9,1,给出bottom-up双层旋转的调整过程

![splay_tree.png](https://oc.sjtu.edu.cn/files/321960/download?download_frd=1&verifier=zd2UpBPPumVt8JjvjyALrdKyOUVv9xfIt2TmMRq2)

调整过程：

![image-20200426140315005](https://gitee.com/fangnuowu/img/raw/master///20200509223300.png)