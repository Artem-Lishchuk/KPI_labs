#include <iostream>
#include "linkedList.h"




int main() {
    std::cout << "Hello, World!" << std::endl;
    LinkedList<double> list;
    cout << "A list of doubles is created. its size is equal to " << list.getSize() << endl;
    cout << "Inserting three elements to the list: " << endl;
    list.insert(0,1.3);
    list.insert(1,2.4);
    list.insert(2,3.5);
    cout << "A size of the list is: " << list.getSize() << endl;
    cout << "A list contains those elements: ";
    list.print();
    if (list.find(3.5)){
        cout << "A list contains the element 3.5" << endl;
    }
    if (!list.find(5.0)){
        cout << "A list does not contain the element 5.0" << endl;
    }
    cout << "Index of the element 2.4 is " << list.index(2.4) << endl;

    cout << "Traversal of linked list using iterators: ";
    LinkedList<double>::Iterator it = list.begin();
    do {
        cout << it.value() << " ";
        it++;
    } while (it != list.end());


    cout << endl << endl << endl;

    LinkedList<double> list2;
    cout << "A list of integers is created. its size is equal to " << list2.getSize() << endl;
    cout << "Inserting fours elements to the list: " << endl;
    list2.insert(0,2);
    list2.insert(1,10);
    list2.insert(2,17);
    list2.insert(2,19);
    cout << "A size of the list is: " << list2.getSize() << endl;
    cout << "A list contains those elements: ";
    list2.print();
    if (list2.find(17)){
        cout << "A list contains the element 17" << endl;
    }
    if (!list2.find(5)){
        cout << "A list does not contain the element 5" << endl;
    }
    cout << "Index of the element 2 is " << list2.index(2) << endl;

    cout << "Traversal of linked list using iterators: ";
    LinkedList<double>::Iterator it2 = list2.begin();
    do {
        cout << it2.value() << " ";
        it2++;
    } while (it2 != list2.end());

    return 0;
}
