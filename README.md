### leetcode solutions

记录我的一些 leetcode 题解。

### 典型解法

* 二分查找
    * [34. Find First and Last Position of Element in Sorted Array](34_search_range.cpp)：二分查找的三个模板。
* 快速排序
    * [912. Sort an Array](912_sort_an_array.cpp)
    * [215. Kth Largest Element in an Array](215_kth_largest_element_in_array.cpp)：快排分区法求第 K 大元素。
* 堆排序
    * [215. Kth Largest Element in an Array](215_kth_largest_element_in_array_2.cpp)：最大堆求第 K 大元素
* 二叉树
    * [98. Validate Binary Search Tree](98_validate_binary_search_tree.cpp)：（迭代）中序遍历二叉树。
    * [145. Binary Tree Postorder Traversal](145_binary_tree_postorder_traversal.cpp)：（迭代）后序遍历二叉树。
    * [102. Binary Tree Level Order Traversal   ](102_binary_tree_level_order_traversal.cpp)：二叉树层序遍历（队列辅助）。
    * [105. Construct Binary Tree from Preorder and Inorder Traversal](105_construct_binary_tree_from_preorder_inorder_traversal.cpp)：根据前序和中序数组还原二叉树。
    * [124. Binary Tree Maximum Path Sum](124_binary_tree_maximum_path_sum.cpp)：二叉树最大路径和。
* 字符串
    * [8. String to Integer (atoi)](8_atoi.cpp)：字符串转整数。
* 队列和栈
    * [225. Implement Stack using Queues](225_implement_stack_using_queues.cpp)：用队列实现栈。
* 动态规划（DP）
    * [1143. Longest Common Subsequence](1143_longest_common_subsequence.cpp)：经典，最长公共子序列。
    * [128. Longest Consecutive Sequence]()：最长上升序列。
    * [322. Coin Change](322_coin_change.cpp)：零钱兑换，简单动态规划。
* BFS
    * [365. Water and Jug Problem](365_water_and_jug_problem.cpp)：典型 BFS 应用（超时了，因为这题需要用[数学公式](365_water_and_jug_problem_2.cpp)求解）。
    * [542. 01 Matrix](542_01_matrix.cpp)：BFS 寻找距离。
* DFS
    * [695. Max Area of Island](695_max_area_of_islang.cpp)：典型的 DFS 应用。
* 双指针
    * [876. Middle of the Linked List](876_middle_linked_list.cpptouch)：快慢指针找中间节点