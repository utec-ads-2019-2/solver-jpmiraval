#include <iostream>
#include <string>
#include <stdlib.h>
#include <stack>
#include <map>
#include <cmath>
#include <vector>

using namespace std;

class Node{
private:
    Node* hijos[2];
    string value;
public:

    string valor(){
        return value;
    }

    Node(string valor):value(valor){
        hijos[0] = nullptr;
        hijos[1] = nullptr;
    };

    Node* left(){
        return hijos[0];
    }

    Node* right(){
        return hijos[1];
    }

    bool llenarNodo(char valor){
        string valorcito2 = "";
        if(!lleno()){
            valorcito2 += valor;
            Node* temp = new Node(valorcito2);
            insertar(temp);
            valorcito2 = "";
            return true;
        }
        return false;
    }

    float getValue(){
        string g;
        if(value == "+"){
            return hijos[0]->getValue() + hijos[1]->getValue();
        }else if(value == "-"){
            return hijos[0]->getValue() - hijos[1]->getValue();
        }else if(value == "*"){
            return hijos[0]->getValue() * hijos[1]->getValue();
        }else if(value == "/"){
            return hijos[0]->getValue() / hijos[1]->getValue();
        }else if(value == "^"){
            return pow(hijos[0]->getValue(), hijos[1]->getValue());
        }else if (value == "1" || value == "2" || value == "3" || value == "4" || value == "5" || value == "6" || value == "7" || value == "8" || value == "9" || value == "0"){
            return stof(value);
        }else{
            cout << "Ingrese el valor de " << value << endl;
            cin >> g;
            return stof(g);
        }
    };

    bool lleno(){
        if(hijos[0]&& hijos[1]){
            if(hijos[0]->valor()!= "+" || hijos[0]->valor()!= "-" || hijos[0]->valor()!= "*" || hijos[0]->valor()!= "/"){
                if(hijos[1]->valor()!= "+" || hijos[1]->valor()!= "-" || hijos[1]->valor()!= "*" || hijos[1]->valor()!= "/"){
                    return true;
                }else{
                    return hijos[1]->lleno();
                }
            }else{
                return hijos[0]->lleno();
            }
        }else{
            return false;
        }


        return true;
    }
    bool hayLeft(){
        return (hijos[0] && hijos[1]);
    }

    void insertar(Node* newNode){
        if(hijos[1]){
            hijos[0] = newNode;
        }else{
            hijos[1] = newNode;
        }
    }

};

class tree{
private:
    Node *root;

    void printTree(Node* puntero){
        cout << "valor nodo:"<<endl;
        cout << puntero->valor()<<endl;
        if(puntero->right()){
            cout << "Para la derecha: " << endl;
            printTree(puntero->right());
        }

        if(puntero->left()){
            cout << "Para la Izquierda: " << endl;
            printTree(puntero->left());
        }

        cout <<"Para arriba" << endl;

    }

    void insert_Node(char nodo, Node* puntero){
        string temporal = "";
        temporal += nodo;
        Node* temp = new Node(temporal);
        if(puntero->right()){
            if(puntero->right()->lleno()){
                if(puntero->left()){
                    insert_Node(nodo, puntero->left());
                }else{
                    puntero->insertar(temp);
                }

            }
            else if(puntero->right()->valor() == "*" || puntero->right()->valor() == "+" || puntero->right()->valor() == "-" || puntero->right()->valor() == "/"){
                insert_Node(nodo, puntero->right());
            }else if(puntero->left()){
                insert_Node(nodo, puntero->left());
            }else{
                puntero->insertar(temp);
            }
        }else{
            puntero->insertar(temp);
        }
    }
public:
    tree(Node* raiz):root(raiz){};

    float resolver(){
        return root->getValue();
    }

    void set_Root(Node *root){
        this->root = root;
    }

    Node* get_Root(){
        return root;
    }
    void insertar(char nodo){
        insert_Node(nodo, root);
    }

    void print(){
        printTree(root);
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

            while(!stack1.empty() && stack1.top()!= '(' && stack1.top()!=')' && (mapita[c]<= mapita[stack1.top()]) && c != '(' && c != ')'){

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
    valorcito+=stack2.top();
    Node* raiz = new Node(valorcito);

    tree* Arbol = new tree(raiz);
    stack2.pop();

    while(!stack2.empty()){
        Arbol->insertar(stack2.top());
        cout << stack2.top();
        stack2.pop();
    }

    cout << "\n\n";
    Arbol->print();
    cout << "\n\n";

    //cout << Arbol->get_Root()->left()->valor() << endl;
    //cout << Arbol->get_Root()->right()->valor() << endl;
    //cout << Arbol->get_Root()->left()->left()->valor() << endl;
    //cout << Arbol->get_Root()->left()->right()->valor() << endl;
    //cout << Arbol->get_Root()->right()->left()->right()->valor() << endl;
    //cout << Arbol->get_Root()->right()->right()->valor() << endl;

    cout << Arbol->resolver();
    return 0;
}
