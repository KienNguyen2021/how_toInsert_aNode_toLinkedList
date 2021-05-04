#include<iostream>

using namespace std;

struct Staff
{
	string name;
	int salary;

	Staff()
	{
		name = " ";
		salary = 0;
	}
	Staff(string Name, int Salary)
	{
		name = Name;
		salary = Salary;
	}

};

struct Node
{
	Staff datum;
	Node* pNext;

	Node()
	{
		datum.name = " ";
		datum.salary = 0;
		pNext = nullptr;
	}

	Node(Staff staff, Node* link)
	{
		datum = staff;
		pNext = link;
	}

};

class SortedLinkedList
{
private:
	Node* pHead;

public:
	SortedLinkedList()
	{
		pHead = nullptr;
	}

	SortedLinkedList(Node* link)
	{
		pHead = link;
	}

	bool isEmpty()
	{
		return (pHead == nullptr);
	}

	void CreateList()
	{
		cout << "Enter the number of nodes that you want to have in the list" << endl;
		int numberOfNodes;
		cin >> numberOfNodes;

		Node* pCurrentNode;
		Node* pNewCode;

		cout << "Enter the value to store in the 0th node: " << endl;
		Staff staff0;
		string inputName;
		int inputSalary;
		cin >> inputName;
		cin >> inputSalary;

		staff0.name = inputName;
		staff0.salary = inputSalary;

		pNewCode = new Node(staff0, nullptr);
		pHead = pNewCode;
		pCurrentNode = pHead;

		int count = 0;

		while (count != (numberOfNodes - 1))
		{
			cout << "Enter the name and salary to store in the "
				<< count + 1 << " node" << endl;
			cin >> inputName;
			cin >> inputSalary;
			staff0.name = inputName;
			staff0.salary = inputSalary;

			pNewCode = new Node(staff0, nullptr);
			pCurrentNode->pNext = pNewCode;
			pCurrentNode = pNewCode;
			count++;
		}

	}

	void printLinkedList()
	{
		cout << "Our linked list is as follows: " << endl;
		for (const Node* p = pHead; p != nullptr; p = p->pNext)
		{
			cout << p->datum.name << " " << p->datum.salary << endl;
		}
		cout << endl;

	}
// H 2 5 7 9 14 17
// We want to insert 11 between 9 and 11
// First, need to find the address of Node 9, means < 11--> we compare the datum component
// It will return the address
// If 18 we want to insert,the pCurrent =17, so pNext = Null pointer, and pCurrent stop at 17
// if we want to insert  0; pHead is nullpoiter

	Node * searchLinkedList(Node *pHead, Staff staff)    // pass 2 parameters : phead and staff staff
	{

		Node *pPrevious = nullptr;       // Initialize Node 9 is the Head Node, assign it with Nullpointer
		Node *pCurrent = pHead;       // Initialize p Current = pHead

		while (pCurrent != nullptr && pCurrent->datum.salary < staff.salary) 
			// datum Salary of 9 node compare with Staff salary New Node, If it is TRUE
			// if the salary of new Node < the salary of Node 14, then it stops searching
		{
			pPrevious = pCurrent;
			pCurrent = pCurrent->pNext;     // pointer of 9 contains pNext- address of new Node
		}
		return pPrevious;
	}

	void insertNode(Staff staff)  // specify which node we insert
	{
	
		Node *pPrevious = searchLinkedList(pHead, staff);  
		
		//We search the place where we want to insert, we use Function SearchLinkedlist to pass 2 parameters
		
		// To define a new node, the datum component of this Node  is staff
		
		Node *pCurrent = new Node;
		pCurrent->datum = staff;      // assign the data component of this new Node is staff

		// to check where we insert :

		if (pPrevious == nullptr)   // means we install the node at the top of the list


		{
			pCurrent->pNext = pHead;
			pHead = pCurrent; 
		}
		// if this condition is not satified:

		else
		{
			pCurrent->pNext = pPrevious->pNext;
			pPrevious->pNext = pCurrent;

		}
	}
};

int main()
{
	SortedLinkedList list1;

	list1.CreateList();

	list1.printLinkedList();

	cout << endl;



     Staff staff1 ("Patel",20);
	 Staff staff2("Paul", 19);
	 Staff staff3("John", 23);

	 list1.insertNode(staff1);
	 list1.insertNode(staff2);
	list1.insertNode(staff3);



	list1.printLinkedList();

	cout << endl;

	//    cout<<list1.isEmpty()<<endl;


	return 0;

}