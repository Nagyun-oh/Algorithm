#include <iostream>
using namespace std;

#define MAX 500000 // 최대 크기

//노드 구조체
template <typename T>
struct Node
{
	int data;
	Node* prev;
	Node* next;
};

// 큐 클래스
template <typename T>
class Queue
{
private:
	int Q_size;
	Node<T>* head;
	Node<T>* tail;

public:
	
	// 생성자
	Queue()
	{
		Q_size = 0;
		Node<T>* tmpHead = new Node<T>;
		Node<T>* tmpTail = new Node<T>;
		tmpHead->data = T();
		tmpTail->data = T();
		tmpHead->next = tmpTail;
		tmpHead->prev = tmpHead;
		tmpTail->next = tmpTail;
		tmpTail->prev = tmpHead;

		head = tmpHead;
		tail = tmpTail;
	}

	// 소멸자
	~Queue()
	{
		Node<T>* tmp = head;
		Node<T>* delNode = tmp;
		while (tmp != tail)
		{
			delNode = tmp;
			tmp = tmp->next;
			delete delNode;
		}
		delete tmp;
	}

	void push(T elem)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = elem;

		newNode->next = tail;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		tail->prev = newNode;
		Q_size++;
	}

	void pop()
	{
		if (!empty())
		{
			Node<T>* delNode = head->next;
			delNode->next->prev = head;
			head->next = delNode->next;
			delete delNode;
			Q_size--;
		}
	}

	T front() { return head->next->data; }
	T back() { return tail->prev->data; }
	bool empty()
	{
		if (Q_size == 0)return true;
		else return false;
	}
	int size()
	{
		return Q_size;
	}

};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Queue<int> q;
	int n;
	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		q.push(i);
	}

	while (q.size() != 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	cout << q.front();

	return 0;
}