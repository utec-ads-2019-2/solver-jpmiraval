//
// Created by HP on 17/10/2019.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef SOLVER_DESDE_0_NODE_H
#define SOLVER_DESDE_0_NODE_H

class Node{
private:
    Node* hijos[2];
    string value;
public:

    string valor(){
        return value;
    }

    Node(string valor){
        value = valor;
        hijos[0] = nullptr;
        hijos[1] = nullptr;
    };

    Node* left(){
        return hijos[0];
    }

    Node* right(){
        return hijos[1];
    }

    bool llenarNodo(string valor){
        if(!lleno()){
            Node* temp = new Node(valor);
            insertar(temp);
            valor = "";
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
        }else if(isdigit(value[0])){
            return stof(value);
        }else{
            cout << "Ingrese el valor de " << value << endl;
            cin >> g;
            return stof(g);
        }
    };

    bool lleno(){
        if(isdigit(valor()[0])){
            return true;
        }else{
            if(hijos[1] && hijos[0]){
                if(hijos[1]->valor() == "+" || hijos[1]->valor() == "-" || hijos[1]->valor() == "*" || hijos[1]->valor() == "/" || hijos[1]->valor() == "+" || hijos[1]->valor() == "^"){
                    if(hijos[0]->valor() == "+" || hijos[0]->valor() == "-" || hijos[0]->valor() == "*" || hijos[0]->valor() == "/" || hijos[0]->valor() == "+" || hijos[0]->valor() == "^"){
                        return hijos[1]->lleno() and hijos[0]->lleno();
                    }else{
                        return hijos[1]->lleno();
                    }
                }else if(hijos[0]->valor() == "+" || hijos[0]->valor() == "-" || hijos[0]->valor() == "*" || hijos[0]->valor() == "/" || hijos[0]->valor() == "+" || hijos[0]->valor() == "^"){
                    return hijos[0]->lleno();
                }else{
                    return true;
                }
            }else{
                return false;
            }

        }


        return true;
    }

    void insertar(Node* newNode){
        if(hijos[1]){
            hijos[0] = newNode;
        }else{
            hijos[1] = newNode;
        }
    }

    ~Node(){
        delete hijos[0];
        delete hijos[1];
    }

};


#endif //SOLVER_DESDE_0_NODE_H
