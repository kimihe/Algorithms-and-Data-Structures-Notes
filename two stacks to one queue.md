### 如何用两个堆栈模拟实现一个队列?  如果这两个堆栈的容量分别是m和n（m>n)，你的方法能保证的队列容量是多少？

**代码思路：**

    #include<iostream>
    #include<stack>
    using namespace std;
    stack<int> s1,s2;
    for(i=1;i<=3;i++)
        s1.push(i);
    while(!s1.empty())
    {    
        s2.push(s1.pop());
    }
    while(!s2.empty())
        s2.pop();
        
**分析：**

**两个栈，一个作为存储栈，一个作为服务栈。**
**元素先压入存储栈，再被逐一弹出逐一压入服务栈，就实现了先来先服务的结构。**

**如果用N作为存储栈，M作为服务栈，**
**则M中一次最多只能被压入N个元素，N中一次也能被压入N个元素，M不为空时不允许被压入元素,容量2N。**

**如果M作为存储栈，N作为服务栈，**
**N中一次最多被压入N个元素，M中最多被压入M个元素，N不为空时不允许被压入元素，N为满时M不允许弹出，容量M+N。**