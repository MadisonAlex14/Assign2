// Question2.cpp Part 2 of the code, implementing stack of intergers

#include <iostream>
#include <vector>

class Stack {
private:
	std::vector<int> elements;

public: 
	// checking if empty
	bool isEmpty() const {
		return elements.empty();
	}
	// Push -> stack
	void push(int value) {
		elements.push_back(value);
	}
	// Pop -> stack
	void pop() {
		if (!isEmpty()) {
			elements.pop_back();
		}
	}
	// Get the top element 
	int top() const {
		if (!isEmpty()) {
			return elements.back();
		}
		return 0;
	}
	// Average
	double average() const {
		if (isEmpty()) {
			return 0.0;

		}

		int sum = 0;
		for (int element : elements) {
			sum += element;
		}
		return static_cast<double>(sum) / elements.size();
	}
};

int main() {
	Stack myStack;
	std::cout << "Is the stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << std::endl;

	myStack.push(5);
	myStack.push(10);
	myStack.push(15);

	std::cout << "Top of the stack: " << myStack.top() << std::endl;

	myStack.pop();

	std::cout << "After popping, top of the stack: " << myStack.top() << std::endl;

	std::cout << "Average value of stack elements: " << myStack.average() << std::endl;

	return 0;
}