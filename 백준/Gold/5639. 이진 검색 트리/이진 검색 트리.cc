#include <iostream>
using namespace std;

struct BinarySearchTree {
	int num;
	BinarySearchTree* left;
	BinarySearchTree* right;

	BinarySearchTree(int num_) :  num(num_), left(nullptr), right(nullptr){}

	void makeBinarySearchTree(int num_) {
		BinarySearchTree* cur = this;

		while (true) {
			//왼쪽 서브트리
			if (cur->num > num_) {
				if (cur->left == nullptr) {
					cur->left = new BinarySearchTree(num_);
					break;
				}
				cur = cur->left;
			}
			//오른쪽 서브트리
			else {
				if (cur->right == nullptr) {
					cur->right = new BinarySearchTree(num_);
					break;
				}
				cur = cur->right;
			}
		}
	}

};

void postOrder(BinarySearchTree& curNode) {
	if (curNode.left != nullptr) postOrder(*curNode.left);
	if (curNode.right != nullptr) postOrder(*curNode.right);
	cout << curNode.num << '\n';

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n;
	cin >> n;
	BinarySearchTree rootNode(n);

	while (cin >> n) {
		rootNode.makeBinarySearchTree(n);
	}
	postOrder(rootNode);

}