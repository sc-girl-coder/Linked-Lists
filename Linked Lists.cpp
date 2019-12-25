/*
 Authors: Samantha Casler & Philip Cesani
 
 Program will create two linked lists with randomly generated numbers 0-25 and display them.
 Then it will create a third linked list with all of the first list followed
 by all of the second list and display it. Then a fourth linked list will be created with the
 numbers from the third linked list excluding those repeated and display it.
 The program will then insert 100 and 200 in the first two location of list four
 and append 88 and 99 numbers to the end of list four and display it. The program will
 continue and display number of elements in list four, delete the first number
 and the last number from list four and display it. And finally display list four backward.
 */

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberList{
private:
    struct ListNode{
        double value;
        ListNode *next;
    };
    ListNode *head;
    
public:
    NumberList();
    ~NumberList();
    void buildList();  // function to build lists 1 and 2 and output their values
    void createList3(NumberList, NumberList);  // function to build list 3 using the elements of lists 1 and 2 and output its values
    void createList4(NumberList);  // function to create list 4 using numbers not repeating from list 3
    void insertNum(double); //inserts a number to the beginning of the list
    void displayNumElem(); //displays the number of elements for list 4
    void deleteNum(double); //deletes a specific number from the list
    void Reverse(ListNode *); //reverses the linked list
    void printReverse(); //access the reverse function and prints out the linked list in reverse order
    void displayList(); //prints the linked list
    void removeDuplicates(ListNode *start); //removes duplicates from the linked list
    void appdendNode(double); //adds a value and a node to the end of the linked list
};

NumberList::NumberList(){
    head = NULL;
}

void NumberList::displayList(){
    if(head)
    {
        int count = 0;
        ListNode *nodePtr = head;  // begin nodePtr at the head of the list
        while (nodePtr)  // while nodePtr points to a node, traverse the list
        {
            if (count == 15)
                cout << "\n\t\t";
    
            cout <<  nodePtr->value << " ";  // display the value in the node
            nodePtr = nodePtr->next;  // move to the next node in the list
            
            count++; //adds 1 to count
        }
        cout << endl;
    }
}

// function to build lists 1 and 2 and output their values
void NumberList::buildList(){
    const int MAX_LENGTH = 15;  //constant integer to hold the maximum length of the lists
    ListNode *newNode;  //Points to a new node
    ListNode *nodePtr;  // pointer to move through the list
    
    
    for (int i = 0; i < MAX_LENGTH; i++){
        newNode = new ListNode; //creates a new node
        newNode->value = rand ()%25; //adds a random value to the node
        newNode->next = NULL; //moves the node to NULL
        
        if (!head) //if no head then create one
            head = newNode;
        else{
            nodePtr = head;  //initialize nodePtr to head of the list
            
            while (nodePtr->next)  //find the last node in the list
                nodePtr = nodePtr->next;
            
            nodePtr->next = newNode;  // insert newNode as the last node
        }
    }
    nodePtr = head;
    displayList();
}

//Takes two linked list and merges then into a singular list
void NumberList::createList3(NumberList list_1, NumberList list_2){
    const int MAX_LENGTH = 15;  //constant integer to hold the maximum length of the lists
    ListNode *newNode;  //Points to a new node
    ListNode *nodePtr;  // pointer to move through the list
    ListNode *list_1Ptr; //points to list one
    ListNode *list_2Ptr; //points to list two
    list_1Ptr = list_1.head;
    list_2Ptr = list_2.head;
    
    for (int i = 0; i < MAX_LENGTH; i++){
        newNode = new ListNode;
        newNode->value = list_1Ptr->value;
        newNode->next = NULL;
        
        if (!head)
            head = newNode;
        else{
            nodePtr = head;  //initialize nodePtr to head of the list
            
            while (nodePtr->next)  //find the last node in the list
                nodePtr = nodePtr->next;
            
            nodePtr->next = newNode;  // insert newNode as the last node
            
        }
        list_1Ptr = list_1Ptr->next;
    }
    
    for (int i = 0; i < MAX_LENGTH; i++){
        newNode = new ListNode;
        newNode->value = list_2Ptr->value;
        newNode->next = NULL;
        
        if (!head)
            head = newNode;
        else{
            nodePtr = head;  //initialize nodePtr to head of the list
            
            while (nodePtr->next)  //find the last node in the list
                nodePtr = nodePtr->next;
            
            nodePtr->next = newNode;  // insert newNode as the last node
        }
        list_2Ptr = list_2Ptr->next;
    }
    nodePtr = head;
    displayList();
}

void NumberList::createList4(NumberList list_3){
    const int MAX_LENGTH = 30;  //constant integer to hold the maximum length of the lists
    ListNode *newNode;  //Points to a new node
    ListNode *nodPtr;  // pointer to move through the list
    ListNode *list_3Ptr;
    list_3Ptr = list_3.head;
    
    for (int i = 0; i < MAX_LENGTH; i++){
        newNode = new ListNode;
        newNode->value = list_3Ptr->value;
        newNode->next = NULL;
        
        if (!head)
            head = newNode;
        else{
            nodPtr = head;  //initialize nodePtr to head of the list
            
            while (nodPtr->next)  //find the last node in the list
                nodPtr = nodPtr->next;
            
            nodPtr->next = newNode;  // insert newNode as the last node
            
        }
        list_3Ptr = list_3Ptr->next;
    }
    nodPtr = head;
    removeDuplicates(nodPtr);
    displayList();
}

//Inserts a new node with a value infront of the list
void NumberList::insertNum(double num){
    
    ListNode *tmp = new ListNode();
    tmp->value = num;
    tmp->next = head;
    head = tmp;
}

//Displays the number of elements
void NumberList::displayNumElem(){
    ListNode *nodePtr;
    nodePtr = head;
    int count = 0;
    while(nodePtr){
        nodePtr = nodePtr->next;
        count++;
    }
    cout << "\nThe Number of Elements in List_4 is: " << count << endl;
}

//Removes Duplicates from the linked list
void NumberList::removeDuplicates(ListNode *start){
    ListNode *ptr1;
    ListNode *ptr2;
    ListNode *dup;
    
    ptr1 = start;
    
    // Pick elements one by one
    while (ptr1 != NULL && ptr1->next != NULL){
        ptr2 = ptr1;
        
        // Compare the picked element with rest
        // of the elements
        while (ptr2->next != NULL){
            // If duplicate then delete it
            if (ptr1->value == ptr2->next->value){
                dup = ptr2->next; //sets dup to the duplicated node
                ptr2->next = ptr2->next->next; //moves ptr2 up to keep the linked list
                delete(dup);
            }
            else //Advance ptr2 to next
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}

//Add a node to the end of the list
void NumberList::appdendNode(double num){
    ListNode *newNode;
    ListNode *nodePtr;
    
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;
    
    nodePtr = head;
    while(nodePtr->next){
        nodePtr = nodePtr->next;
    }
    nodePtr->next = newNode;
}

//Deletes a specific number from the list
void NumberList::deleteNum(double num){
    ListNode *nodePtr;
    ListNode *previousNode;
    
    //if no head then leave
    if(!head)
        return;
    
    //if the number is in head then delete the node and move head forward
    if(head->value == num){
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    //else check the list for the number and delete if its in another node
    else{
        nodePtr = head;
        
        while (nodePtr != NULL && nodePtr ->value != num){
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr){
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

//Takes a Struct as a parameter and moves through the list recurrsively to display it backwards
void NumberList::Reverse(ListNode *nodePtr){
    if(nodePtr){
        Reverse(nodePtr->next);
        cout << nodePtr->value << " ";
    }
}

//Access the Reverse function to print the list backwards
void NumberList::printReverse(){
    Reverse(head);
}

NumberList::~NumberList(){
    ListNode *nodePtr;
    ListNode *nextNode;
    nodePtr = head;
    while (nodePtr) {
        nextNode = nodePtr->next;
        //delete nodePtr;
        nodePtr = nextNode;
    }
}

int main (){
    srand(time(0));
    cout << "Welcome to my Singly LL Program" << endl;
    
    NumberList list_1; //create list 1
    NumberList list_2; //create list 2
    NumberList list_3; //create list 3
    NumberList list_4; //create list 4
    
    //build list one
    cout << "List 1: " ;
    list_1.buildList();
    
    //build list two
    cout << "\nList 2: ";
    list_2.buildList();
    
    //build list three
    cout << "\nList 3: ";
    list_3.createList3(list_1, list_2);
    
    //build list four
    cout << "\nList 4: ";
    list_4.createList4(list_3);
    
    
    list_4.insertNum(200); //insert 200 to front
    list_4.insertNum(100); //insert 100 to front
    list_4.appdendNode(88); //insert 88 to the back
    list_4.appdendNode(89); //insert 89 to the back
    cout << "\nList 4 after insertion: ";
    list_4.displayList(); //displays list 4
    
    list_4.displayNumElem(); //displays the number if elements of list 4
    
    list_4.deleteNum(100); //deletes 100
    list_4.deleteNum(89); //deletes 89
    cout << "\nList 4 after deletion: ";
    list_4.displayList(); //displays list 4
    
    cout << "\nList 4 in reverse order: ";
    list_4.printReverse(); //prints list 4 in reverse
    cout << endl;
    
    
    cout << "\nThis Simple LL program is implemented by :\n";
    cout << "Samantha Casler & Philip Cesani - March 27th, 2019\n";
    
    return 0;
}


