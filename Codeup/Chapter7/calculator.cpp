#include<bits/stdc++.h>
using namespace std;

struct node {
    double num; // operand
    char op; // operator
    bool flag; // true is the operand, false if the operator
};

string str;
stack<node> s; // operator stack
queue<node> q; // postfix expression
map<char, int> op; // priority of the operator


/* convert the infix expression to the postfix expression */
void Change() {
    double num;
    node temp;
    for (int i = 0; i < str.length();) {
        if (isdigit(str[i])) {
            num = str[i++] - '0';
            temp.flag = true;
            while (i < str.length() && isdigit(str[i])) {
                num = num * 10 + str[i++] - '0';
            }
            temp.num = num;
            q.push(temp);
        } else {
            temp.flag = false;
            temp.op = str[i];
            if (temp.op == '(') s.push(temp);
            else if (temp.op == ')') {
                while (s.top().op != '(') {
                    q.push(s.top());
                    s.pop();
                } 
                s.pop();
            }
            else {
                while (!s.empty() && op[s.top().op] >= op[temp.op]) {
                    q.push(s.top());
                    s.pop();
                }
                s.push(temp);
            }
            i++;
        }
    }
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }
}

/* postfix stack 
 *  1 + 2 * 3 ==> 1 2 3 * +
 *                
 */

double cal() {
    double num;
    node temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp.flag == true) s.push(temp);
        else {
            double cur = s.top().num;
            s.pop();
            double pre = s.top().num;
            s.pop();
            if (temp.op == '+') num = pre + cur;
            else if (temp.op == '-') num = pre - cur;
            else if (temp.op == '*') num = pre * cur;
            else if (temp.op == '/') num = pre / cur;
            temp.flag = true;
            temp.num = num;
            s.push(temp);
        }
    }
    return s.top().num;
}

int main() {
    op['+'] = op['-'] = 1;
    op['*'] = op['/'] = 2;
    cin >> str;
    for (auto it = str.begin(); it != str.end(); it++) {
        if (*it == ' ') str.erase(it);
    }
    Change();
    printf("%.2f\n", cal());
    return 0;
}