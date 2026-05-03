#include <iostream>
#include <stack>
#include <string>
#include <cmath>
#include <cctype>
#include <cstdlib>

using namespace std;

// 判断是否为运算符
bool isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^' || ch == '(' || ch == ')' || ch == '=';
}

// 获取运算符优先级
// 优先级定义参考图片：=为1, ()为2, +-为3, */%为4, ^为5
int getPriority(char op) {
    switch (op) {
    case '=': return 0; // 最低，作为结束标志
    case '(': return 1; // 在栈内优先级最低，保证其他运算符能入栈
    case '+':
    case '-': return 2;
    case '*':
    case '/':
    case '%': return 3;
    case '^': return 4;
    case ')': return 5; // 右括号优先级虽高，但用于触发计算
    default: return -1;
    }
}

// 执行单步运算
double calculate(double a, char op, double b) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/':
        if (b == 0) {
            cout << "错误：除数不能为0！" << endl;
            exit(1);
        }
        return a / b;
    case '%':
        if ((int)b == 0) {
            cout << "错误：取余除数不能为0！" << endl;
            exit(1);
        }
        return fmod(a, b); // 支持浮点数取余
    case '^': return pow(a, b);
    default: return 0;
    }
}

// 核心计算逻辑
void evaluateExpression() {
    stack<char> optr;   // 运算符栈
    stack<double> opnd; // 操作数栈

    optr.push('='); // 初始压入结束符

    char ch;
    char lastChar = '('; // 用于判断单目运算符，假定开始前有一个虚拟左括号

    cout << "输入表达式 (以=结尾): " << endl;

    // 跳过可能的初始空格
    cin >> ws;

    while (cin >> ch) {
        // 如果不是运算符，或者是数字的一部分（处理小数点的情况需要更复杂的逻辑，这里简化为放回流交给cin读取double）
        if (!isOperator(ch)) {
            cin.putback(ch);
            double num;
            if (cin >> num) {
                opnd.push(num);
                lastChar = '0'; // 标记上一个是数字
            }
            else {
                cout << "表达式有错！非法字符。" << endl;
                // 清空输入流以防死循环
                cin.clear();
                string dummy; getline(cin, dummy);
                return;
            }
        }
        else {
            // 处理运算符

            // 特殊处理单目运算符 (如 -2 或 (-2))
            // 如果读到 + 或 -，且上一个字符是 ( 或 = 或其他运算符，说明这是正负号
            if ((ch == '+' || ch == '-') && (lastChar == '(' || lastChar == '=' || isOperator(lastChar) && lastChar != ')')) {
                opnd.push(0); // 补0，变单目为双目，如 -2 变为 0-2
            }

            // 比较优先级逻辑
            bool handled = false;
            while (!handled && !optr.empty()) {
                char topOp = optr.top();

                // 情况1: 读入左括号，直接入栈
                if (ch == '(') {
                    optr.push(ch);
                    handled = true;
                }
                // 情况2: 读入右括号，计算直到遇到左括号
                else if (ch == ')') {
                    while (optr.top() != '(') {
                        char op = optr.top(); optr.pop();
                        if (opnd.size() < 2) { cout << "表达式有错！操作数不足。" << endl; return; }
                        double b = opnd.top(); opnd.pop();
                        double a = opnd.top(); opnd.pop();
                        opnd.push(calculate(a, op, b));
                    }
                    optr.pop(); // 弹出 '('
                    handled = true;
                }
                // 情况3: 读入 '='，且栈顶也是 '='，结束
                else if (ch == '=' && topOp == '=') {
                    handled = true;
                }
                // 情况4: 读入 '='，但栈顶不是 '='，需要计算栈内剩余
                else if (ch == '=') {
                    char op = optr.top(); optr.pop();
                    if (opnd.size() < 2) { cout << "表达式有错！" << endl; return; }
                    double b = opnd.top(); opnd.pop();
                    double a = opnd.top(); opnd.pop();
                    opnd.push(calculate(a, op, b));
                }
                // 情况5: 普通运算符比较
                else {
                    // 如果栈顶优先级 >= 当前字符优先级 (且栈顶不是 '(')，则先计算栈顶
                    // 注意：这里优先级逻辑：栈顶大则出栈计算，栈顶小则当前符入栈
                    if (topOp != '(' && getPriority(topOp) >= getPriority(ch)) {
                        char op = optr.top(); optr.pop();
                        if (opnd.size() < 2) { cout << "表达式有错！" << endl; return; }
                        double b = opnd.top(); opnd.pop();
                        double a = opnd.top(); opnd.pop();
                        opnd.push(calculate(a, op, b));
                    }
                    else {
                        // 栈顶优先级低，当前符入栈
                        optr.push(ch);
                        handled = true;
                    }
                }
            }

            lastChar = ch;
            if (ch == '=') break;
        }
    }

    if (!opnd.empty()) {
        cout << opnd.top() << endl;
    }
    else {
        cout << "0" << endl;
    }
}

int main() {
    char cont = 'y';
    while (cont == 'y' || cont == 'Y') {
        evaluateExpression();
        cout << "是否继续 (y/n)? ";
        cin >> cont;
    }
    return 0;
}