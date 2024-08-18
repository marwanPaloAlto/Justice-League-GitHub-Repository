#include <iostream>
#include <stack>
#include <string>
using namespace std;
class Queue {
private:
    stack<string> stack1, stack2;

public:
    void enqueue(const string& item) {
        // Push the item into the first stack
        stack1.push(item);
    }

    void dequeue() {
        // Move elements from stack1 to stack2 if stack2 is empty
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        // Pop the top element from stack2
        if (!stack2.empty()) {
            stack2.pop();
        } else {
            cout << "Queue is empty" << endl;
        }
    }

    string front() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        return stack2.empty() ? "Queue is empty" : stack2.top();
    }

    bool isEmpty() {
        return stack1.empty() && stack2.empty();
    }
};
int main() {
    Queue batmanQueue;

    // Enqueue Batman's weapons and shields
    batmanQueue.enqueue("Batarang");
    batmanQueue.enqueue("Grapple Gun");
    batmanQueue.enqueue("Explosive Gel");
    batmanQueue.enqueue("Batclaw");
    batmanQueue.enqueue("Cape Glide");
    batmanQueue.enqueue("Smoke Pellet");

    // Display the contents of the queue
    while (!batmanQueue.isEmpty()) {
        cout << batmanQueue.front() << endl;
        batmanQueue.dequeue();
    }

    return 0;
}
