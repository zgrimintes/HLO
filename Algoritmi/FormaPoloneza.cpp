//ALGORITMUL PENTRU CREEREA UNEI FORME POLONEZE PREFIXATE SI CALCULUL ACESTEIA
//Vezi EvaluareDeExpresii.cpp (complexitate de O(n^2)) fata de acesta cu O(n)
#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

char exp[100005];
int p;

stack <int> nrs;
stack <char> semne;

int eval(int a, int b, char s){
    switch (s){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        return a / b;
        break;
    }
}

bool prioritate(int s1, int s2) {
    if (s1 == '(') return true;

    if ((s1 == '+' || s1 == '-') && (s2 == '*' || s2 == '/')) return true;
    return false;
}

int getNum(){
    int nr = 0;
    for (; exp[p] >= '0' && exp[p] <= '9';)
        nr = nr * 10 + (exp[p++] - '0');

    return nr;
}

void getResult(){
    int v1 = nrs.top();
    nrs.pop();

    int v2 = nrs.top();
    nrs.pop();

    char s = semne.top();
    semne.pop();

    nrs.push(eval(v2, v1, s));
}

int solve(int n){
    while (p < n){
        switch(exp[p]) {
        case '(':
            semne.push(exp[p++]);
            break;
        case ')':
            while (semne.top() != '(')
                getResult();

            semne.pop();
            p++;
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            if (semne.empty() || prioritate(semne.top(), exp[p])){
                semne.push(exp[p++]);
            }
            else {
                do {
                    getResult();
                }while (!semne.empty() && !prioritate(semne.top(), exp[p]));
                semne.push(exp[p++]);
            }
            break;
        default:
            nrs.push(getNum());
            break;
    }

    }

    while (!semne.empty()){
        getResult();
    }

}


int main()
{
    cin.getline(exp, 1000005);
    int len = strlen(exp);
    solve(len);

    cout << nrs.top();

    return 0;
}
