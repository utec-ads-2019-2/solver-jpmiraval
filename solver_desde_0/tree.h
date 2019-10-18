//
// Created by HP on 17/10/2019.
//

#ifndef SOLVER_DESDE_0_TREE_H
#define SOLVER_DESDE_0_TREE_H

#include "node.h"

using namespace std;

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

    void insert_Node(string nodo, Node* puntero){
        Node* temp = new Node(nodo);

        if(puntero->right()){
            if(!puntero->right()->lleno()){
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
    void insertar(string nodo){
        insert_Node(nodo, root);
    }

    void print(){
        printTree(root);
    }

    ~tree(){
        delete root;
    }

};

#endif //SOLVER_DESDE_0_TREE_H
