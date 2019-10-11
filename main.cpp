
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <map>
#include <vector>

using namespace std;

class Node{
private:
    Node* hijos[2];
    string value;
public:
    Node(string valor):value(valor){
        hijos[1] = nullptr;
        hijos[2] = nullptr;
    };

    float getValue(){
        if(value == "+"){
            return hijos[1]->getValue() + hijos[2]->getValue();
        }else if(value == "-"){
            return hijos[2]->getValue() - hijos[2]->getValue();
        }else if(value == "*"){
            return hijos[1]->getValue() * hijos[2]->getValue();
        }else{
            return stof(value);
        }
    };

    bool lleno(){
        return (hijos[1] && hijos[2]);
    }

    void insertar(Node* newNode){
        if(hijos[1] != nullptr){
            hijos[1] = newNode;
        }else if(hijos[2] != nullptr){
            hijos[2] = newNode;
        }
    }

};

class tree{
private:
    Node *root;
public:
    tree(){};

    float resolver(){
        return root->getValue();
    }

    void set_Root(Node *root){
        this->root = root;
    }

    Node* get_Root(){
        return root;
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
    mapita.insert(pair <char, int> (')', 0));

    vector <string> vector2;
    int counter = 0;
    string valorcito = "";





    for(auto c : formula){
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')') {

                while(!stack1.empty() && stack1.top()!= '(' && stack1.top()!=')' && (mapita[c]>= mapita[stack1.top()]) && c != '(' && c != ')'){

                        stack2.push(stack1.top());
                        stack1.pop();

                }

            stack1.push(c);
        }else{
            stack2.push(c);
        }

    }



    while(!stack1.empty()){
        if(stack1.top() != '(' && stack1.top() != ')'){
            stack2.push(stack1.top());
        }

        stack1.pop();
    }

    /*string x = "";
    x+= stack2.top();

    tree *Arbol = new tree;

    Node *raiz = new Node(x);
    Node *temp;

    Arbol->set_Root(raiz);

    stack2.pop();

*/

    while(!stack2.empty()){
        cout << stack2.top();
        stack2.pop();
    }




    return 0;
}
