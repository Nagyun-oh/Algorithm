#include <iostream>

using namespace std;


// 노드 구조체
template <typename T>
struct Node
{
	T data;
	Node* prev;
	Node* next;
};

template <typename T>
class queue
{
private:
	int q_size;
	Node<T>* head;
	Node<T>* tail;

public:

	
	// constructor
	queue()
	{
		q_size = 0;
		Node<T>* tmpHead = new Node<T>;
		Node<T>* tmpTail = new Node<T>;
		tmpHead->data = T();
		tmpTail->data = T();
		tmpHead->next = tmpTail;
		tmpHead->prev = nullptr;
		tmpTail->next = nullptr;
		tmpTail->prev = tmpHead;

		head = tmpHead;
		tail = tmpTail;
	}

	// destructor
	~queue()
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

	// push
	void push(T elem)
	{
		Node<T>* newNode = new Node<T>;
		newNode->data = elem;

		newNode->next = tail;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		tail->prev = newNode;
		q_size++;
	}

	//pop
	void pop()
	{
		// 큐가 비어있지 않음
		if (!empty())
		{
			Node<T>* delNode = head->next;

			cout << delNode->data << "\n";

			delNode->next->prev = head;
			head->next = delNode->next;
			delete delNode;
			q_size--;
		}
		else // 큐가 비어있을 때
		{
			cout << "-1\n";
		}

	}

		T front()
		{
			
			if (!empty())return head->next->data;
			else return -1;
		}

		T back()
		{
			if (!empty())return tail->prev->data;
			else return -1;
		}
		
		bool empty()
		{
			if (q_size == 0)
			{
				return true;
			}
			else return false;
		}
		
		int size()
		{
			return q_size;
		}
	


};

void first()
{
	queue<int> q;
	string command;
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> command;

		if (command == "push")
		{
			int n;
			cin >> n;
			q.push(n);
		}
		else if (command == "pop")
		{
			q.pop();
		}
		else if (command == "size")
		{
			cout << q.size() << '\n';
		}
		else if (command == "empty")
		{
			if (q.empty())cout << "1\n";
			else cout << "0\n";
		}
		else if (command == "front")
		{
			cout << q.front() << "\n";
		}
		else if (command == "back")
		{
			cout << q.back() << "\n";
		}

	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	first();

	return 0;
}