###问题：堆栈顺序存储的另一种实现

**有人给出了堆栈用数组实现的另一种方式，即直接在函数参数中传递数组和top变量（而不是两者组成的结构指针），其中Push操作函数设计如下。这个Push函数正确吗？为什么？**

	#define MaxSize 100
	ElementType S[MaxSize];
	int top;
	void Push(ElementType *S, int top, ElementType item)
	{   if (top==MaxSize-1) {

	          printf(“堆栈满”);  return;
	    }else {
	          S[++top] = item;
	          return;
	    }
	}


**分析：**
**1.void Push(ElementType *S, int top, ElementType item)
Push方法形参int top是值传递，在方法内对top修改的影响只对方法内top变量有效，方法体之外的top变量没有变化。如果要获取当前栈顶元素的位置，那么只能通过过滤条件值来遍历栈内所有元素来获取当前栈顶元素的索引位置了。
这个Push函数的参数表中定义了和全局变量top重名的本地变量top，结果产生屏蔽，即对top的++操作是针对该本地变量的，不会改变原全局变量的值。**

**2.如果仍想使用这种方式，则应该在Push参数表中（或函数体中）不定义变量top，这样就能直接访问到全局的top了；或者使用指针，在参数表中定义int* top，将原top地址传递进函数(使用C++中的引用也可以达到这个效果：int& top)。**
