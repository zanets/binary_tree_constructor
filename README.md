# binary_tree_constructor
A constructor to build a binary tree by in-order and pre-order.

Use in-order and pre-order to build a binary tree is a medium level
Leetcode problem. I thought it is useful to build a tool that can
construct a binary tree so I can explorer more about binary tree.

If you want to use it, clone with submodule and use cmake.

```bash
git clone --recursive git@github.com:zanets/binary_tree_constructor.git
cd binary_tree_constructor
cmake .
make
```

You can add more test case by add an array to test.json with pre-order at 0-index and in-order at 1-index. For example, 
```
[ [1,2,4,5,3], [4,2,5,1,3] ]
```
generates a binary tree like this

```
        1
     2     3
   4   5
```


