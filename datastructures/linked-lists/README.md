## Linked Lists

The linked lists is a linear data structure, in which the elements are not stored at contiguous memory location like the arrays. The elements in a linked list are linked using pointer.

```cpp
[data | ->] [data2 | ->] ... -> NULL;
```

In simple words, a linked list consists of nodes where each node has a field for data and a reference (link) for the next node in the chain.

#### Why Linked Lists?

1. The size of array is fixed. So we must know the upper limit on the number of elements in advance. Also the memory allocation is equal to the upper limit irrespective of the usage.
2. Insert an element in the middle of an array is expensive because we need to shift the elements to create a room for the new element.

#### Advantages over arrays

1. Dynamic size
2. Ease insert and deletion

#### Drawbacks

1. Randon access is not allowed. We have to access elements sequentially from the first node. So we cannot do binary search with linked lists efficiently with its default implementation.
