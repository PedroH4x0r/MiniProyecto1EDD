#include "ListArrClass.h"
#include <iostream>
#include <vector>
using namespace std;

ListArrClass::ListArrClass(int size){
    // Builder Class
    T = nullptr;
    T = new Node;
    T->size = size;
    T->n = 0;
    T->arr = new int[T->size];
    T->next = nullptr;
    root = nullptr;

}

ListArrClass::~ListArrClass(){

	Node* current = T; // Destroyer Class
	
	while(current != nullptr){

		Node* next = current -> next;


		delete[] current -> arr;
		delete current;
		current = next;

	}

}

int ListArrClass::size(){
        // Move on the list so it gives the total size of the arrays

	int aux = 0;
	Node* current = T;

	while(current != nullptr){

		aux += current -> n;
		current = current -> next;

	}

	return aux; // Returns the value after moving on all the list

}

void ListArrClass::insert_left(int v){
    
        // This if is for moving on the list and replacing the value ONLY if the nodes aren't full

    	if(T -> n < T->size){
        	for(int i = T->n; i > 0; i--){
            	
            	T->arr[i] = T->arr[i-1];
        	
        	}
        	
        	T->arr[0] = v;
        	T->n++;
        	
    	}
    
    	else{

            // Creates the new node and puts the value in if the nodes are full
        
        	Node* U = new Node;
        	U -> size = T -> size;
        	U -> n = 1;
        	U -> arr = new int[U -> size];
        	U-> next = T;
        	T = U;
        	T->arr[0] = v;
            
 
    	}

    


    



    arbol();
}

void ListArrClass::insert_right(int v){
        
        // Same as insert left but with a small variation for when nullptr is posible to be there

    	Node* current = T;

    	while(current->next != nullptr){
        
        	current = current->next;
    	}
    
    	if(current->n < current->size){
        
        	current->arr[current->n] = v;
        	current->n++;
    	}
    
    	else{

            // Creates the new node and puts the value in if the nodes are full

        	Node* aux = new Node;
        	aux->size = T->size;
        	aux->n = 1;
        	aux->arr = new int[aux->size];
        	aux->arr[0] = v;
        	aux->next = nullptr;
        	current->next = aux;

		}
	




	arbol();
}

void ListArrClass::insert(int v, int index) {

    // Checks for the range of the index

    if (index < 0 || index > size()) {
        cout << "Out of range index" << endl;
      
    }

    // If they ask at left insert at left, same with right

    if (index == 0) {
        insert_left(v);
     
    } else if (index == size()) {
        insert_right(v);
       
    }
    else{
    // find the node that contains the element at the given index
    Node* current = T;
    int currentIndex = 0;
    
    // Moving on the list

    while (current != nullptr) {
        if (currentIndex + current->n > index) {
            break;
        }
        currentIndex += current->n;
        current = current->next;
    }

    int moveIndex = index - currentIndex;

    if (current->n < current->size) {
        // Move elements to the right
        for (int i = current->n - 1; i >= moveIndex; i--) {
            current->arr[i + 1] = current->arr[i];
        }

        current->arr[moveIndex] = v;
        current->n++;
    } 

    else {
        
        // Create a new node if full
        Node* newNode = new Node;
        newNode->size = current->size;
        newNode->n = 0;
        newNode->arr = new int[newNode->size];
        newNode->next = current->next;

        current->next = newNode;

        // Move half of the elements to the new node
        int numToMove = current->n / 2;
        for (int i = numToMove; i < current->n; i++) {
            newNode->arr[i - numToMove] = current->arr[i];
            current->n--;
            newNode->n++;
        }

        // Move elements to the right
        for (int i = current->n - 1; i >= moveIndex; i--) {
            current->arr[i + 1] = current->arr[i];
        }

        current->arr[moveIndex] = v;
        current->n++;
    }
    }
    arbol();
}
void ListArrClass::print(){

    // Prints elements individually

	Node* aux = T;
	cout<<"[";
	while(aux != nullptr){
		
		for(int i=0; i < aux -> n; i++){

			cout << aux -> arr[i] << " ";
			
		}
		aux = aux -> next;
		
	}
    cout<<"]";
}

bool ListArrClass::find(int v){

    // Moves on the list to find the element asked, ALWAYS looking up until it finds the element of gets to a nullptr

    Node* current = T;

    while(current != nullptr) {

        for(int i = 0; i < current->n; i++) {
            if(current->arr[i] == v) {
                return true;
            }
        }

        current = current->next;
    }

    return false;
}

void ListArrClass::arbol(){


    int nodeamount = size() / T->size; // How much nodes we need
    root = new Node(); 
    Node* current = root;
    
    for(int i = 1; i < nodeamount; i++){
        
        current -> next = new Node(); // Creating new node and connecting it to the previous ones
        current = current -> next;
    }
}

