#include <iostream>
using namespace std;
int main(){
    double num1, num2;
    char op;

    cout<<"Enter the number: ";
    cin>>num1;

    cout<<"Enter the number:";
    cin>>num2;

    cout<<" Choose an oprator (+,-,*,/): ";
    cin>>op;

    switch (op)
    {
     case '+':
            cout << "Result = " << num1 + num2;
            break;

    case '-':
           cout << "Result ="<<num1 - num2;
           break;

    case '*':
          cout << "Result ="<< num1 * num2;
          break;

    case '/':
        if(num2 != 0)
           cout << "Result ="<<num1 / num2;
        else
           cout <<"Error: Division by zero is not allowed: ";
           break;
    
    default:
      cout <<" invalid oprator selected.";
        break;
    }

    return 0;
}

