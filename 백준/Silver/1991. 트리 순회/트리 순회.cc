#include <iostream>
#include <unordered_map>
using namespace std;

// 이진트리란 => 0개 혹은 최대 2개의 자식을 가지는 노드를 갖는 트리

template<typename T>
struct Node
{
	T data;
	Node<T>* left;
	Node<T>* right;
	Node(T value)
	{
		this->data = value;
		left = nullptr;
		right = nullptr;
	}
};

template<typename T>
class BST
{
private:
	Node<T>* root;
public:
	BST()
	{
		root = nullptr;
	}
	~BST(){}
	
	void setRoot(Node<T>* node)
	{
		this->root = node;
	}
	void setLeftNode(Node<T>* parent, Node<T>* child);
	void setRightNode(Node<T>* parent, Node<T>* child);
	void preOrder(); //전위
	void inOrder();  //중위
	void postOrder(); //후위

	void preOrderLogic(Node<T>* cur);
	void inOrderLogic(Node<T>* cur);
	void postOrderLogic(Node<T>* cur);

	void printAllOrder();
};

template <typename T>
void BST<T>::setLeftNode(Node<T>* parent, Node<T>* child)
{
	parent->left = child;
}

template <typename T>
void BST<T>::setRightNode(Node<T>* parent, Node<T>* child)
{
	parent->right = child;
}

template <typename T>
void BST<T>::preOrder()
{
	if (root == nullptr)
	{
		cout << "이진 트리가 비어있습니다\n";
		return;
	}
	else preOrderLogic(root);
}

//전위 VLR
template <typename T>
void BST<T>::preOrderLogic(Node<T>* cur)
{
	if (cur == nullptr)return;

	cout << cur->data;
	preOrderLogic(cur->left);
	preOrderLogic(cur->right);
}

template <typename T>
void BST<T>::inOrder()
{
	if (root == nullptr)
	{
		cout << "이진 트리가 비어있습니다\n";
		return;
	}
	else inOrderLogic(root);
}

//중위 LVR
template <typename T>
void BST<T>::inOrderLogic(Node<T>* cur)
{
	if (cur == nullptr)return;

	inOrderLogic(cur->left);
	cout << cur->data;
	inOrderLogic(cur->right);

}
template <typename T>
void BST<T>::postOrder()
{
	if (root == nullptr)
	{
		cout << "이진 트리가 비어있습니다\n";
		return;
	}
	else postOrderLogic(root);
}

// 후위 LRV
template <typename T>
void BST<T>::postOrderLogic(Node<T>* cur)
{
	if (cur == nullptr)return;

	postOrderLogic(cur->left);
	postOrderLogic(cur->right);
	cout << cur->data;

}

template <typename T>
void BST<T>::printAllOrder()
{
	preOrder();
	cout << '\n';
	inOrder();
	cout << '\n';
	postOrder();
}

int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N; //
	cin >> N; //노드개수

	// 노드 알파벳은 
	// 'A' ~ 'A'+(N-1) 까지
	
	BST<char> tree;
	unordered_map<char, Node<char>*>nodes; // <key ,value>

	char parent, left, right;
	for (int i = 0; i < N; i++)
	{
		cin >> parent >> left >> right;
		
		if (nodes.find(parent) == nodes.end())
		{
			nodes[parent] = new Node<char>(parent); //문자노드 알아서 중복생성 방지
		}
		

		if (left != '.')
		{
			if (nodes.find(left) == nodes.end()) // 사용되지 않았다면
			{
				nodes[left] = new Node<char>(left); //문자 알아서 중복생성 방지
			}
			tree.setLeftNode(nodes[parent], nodes[left]);
		}
		if (right != '.')
		{
			if (nodes.find(right) == nodes.end()) // 사용되지 않았다면
			{
				nodes[right] = new Node<char>(right); //문자 알아서 중복생성 방지
			}
			tree.setRightNode(nodes[parent], nodes[right]);
		}
		if (i == 0)tree.setRoot(nodes[parent]);
	}
	
	tree.printAllOrder();

	return 0;
}