#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    // --- part 1: stack operations ---
    // initialize a stack
    stack<int> intStack;

    // push elements into the stack
    for (int i = 1; i < 6; i++) {
        intStack.push(i * 5);
    }



    // --- part 2: transfer from stack to queue ---
    // initialize a queue
    queue<int> intQueue;

    // transfer elements
    for (int i = 0; i < 5; i++) {
        cout << intStack.top() << endl;
        intQueue.push(intStack.top());
        intStack.pop();
    }



    // --- part 3: queue operations ---
    // print queue contents
    for (int i = 0; i < 5; i++) {
        cout << intQueue.front() << endl;
        intQueue.pop();
    }

    return 0;
}
