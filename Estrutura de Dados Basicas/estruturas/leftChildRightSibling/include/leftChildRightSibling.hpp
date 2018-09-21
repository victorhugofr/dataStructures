#ifndef _LEFT_CHILD_RIGHT_SIBLING_HPP_
#define _LEFT_CHILD_RIGHT_SIBLING_HPP_
#include <iostream>
#include "node.hpp"

template <typename T>
class LeftChildRightSibling{
    public:
        T value;
        Node<T> *root;

        LeftChildRightSibling(T value){
            this->root = new Node<T>(value);
            this->root->sibling = this->root->child = NULL;
            this->root->value = value;
        }

        Node<T> *pushSibling(Node<T> *n, T value){
            if(n == NULL) return NULL;
            while(n->sibling)
                n = n->sibling;
            return (n->sibling = new Node<T>(value));
        }

        /*
        Queria colocar o Node<T> *n = root, mas ando tendo problemas
        Comparo se o n é nulo, se for ele assume o valor do root, se
        o root for nulo também, então retornamos nulo mesmo.
        Esse código ficaria mais elegante de aceitasse o parâmetro default
        */
        Node<T> *pushChild(T value, Node<T> *n = NULL){
            if(n == NULL){
                if(this->root == NULL) return NULL;

                n = root;
            }

            // Se o nó já tiver um filho então adicionamos um irmão
            if(n->child)
                return pushSibling(n->child, value);

            return (n->child = new Node<T>(value));
        }

        // Aqui também gostaria de um parâmetro default
        void print(Node<T> *n = NULL){
            if(n == NULL){
                if(this->root == NULL) return;

                n = root;
            }

            while(n){
                std::cout << " " << n->value;
                /*
                Todo nó só tem um filho ou um irmão, então caso
                exista filho fazemos uma chamada recursiva
                para imprimir os valores do nó filho, percorrendo
                assim nossa "árvore"
                */
                if(n->child)
                    print(n->child);

                n = n->sibling;
            }

        }
    int heightt(Node<T> *n) { 
        int h, t;
        if (n == NULL) 
            return -1; 
        h = 0; //height
        n = n->child; 
        while (n!= NULL) {
            t = heightt(n); 
            if (t > h)  
                h = t; 
            n = n->sibling; 
        } 
        return h+1; 
    }

        bool searchChild(Node<T> *child, T value) {
            if(child == NULL) {
                return false;
            } else if(child->value == value || searchSibling(child->sibling, value)) {
                return true;
            }

            return searchChild(child->child, value);
        }

        bool searchSibling(Node<T> *sibling, T value) {
            if(sibling == NULL) {
                return false;
            } else if(sibling->value == value || searchChild(sibling->child, value)) {
                return true;
            }
            
            return searchSibling(sibling->sibling, value);
        }

        bool search(T value) {
            return this->searchChild(this->root, value);
        }
};

#endif