#include <bits/stdc++.h>

using namespace std;

int main() 
{
    double num1, num2, result;
    char op;
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t                     /$$                     /$$             /$$                        \n";
    cout<<"\t\t\t\t                    | $$                    | $$            | $$                        \n";
    cout<<"\t\t\t\t  /$$$$$$$  /$$$$$$ | $$  /$$$$$$$ /$$   /$$| $$  /$$$$$$  /$$$$$$    /$$$$$$   /$$$$$$ \n";
    cout<<"\t\t\t\t /$$_____/ |____  $$| $$ /$$_____/| $$  | $$| $$ |____  $$|_  $$_/   /$$__  $$ /$$__  $$\n";
    cout<<"\t\t\t\t| $$        /$$$$$$$| $$| $$      | $$  | $$| $$  /$$$$$$$  | $$    | $$  \\ $$| $$  \\__/\n";
    cout<<"\t\t\t\t| $$       /$$__  $$| $$| $$      | $$  | $$| $$ /$$__  $$  | $$ /$$| $$  | $$| $$      \n";
    cout<<"\t\t\t\t|  $$$$$$$|  $$$$$$$| $$|  $$$$$$$|  $$$$$$/| $$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$      \n";
    cout<<"\t\t\t\t \\_______/ \\_______/|__/ \\_______/ \\______/ |__/ \\_______/   \\___/   \\______/ |__/      \n";
    cout<<"\n\n\n\n";
    cout << "\033[1;34mThis is a simple calculator to perform basic arithmetic operations, like addition(+), subtraction(-), multiplication(*), & division(/)\033[0m" << endl;
    cout << "\n\n\033[3;33mEnter two numbers: \033[0m\n\n";
    cin >> num1 >> num2;

    cout << "\n\n\033[33mEnter an operator (+, -, *, /): \033[0m\n\n";
    cin >> op;

    switch (op) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                cout << "\033[31mError: Division by zero\033[0m\n";
                return 1;  // Exit the program with an error code
            }
            result = num1 / num2;
            break;
        default:
            cout << "\033[31mError: Invalid operator\033[0m\n";
            return 1;  // Exit the program with an error code
    }

    cout << "\033[32mResult: " << num1 << " " << op << " " << num2 << " = " << result << "\033[0m\n";

    return 0;
}
