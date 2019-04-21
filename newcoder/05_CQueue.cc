// This file is part of my coding practice, a lightweight C++
// solution for newcoder program practice.
//
// For all of files in the coding folder, I check the rightness
// not only by the case test online, but also by my offline IDE
// Microsoft Visual Studio 2010 as well when I write on windows
// 7 64-bit platform or by g++5.4 when I am on linux platform.
// 
// If there are some questions, please send me an email: 
// Phil <phillee2016@163.com> or feel free to create an issue.

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

class Myqueue
{
public:
	/* 题目描述：用两个栈来实现一个队列，完成队列的Push和Pop操作。
	 *			队列中的元素为int类型。
	 *
	 */	
	// 以stack1为入队通道，所有元素都压入到队中
    void push(int node) {
    	stack1.push(node);
    }

    // 为了实现先进先出的功能，将stack2作为缓冲地带，先将队列中的元素
    // 从stack1中弹出并压入到stack2中，此时刚好满足先进的元素在栈顶
    // 从stack2中弹出的刚好是队列头处的元素，因此满足题意
    int pop() {
    	int res;
        int tmp;
        if (stack2.empty()) {
        	while (!stack1.empty()) {
                tmp = stack1.top();
                stack2.push(tmp);
                stack1.pop();
            }
        }
        res = stack2.top();
        stack2.pop();

        return res;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(int argc, char **argv) {

	Myqueue s;
	printf("Now let us input some integer:\n");
	int num, tmp;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		scanf("%d", &tmp);
		s.push(tmp);
	}

	printf("Now let us see the pop order:\n");
	for (int i = 0; i < num; i++) {
		tmp = s.pop();
		printf("%d  ", tmp);
	}
	printf("\n");
	return 0;
}