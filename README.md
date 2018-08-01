#  
## Data Structure  
## Problem analysis log  
<a id="contents"/>  
  
[349.Intersection-of-Two-Arrays](#p349)  
[538.Convert-BST-to-Greater-Tree](#p538)  
  
### 349.Intersection-of-Two-Arrays  
[Descpription](https://leetcode.com/problems/intersection-of-two-arrays/description/)<a id= "p349"/>
[Back to Cotents](#contents)  
比较简单能想到，如果暴力操作，复杂度O(mn)。若采用数组储存信息，则空间复杂度O(n)，时间复杂度O(n + m)。但要做到精确的O(n)空间复杂度，还得哈希一下，有点麻烦，直接开个最小值到最大值的数组解决了。  


### 538.Convert-BST-to-Greater-Tree  
[Description](https://leetcode.com/problems/convert-bst-to-greater-tree/description/)<a id="p538"/>  
[Back to Cotents](#contents)  
容易想到，一个节点需要加上其*右子树所有的节点*和*父节点*(如果是左子树)。初步想法是从叶节点递归计算，先计算*右子树所有的节点*，再计算*父节点*。  
简单地说，两步：
1. 从叶节点开始，所有右子树值加给父节点。O(n)
2. 从根节点开始，所有父节点的值加给左子树。O(nlogn)
此算法能够得到正确结果，但复杂度较高，因为在第一步求所有右子树节点和的时候存在大量的重叠子问题。考虑到此问题的有序性。我们可以维持一个sum，从最大到最小更新sum并更新子树节点，同样采用递归的思路:  
1. 若当前节点有右子，则进入递归右子。
2. 若当前节点没有右子or右子处理完毕，则说明当前节点是目前最大的节点。更新value和sum。
3. 若当前节点有左子，则进入递归左子。
只需遍历一遍BST，复杂度O(n)。


