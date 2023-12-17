#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
private:
    stack<int> inputStack;
    stack<int> outputStack;

public:
    // Конструктор класу
    MyQueue() {}

    // Переміщення елемента у кінець черги
    void push(int x) {
        inputStack.push(x);
    }

    // Вилучення елемента з початку черги та його повернення
    int pop() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        int frontElement = outputStack.top();
        outputStack.pop();
        return frontElement;
    }

    // Отримання елемента на початку черги
    int peek() {
        if (outputStack.empty()) {
            while (!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }

        return outputStack.top();
    }

    // Перевірка, чи черга порожня
    bool empty() {
        return inputStack.empty() && outputStack.empty();
    }
};

int main() {
    // Створення об'єкта MyQueue
    MyQueue myQueue;

    // Виклики методів для вказаних операцій
    myQueue.push(1);
    myQueue.push(2);
    cout << "peek: " << myQueue.peek() << endl;
    cout << "pop: " << myQueue.pop() << endl;
    cout << "empty: " << (myQueue.empty() ? "true" : "false") << endl;

    return 0;
}
