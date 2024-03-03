// Assignment 2, Question 1 code - Madison Alexander
#include <iostream>

template <typename Item_Type>
class Single_Linked_List {
private:
	struct Node {
		Item_Type data;
		Node* next;
		Node(const Item_Type& item) : data(item), next(nullptr) {}
	};

	Node* head;
	Node* tail;
	size_t num_items;

public:
	Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

	void push_front(const Item_Type& item) {
		Node* new_node = new Node(item);
		if (empty()) {
			head = tail = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
		++num_items;
	}

	void push_back(const Item_Type& item) {
		Node* new_node = new Node(item);
		if (empty()) {
			head = tail = new_node;
		}
		else {
			tail->next = new_node;

		}
		++num_items;
	}

	void pop_front() {
		if (!empty()) {
			Node* temp = head;
			head = head->next;
			delete temp;
			--num_items;
			if (empty()) {
				tail = nullptr;
			}
		}
	}

	void pop_back() {
		if (!empty()) {
			if (head == tail) {
				delete tail;
				head = tail = nullptr;
			}
			else {
				Node* temp = head;
				while (temp->next != tail) {
					temp = temp->next;
				}
				delete tail;
				tail = temp
					tail->next = nullptr
			}
			--num_items;
		}
	}

	Item_Type front() const {
		if (!empty()) {
			return head->data;
		}
		throw std::out_of_range("List is empty");
	}

	Item_Type back() const {
		if (!empty()) {
			return tail->data;
		}
		throw std::out_of_range("List is empty");
	}

	bool empty() const {
		return num_items == 0
	}

	void insert(size_t index, const Item_Type& item) {
		if (index > num_items) {
			index = num_items;
		}
		if (index == 0) {
			push_front(item);
		}
		else if (index == num_items) {
			push_back(item);
		}
		else {
			Node* new_node = new Node(item);
			Node* temp = head;
			for (size_t i = 0; i < index - 1; ++i) {
				temp = temp->next;
			}
			new_node->next = temp->next;
			temp->next = new_node;
			++num_items;
		}
	}

	bool remove(size_t index) {
		if (index >= num_items) {
			return false;
		}
		if (index == 0) {
			pop_front();
		}
		else {
			Node* temp = head;
			for (size_t i = 0; i < index - 1; i++) {
				temp = temp->next;
			}
			Node* to_remove = temp->next;
			temp->next = to_remove->next;
			delete to_remove;
			--num_items;
			if (index == num_items - 1) {
				tail = temp;
			}
		}
		return true;
	}

	size_t find(const Item_Type& item) {
		Node* temp = head;
		size_t index = 0;
		while (temp != nullptr && temp->data != item) {
			temp = temp->next;
			++index;
		}
		return (temp != nullptr) ? index : num_items;
	}

	~Single_Linked_List() {
		while (!empty()) {
			pop_front();
		}
	}
};
		
int main() {
	Single_Linked_List<int> linkedlist;

	linkedlist.push_back(10);
	linkedlist.push_back(20);
	linkedlist.push_front(5);

	std::cout << "Front: " << linkedlist.front() << std::endl;
	std::cout << "Back: " << linkedlist.back() << std::endl;

	linkedlist.pop_front();
	linkedlist.pop_back();

	std::cout << "Is empty: " << std::boolalpha << linkedlist.empty() << std::endl;

	linkedlist.insert(1, 15);
	linkedlist.insert(0, 8);

	std::cout << "Index of 15: " << linkedlist.find(15) << std::endl;
	std::cout << "Index of 25: " << linkedlist.find(25) << std::endl;

	linkedlist.remove(1);

	return 0;
}
