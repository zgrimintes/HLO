#include <iostream>

using namespace std;

struct Node {
    int v;
    Node* next;
};

void addToFront(Node*& p, int x) {
    if (!p) {
        p = new Node;
        p->next = 0;
        p->v = x;
        return;
    }

    Node* q = p;
    while (q->next) q = q->next;

    q->next = new Node;
    q = q->next;
    q->v = x;
    q->next = 0;
}

void citire(int& n, Node*& p) {
    cin >> n;
    while (n) {
        int x; cin >> x;
        addToFront(p, x);
        n--;
    }
}

void interclasare(Node*& p1, Node*& p2) {

    //Node *st;
    //(p1->v > p2->v) ? st = p2, p2 = p2->next: st = p1, p1 = p1->next;

    while (p1 && p2) {
        if (p1->v < p2->v) {
            Node* q = p1->next;
            p1->next = p2;
            p1->next->next = q;

            p2 = p2->next;
            p1 = p1->next;
        }
        else p1 = p1->next;
    }

    while (p2) {
        Node* q = p1->next;
        p1->next = new Node;
        p1->next->v = p2->v;
        p1->next->next = q;

        p2 = p2->next;
        p1 = p1->next;
    }
}

int main()
{
    Node* p1 = new Node, * p2 = new Node; 
    p1 = p2 = NULL;

    int n1, n2;
    citire(n1, p1);
    citire(n2, p2);
    interclasare(p1, p2);
    return 0;
}
