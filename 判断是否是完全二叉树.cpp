#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<queue>
using namespace std;
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int value) :
        value(value), left(nullptr), right(nullptr) {}
};
bool isCBT(Node* head) {
    if (head == nullptr) {
        return true;
    }
    queue<Node*> q;
    //1 先插入头结点
    q.push(head);
    Node* front = nullptr;
    //2 依次将结点的孩子插入，当遇到空 则停止，比如只有右孩子，会先取到左孩子的空
    while (front = q.front()) { 
        q.push(front->left);
        q.push(front->right);
        q.pop();
    }
    //3 判断队列中的元素，只要有不为空指针的返回false;
    while (!q.empty()) {
        if (q.front() != nullptr) {  // if we encount a not nullptr, return false
            return false;
        }
        q.pop();
    }
    return true;    // if pass the check, is CBT!
}
int main() {
    Node* head1 = new Node(1);
    head1->left = new Node(2);
    head1->right = new Node(3);
    head1->left->right = new Node(4);
    head1->right->right = new Node(5);

    std::cout << "==============CBT Test1==============\n";
    bool iscbt1 = isCBT(head1);
    std::cout << iscbt1 << std::endl;

    Node* head2 = new Node(1);
    head2->left = new Node(2);
    head2->right = new Node(3);
    head2->left->left = new Node(4);
    head2->left->right = new Node(5);
    head2->right->left = new Node(6);

    std::cout << "==============CBT Test2==============\n";
    bool iscbt2 = isCBT(head2);
    std::cout << iscbt2 << std::endl;
    return 0;

}