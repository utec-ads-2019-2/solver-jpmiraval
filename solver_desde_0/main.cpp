#include <iostream>
#include <vector>
#include <stack>
#include <map>
#include <string>
#include "tree.h"

using namespace std;

int main() {

    string formula;

    string numero = "";
    string operador = "";
    stack <string> stack1;
    stack <string> stack2;
    map <string, int> mapita;
    mapita.insert(pair <string, int> ("-", 1));
    mapita.insert(pair <string, int> ("+", 1));
    mapita.insert(pair <string, int> ("*", 2));
    mapita.insert(pair <string, int> ("/", 2));
    mapita.insert(pair <string, int> ("(", 4));
    mapita.insert(pair <string, int> (")", 0));
    mapita.insert(pair <string, int> ("^", 3));

    while(cin >> formula){
        for(auto c : formula){
            if(isdigit(c) || c == '.'){
                numero += c;
            }else if(c == '(' || c == ')' || c == '+' || c == '-' || c == '*' || c == '/' || c == '^'){
                operador += c;
                if(!numero.empty()){
                    stack2.push(numero);
                    numero = "";
                }


                while(!stack1.empty() && stack1.top()!= "(" && stack1.top()!= ")" && (mapita[operador]<= mapita[stack1.top()]) && c != '(' && c != ')'){

                    stack2.push(stack1.top());
                    stack1.pop();

                }

                stack1.push(operador);

                operador = "";

            }else {
                numero +=c;
            }
        }
        if(numero != ""){
            stack2.push(numero);
        }

        while(!stack1.empty()){
            if(stack1.top() != "(" && stack1.top() != ")"){
                stack2.push(stack1.top());
            }

            stack1.pop();
        }

        Node *temp = new Node(stack2.top());
        stack2.pop();
        tree *arbolito = new tree(temp);

        while(!stack2.empty()){
            arbolito->insertar(stack2.top());
            cout << stack2.top() << " ";
            stack2.pop();
        }

        cout << "\n";
        arbolito->print();
        cout << "\n\n";
        cout << arbolito->resolver();

        delete arbolito;
    }

    return 0;
}