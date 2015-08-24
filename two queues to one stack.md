###两个队列实现栈

**思路:**

    q1是专职进出栈的，q2只是个中转站

    入栈：直接入队列q1即可
    出栈：把q1的除最后一个元素外全部转移到队q2中,然后把刚才剩下q1中的那个元素出队列。之后把q2中的全部元素转移回q1中
    
**代码示例：**

    void Push(Queue *q1, Queue *q2, int k)
    {
            EnQueue(q1, k);
    }

    int  Pop(Queue *q1, Queue *q2)
    {
        int tmp;
        if(IsQueueEmpty(q1) == 1)
        {
           printf("Stack Empty!\n");
        }
        else
        {
            while(SizeOfQueue(q1) != 1)
            {
                EnQueue(q2, DeQueue(q1));
            }
            tmp = DeQueue(q1);
            while(IsQueueEmpty(q2) == 0)
            {
                EnQueue(q1, DeQueue(q2));
            }
            return tmp;
        }
    } 

