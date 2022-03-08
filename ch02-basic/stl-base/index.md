### STL 常用函数

1. `min(x, y)`求最小值
2. `max(x, y)` 求最大值
3. `swap(x, y)` 交换两个元素
4. `find(begin, end, x)` 第一个值为 x 的指针；没找到返回 end
5. `count(begin, end, x)` 返回 [begin, end) 值为 x 的元素个数
6. `reverse(begin, end)` 翻转
7. `random_shuffle(begin, end)` 洗牌-随机打乱
8. `unique(begin, end)` 连续的相同元素压缩成一个，返回去重后的尾指针。不连续不会被压缩（一般先排序后去重）
9. `fill(begin, end, val)` 用 val 填充区间
10. `sort(begin, end, compare)` 区间排序，默认升序；`compare(a, b)` 返回 a < b 表示升序，即 a 在 b 前面
11. `stable_sort(begin, end, compare)` 稳定排序
12. `lower_bound/upper_bound(begin, end, x)` 二分查找第一个满足条件元素，返回元素指针
13. `nth_element(begin, begin + k, end, compare)` 返回第 k 小元素，左边小于等于，右边大于等于；不保证其他元素有序
14. `next_permutation(begin, end)` 字典排序的下一个排列; 循环可得到全排列 [1, 2, 3]-> [1, 3, 2] ... -> [3, 2, 1]，完全全排列需要从升序开始
15. `pre_permutation(begin, end)` 字典排序的上一个排列
