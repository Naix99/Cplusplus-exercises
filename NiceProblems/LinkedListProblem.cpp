#include <bits/stdc++.h>

using namespace std;

// Problem of implementing a fusing of two linked list in to one (assuming they are ordered.)
// Really good idea on how to work with existent classes.

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * =This was the big part of the problem. Had a hard time getting all the reference right in my head.
 */
SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* &head1, SinglyLinkedListNode* &head2) {
    SinglyLinkedListNode* finallist = new SinglyLinkedListNode(0);
    SinglyLinkedListNode* finalhead  =finallist;
    SinglyLinkedListNode* dummy1 = head1; SinglyLinkedListNode* dummy2 = head2;
    while ((dummy1 != NULL)&&(dummy2 != NULL)){
        if (dummy1 ->data < dummy2 -> data){
            finalhead -> next = dummy1;
            dummy1 = dummy1 -> next; 
        }
        else{
            finalhead -> next = dummy2;
            dummy2 = dummy2 -> next; 
        }
        finalhead = finalhead -> next;
    }
    while (dummy1 != NULL){
        finalhead -> next = dummy1;
        dummy1 = dummy1 -> next; 
        finalhead = finalhead -> next;
    }
    while (dummy2 != NULL){
        finalhead -> next = dummy2;
        dummy2 = dummy2 -> next; 
        finalhead = finalhead -> next;
    }
    return finallist -> next;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}