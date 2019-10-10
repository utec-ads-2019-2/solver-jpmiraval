#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <map>
#include <vector>

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
    map <char, int> mapita;
    mapita.insert(pair <char, int> ('-', 1));
    mapita.insert(pair <char, int> ('+', 1));
    mapita.insert(pair <char, int> ('*', 2));
    mapita.insert(pair <char, int> ('/', 2));
    mapita.insert(pair <char, int> ('(', 4));
    mapita.insert(pair <char, int> (')', 4));

    vector <string> vector2;
    int counter = 0;
    string valorcito = "";





    for(auto c : formula){
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {

                while(!stack1.empty() && (mapita[c]>= mapita[stack1.top()])){
                    valorcito += stack1.top();
                    vector2.push_back(valorcito);
                    valorcito = "";
                    stack1.pop();
                }

            stack1.push(c);

            c = ' ';
        }else{
            valorcito += c;
            vector2.push_back(valorcito);
            valorcito = "";
        }

        counter++;
    }

    for(auto d : vector2){
        cout << d;
    }


    return 0;
}