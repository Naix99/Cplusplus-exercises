#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

/* this is a code for simulating a queue with two stacks.
Took me a LONG WHILE to figure how to do this effieciently.
The first intuition was to use the "middle" of the two stacks to simulate a position of the queue,
and moving back and for by moving objects between stacks, which was incredible ineficient.
Instead we use the second stack as a "buffer", and the first stack to add elements. When we want to 
deque an element and the buffer is empty we transfer everything to the buffer, so the 
 elements are ordered with the oldest on top. */
class Queue{
    private:
    stack<int> leftstack;
    stack<int> rightstack;
    public:
    bool isempty(){
        return (leftstack.empty() && rightstack.empty());
    }
    bool size(){
        return leftstack.size() + rightstack.size();
    }
    void add(int x){
        leftstack.push(x);
    }
    int front(){
        if (rightstack.empty()){
            while (!leftstack.empty()){
                rightstack.push(leftstack.top());
                leftstack.pop();
            }
        }
        return rightstack.top();
    }
    void deque(){
        if (rightstack.empty()){
            while (!leftstack.empty()){
                rightstack.push(leftstack.top());
                leftstack.pop();
            }
        }
        rightstack.pop();
    }
};


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int Q; int type; int num;
    cin >> Q;
    Queue cola;
    for (int i =0; i<Q; i++){
        cin >> type;
        switch(type){
            case 1:
                cin >> num;
                cola.add(num);
                break;
            case 2:
                if (!cola.isempty()){
                cola.deque();
                break;
                }
            case 3:
                if (!cola.isempty()){
                cout << cola.front() << endl;
                }
                break;
        default: continue;
        }
    }
    return 0;
}
