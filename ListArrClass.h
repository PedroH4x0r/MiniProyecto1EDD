#include "ListArr.h"

class ListArrClass:public ListArr{

private:

    struct Node{

        int* arr;
        int size; // Capacidad del arreglo
        int n; // Contador


        Node* next;
        Node* der;
        Node* izq;


    };

    Node* T;
    Node* root;

public:

    ListArrClass(int size);

    ~ListArrClass();

    int size();

    void insert_left(int v);

    void insert_right(int v);

    void insert(int v, int i);

    void print();

    bool find(int v);

    void arbol();


};
