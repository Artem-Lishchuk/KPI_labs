//
// Created by lishc on 5/13/2023.
//

#ifndef LAB6_LINKEDLIST_H
#define LAB6_LINKEDLIST_H

using namespace std;

template <typename T>
class Node{
public:
    T data;
    Node* prev;
    Node* next;
    Node(T data, Node* prev = nullptr, Node* next = nullptr) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
    Node(){
        this->prev = nullptr;
        this->next = nullptr;
    }
};



template<class T>
class LinkedList{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;
public:

    class Iterator{
    private:
        Node<T>* node;
    public:
        Iterator(){
            this->node = nullptr;
        }
        Iterator(Node<T>* nod) {
            this->node = nod;
        }

        bool operator!=(const Iterator& iterator)
        {
            return node != iterator.node;
        }

        Iterator operator++(){
            if (node)
                node = node->next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        Iterator operator--(){
            if(node)
                node = node->prev;
            return *this;
        }

        Iterator& operator=(const Iterator& it){
            node = it.node;
            return *this;
        }

        Node<T>* getNode(){
            return node;
        }

        T value() const {
            return node->data;
        }

        void setNode(Node<T>* nod){
            this->node = nod;

        }
    };

    LinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    int getSize(){
        return this->size;
    }

    bool find(T value){
        Node<T>* node = head;
        while(node){
            if(value == node->data){
                return true;
            }
            node = node->next;
            if (node == head){
                return false;
            }
        }
        return false;
    }

    bool isEnd(Iterator& iterator){
        return iterator == end();
    }

    int index(T value){
        int ind = 1;
        Node<T>* current = head;
        if(current == nullptr){
            return -1;
        }
        while(current){
            if(value == current->data){
                return ind;
            }
            ind++;
            current = current->next;
            if(current == head){
                return -1;
            }
        }
        return -1;
    }

    void insert(int pos, T value){
        if(pos < 0 || pos > size){
            cout << "Impossible to insert the node at the current position" << endl;
        }

        Node<T>* node = new Node(value);
        if (pos == 0){
            if (head == nullptr) {
                // List is empty
                head = node;
                tail = node;
                head->next = tail;
                head->prev = tail;
                tail = node;
                tail->next = head;
                tail->prev = head;
            }
            else{
                node->prev = head->prev;
                node->next = head;
                head->prev->next = node;
                head->prev = node;
                head = node;
            }
        }
        else if(pos == size){
            node->prev = tail;
            node->next = head;
            head->prev = node;
            tail->next = node;
            tail = node;
        }
        else{
            Node<T>* current = head;
            for (int i = 0; i < pos - 1; i++) {
                current = current->next;
            }
            node->next = current->next;
            current->next->prev = node;
            node->prev = current;
            current->next=node;
        }
        size ++;
    }

    void print() const {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
            if (current == head) {
                break;
            }
        }
        cout << endl;
    }

    Iterator begin(){
        return Iterator(head);
    }

    Iterator end(){
        return Iterator(tail->next);
    }

};

#endif //LAB6_LINKEDLIST_H
