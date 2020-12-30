#include<bits/c++std.h>

using namespace std;

struct Node {
    int val;
    int left, right, next;
    Node(int _val): val(_val), left(nullptr), right(nullptr), next(nullptr){}
};

typedef struct Node* node;

void convertToZigZag(node root) {
    if(root == nullptr) return;
    node parent = prev = start = end = root;
    if(end->right) {
        end = end->right;
        start = end->left;
        parent->next = start;
    } else if(
        end = end->left;
        start = end->left;
        parent->next = start;
    )

    while(start != nullptr) {
        if(start == end) {
            if(prev->left) start->next = prev->left;
            else start->next = prev->right;
            parent = end;
            if(end->right) end = end->right;
            else end = end->left;
        } else {
            node temp = prev->left != nullptr ? prev->left : prev->right;
            if(temp == start) {
                start->next = prev->right;
                prev = prev->next;
            } else {
                start->next = prev->left;
            }
        }
        start = start->next;
    }
}

int main() 
{
    cout << " Hello " << endl;
}