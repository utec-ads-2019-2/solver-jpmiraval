#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>

using namespace std;

class Node{
private:
    Node* left;
    Node* right;
    string value;
public:
    Node(string valor):value(valor){};

    float getValue(){
        if(value == "+"){
            return left->getValue() + right->getValue();
        }else if(value == "-"){
            return left->getValue() - right->getValue();
        }else if(value == "*"){
            return left->getValue() * right->getValue();
        }else{
            return stoi(value);
        }
    };
};

class tree{
private:
    Node *root;
public:
    tree(){};

    float resolver(){
        return root->getValue();
    }
};

int main() {

    string formula;
    string formula2 = "";
    cin >> formula;

    stack <char> stack1;
    stack <char> stack2;

    for(auto c : formula){
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {
            if(c == '*' || c == '/'){

                while(stack1.top() == '+' || stack1.top() == '-'){
                    formula2  += stack1.top();
                    stack1.pop();
                }

            }

            stack1.push(c);

            c = 0;
        }else{
            formula2 += c;
        }



    }

    cout<<formula;


    return 0;
}