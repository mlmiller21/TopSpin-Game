#pragma once

template <class item>
class CircularDoublyLinkedList {

private:

	struct Node {
		Node * next;	//Refers to next pointer
		Node * previous;	//Refers to previous pointer
		item value;

		Node(item item, Node *head, Node *tail) : value(item), next(head), previous(tail) {};
	};
	Node * head;	
	Node * tail;
	unsigned int listSize;	//size of linked list

public:
	class iterator {
	private:
		Node * ptr;
	public:
		iterator() {}
		iterator(Node * _ptr)
		{
			ptr = _ptr;
		}
		void operator++()	//++ overload operator, traverses list to the right
		{
			ptr = ptr->next;
		}
		void operator--()	//-- overload operator, traverses list to the left
		{
			ptr = ptr->previous;
		}
		item getValue()
		{
			return ptr->value;
		}
		void setValue(item val)
		{
			ptr->value = val;
		}
		bool operator!=(const iterator&b)	//!= overload operatror, compares values
		{
			return ptr != b.ptr;
		}
	};
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{
		return iterator(tail);
	}
	CircularDoublyLinkedList();
	~CircularDoublyLinkedList();
	void addHead(item item);
	bool isEmpty()const;
	item removeHead();
	item retrieveHead ()const;
	item size() const;
	void addTail(item item);
	item removeTail();
	item retrieveTail()const;
	void add(unsigned int n, item item);
	item replace(unsigned int n, item Item);
	item remove(unsigned int n);
	item retrieve(unsigned int n)const;

};	

template <class item>
CircularDoublyLinkedList<item>::CircularDoublyLinkedList()	//head and tail point to node null, size is 0
{
	head = nullptr;
	tail = nullptr;
	listSize = 0;
}

template<class item>
CircularDoublyLinkedList<item>::~CircularDoublyLinkedList()	//Delete all nodes, use for loop to delete node one by one
{
	Node * here = head, *nextNode;
	for (int i=0;i<listSize;i++)
	{
		nextNode = here->next;
		delete here;
		here = nextNode;
	}
}

template<class item>
void CircularDoublyLinkedList<item>::addHead(item item)	//if size=0, node=tail=null.
{
	Node *node = new Node(item, head, tail);
	node->value = item;
	if (listSize == 0) {
		head = node;
		tail = node;
	}
	else
	{
		tail->next = node;	//the tail points to the next node, being head
		head->previous = node;	//The new head points to the previous node, being tail
		head = node;
	}
	listSize++;
}

template<class item>
bool CircularDoublyLinkedList<item>::isEmpty()const	//Check if list is empty, return true value (1)
{
	return (listSize == 0);
}

template<class item>
item CircularDoublyLinkedList<item>::removeHead()	
{
	Node * oldNode = head;	//Set a temporary node to store the head value
	item returnVal = head->value;	
	head = head->next;	//Have head equal to the next node
	tail->next = head;	//Have tail point to the new head
	if (head == nullptr)
		tail = nullptr;	
	listSize--;
	delete oldNode;	//Temporary value storing head is deleted
	return returnVal;	//value is returned
}

template<class item>
item CircularDoublyLinkedList<item>::retrieveHead()const
{
	return head->value;	//Return head value
}

template<class item>
item CircularDoublyLinkedList<item>::size()const
{
	return listSize;	//size
}

template<class item>
void CircularDoublyLinkedList<item>::addTail(item item)
{
	if (isEmpty())
		addHead(item);	//If the list is empty, adding a tail is identical to adding a head
	else
	{
		Node *node = new Node(item, head, tail);	//Make new node with value that is going to be stored
		node->value = item;	//New node value is equal to value inputted
		tail->next = node;	//new tail is added right of old tail, so old tail now points to new tail
		head->previous = node;	//head points back to new tail
		tail = node;	//set tail equal to the new node
		listSize++;
	}
}

template<class item>
item CircularDoublyLinkedList<item>::removeTail()
{
	if (head == tail)
		return removeHead();	//if size is 1, then the tail is the same as the head
	Node * oldNode = tail;	//Make new node set to old tail
	item returnVal = tail->value;	
	tail = tail->previous;	//Have tail be the node before the old tail
	head->previous = tail;	//Head poinst to new tail
	if (oldNode->next != head)
		oldNode = oldNode->next;
	oldNode->next = head;	//New node now points to the head
	tail->next = head;
	listSize--;
	delete oldNode;
	return returnVal;

}

template<class item>
item CircularDoublyLinkedList<item>::retrieveTail()const
{
	return tail->value;	//Value at tail node
}

template <class item>
void CircularDoublyLinkedList<item>::add(unsigned int n, item item)
{
	while (n<1 || n>size() + 1)
	{
		cout << "invalid position, n should be between 1 and size + 1, try again: ";
		cin >> n;
	}
	if (n == 1)
		addHead(item);	//If adding at position 1, same to adding head
	else if (n == size() + 1)
		addTail(item);	//If adding to last position, same as adding a tail
	else
	{
		Node * here = head;
		for (unsigned int k = 1;k < n - 1;k++)
			here = here->next;	//For loop has here point to the new node position
		here->next = new Node(item, here->next, tail);	//New node is added in this position and size is incremented
		listSize++;
	}
}

template<class item>
item CircularDoublyLinkedList<item>::replace(unsigned int n, item Item)
{
	item returnValue;
	Node * here = head;
	for (unsigned int k = 1;k < n;k++)
		here = here->next;	//For loop has here point to the node being replaced
	returnValue = here->value;	//Node value is stored
	here->value = Item;	//Node is replaced by new value
	return returnValue;
}

template<class item>
item CircularDoublyLinkedList<item>::remove(unsigned int n)
{
	if (n == 1)
		return removeHead();	//Removing at position 1 same as removing head
	else if (n == size())
	{
		return removeTail();	//Removing at last position same as removing tail
	}
	else {
		Node * here = head;
		Node * before;
		for (unsigned int i = 1;i < n;i++)
			here = here->next;	//Here points to node being removed
		Node * kill = here;	//Kill represents the value being removed
		item returnValue = kill->value;	//Value is stored
		here = kill->next;	
		before = kill->previous; //Here points to next and previous value of node being deleted so it doesn't point to null
		delete kill;
		listSize--;
		before->next = here;
		here->previous = before;	
		return returnValue;
	}
	
}

template <class item>
item CircularDoublyLinkedList<item>::retrieve(unsigned int n)const
{
	if (n == 1)
		return retrieveHead();	//Retreieve at position 1 = retrieve head
	else if (n == size())
		return retrieveTail();	//Retrieve at last position = retrieve tail
	else
	{
		Node * here = head;
		for (unsigned int k = 1;k < n;k++)
			here = here->next;	//For loop points to value being retrieved and returns it
		return here->value;
	}
}
