#include <iostream>
#include <string>
using namespace std;

class Node {
public:
	int rollNumber;
	string name;
	Node* next;
};

class CircularLinkedList {
private:
	Node* LAST;
public:
	CircularLinkedList() {
		LAST = NULL;
	}
	void addNode();
	bool search(int rollno, Node** permono, Node** aditya); // current aditya prev permono
	bool listEmpty();
	bool delNode();
	void traverse();
};
void CircularLinkedList::addNode() { //write your answer here
	int number;
	string nama;
	Node* nodeBaru = new Node();
	cout << "Masukkan Number: ";
	cin >> number;
	cout << "Masukkan Nama: ";
	cin >> nama;
	nodeBaru->rollNumber = number;
	nodeBaru->name = nama;

	if (LAST == NULL || number <= LAST->rollNumber) {
		if (LAST != NULL && number == LAST->rollNumber)
		{
			cout << "Number sudah ada" << endl;
			return;
		}

		nodeBaru->next = LAST;
		LAST = nodeBaru;
		return;
	}

	Node* permono = LAST;
	Node* aditya = LAST;

	while ((aditya != NULL) && (number >= aditya->rollNumber))
	{
		if (number == aditya->rollNumber)
		{
			cout << "Number sudah ada" << endl;
			return;
		}
		permono = aditya;
		aditya = permono->next;
	}

	nodeBaru->next = aditya;
	permono->next = nodeBaru;

	// Beginning of the list
	if (LAST == NULL) {
		nodeBaru->next = nodeBaru;
		LAST = nodeBaru;
		aditya = nodeBaru;
		permono = LAST;
	}
	// End of the list
	if (aditya == LAST) { 
			nodeBaru->next = LAST->next;
			LAST->next = nodeBaru;
			LAST = nodeBaru;
	}
	// Between two nodes in the list
	else { 
			nodeBaru->next = aditya;
			permono->next = nodeBaru;
		}
	
}

bool CircularLinkedList::search(int rollno, Node** permono, Node** aditya) {
	*permono = LAST->next;
	*aditya = LAST->next;
	while (*aditya != LAST) {
		if (rollno == (*aditya)->rollNumber) {
			return true;
		}
		*permono = *aditya;
		*aditya = (*aditya)->next;
	}
	if (rollno == LAST->rollNumber) {
		return true;
	}
	else {
		return false;
	}
}
bool CircularLinkedList::listEmpty() {
	return LAST == NULL;
}
bool CircularLinkedList::delNode() { //write your answer here
	if (listEmpty()) {
		cout << "List is empty" << endl;
		return false;
	}
	else {
		Node* aditya = LAST->next;
		Node* successor = LAST->next;

		if (aditya == LAST) { // If the node to be deleted is the only node in the list
			LAST = NULL;
			delete aditya;
			return true;
		}

		LAST->next = successor;
		delete aditya;
		return true;
	}
}

void CircularLinkedList::traverse() {
	if (listEmpty()) {
		cout << "\nList is empty\n";
	}
	else {
		cout << "\nRecords in the list are:\n";
		Node* adityaNode = LAST->next;
		while (adityaNode != LAST) {
			cout << adityaNode->rollNumber << " " << adityaNode->name << endl;
			adityaNode = adityaNode->next;
		}
		cout << LAST->rollNumber << " " << LAST->name << endl;
	}
}
int main() {
	CircularLinkedList obj;
	while (true) {
		try {
			cout << "\nMenu" << endl;
			cout << "1. Add a record to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all the records in the list" << endl;
			cout << "4. Exit" << endl;
			cout << "\nEnter your choice (1-5): ";
			char ch;
			cin >> ch;
			switch (ch) {
			case '1': {
				obj.addNode();
			}
			case '2': {
				obj.delNode();
			}
			case '3': {
				obj.traverse();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "Invalid option" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}