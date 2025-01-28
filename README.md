# 队列（Queue）实现示例

这是一个使用C语言实现的循环队列示例。

## 功能特点

- 实现了基本的队列操作（入队、出队、判空、判满等）
- 使用循环数组实现
- 支持最小队列大小为5
- 队列容量可自定义

## 使用示例

主函数展示了队列的基本用法：

```c
int main(void)
{
    Queue Q;
    Q = CreateQueue(50);    // 创建容量为50的队列
    int i;
    for(i = 0; i < 49; i++) // 连续入队49个元素
    {
        Enqueue(i, Q);
    }
    PrintQueue(Q);          // 打印队列中所有元素
}
```

## 主要函数

- `CreateQueue(int MaxElements)`: 创建指定大小的队列
- `Enqueue(ElementType X, Queue Q)`: 入队操作
- `Dequeue(Queue Q)`: 出队操作
- `PrintQueue(Queue Q)`: 打印队列中的所有元素
- `IsEmpty(Queue Q)`: 判断队列是否为空
- `IsFull(Queue Q)`: 判断队列是否已满

## 注意事项

- 队列大小必须大于等于5
- 使用完队列后需要调用`DisposeQueue`释放内存
- 队列满时无法继续入队
- 队列空时无法执行出队操作
