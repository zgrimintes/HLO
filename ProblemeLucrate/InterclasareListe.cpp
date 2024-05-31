///To check
///p->adr=q->adr; q->adr=p;
#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("list.in");

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
    fin >> n;
    while (n) {
        int x; fin >> x;
        addToFront(p, x);
        n--;
    }
}

void interclasare(Node*& p1, Node*& p2) {

    if (p1->v > p2->v){
        swap(p1, p2);
    }

    Node *t1 = p1;

    while (t1 && t1->next && p2) {
        if (t1->v < p2->v && t1->next->v > p2->v) {
            Node* q = t1->next;
            t1->next = new Node;
            t1->next->v = p2->v;
            t1->next->next = q;

            p2 = p2->next;
            t1 = t1->next;
        }
        else t1 = t1->next;
    }

    if (p2) t1->next = p2;
}

void afisare(Node *p) {
    for (Node *q = p; q; q = q->next)
        cout << q->v << " ";
}

int main()
{
    Node* p1 = new Node, * p2 = new Node;
    p1 = p2 = NULL;

    int n1, n2;
    citire(n1, p1);
    citire(n2, p2);
    interclasare(p1, p2);
    afisare(p1);
    return 0;
}
