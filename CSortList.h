#pragma once
#include "Node1.h"

class CSortList
{
private:
    Node* head;

public:
    // Constructor
    CSortList()
    {
        head = nullptr;
    }

    void Insert(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr || head->data > val) {
            newNode->next = head;
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr && curr->next->data < val) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }

    // Method for adding to head
    void AddToHead(int val)
    {
        Node* temp = new Node(val); 
        temp->next = head;
        head = temp;
    }

    // Method for sorting linked list using BubbleSort algorithm
    void BubbleSort(bool rising)
    {
        Node* curr = head;
        bool swapped = true;
        int temp;

        while (swapped)
        {
            swapped = false;
            curr = head;

            while (curr->next != nullptr)
            {
                if (rising ? curr->data > curr->next->data : curr->data < curr->next->data)
                {
                    temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = true;
                }
                curr = curr->next;
            }
        }
    }

    void SelectionSort(bool rising)
    {
        Node* i, * j, * temp;
        int temp_i;

        for (i = head; i != nullptr; i = i->next)
        {
            temp = i;

            for (j = i->next; j != nullptr; j = j->next)
            {
                if (rising ? j->data < temp->data : j->data > temp->data)
                {
                    temp = j;
                }
            }

            if (temp != i)
            {
                temp_i = i->data;
                i->data = temp->data;
                temp->data = temp_i;
            }
        }
    }

    void InsertionSort(bool rising)
    {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        Node* curr = head->next;
        Node* prev_curr = head;

        while (curr != nullptr) {
            Node* j = head;
            Node* prev_j = nullptr;
            bool is_sorted = true;

            while (j != curr) {
                if (rising ? j->data > curr->data : j->data < curr->data) 
                {
                    prev_curr->next = curr->next;

                    if (prev_j != nullptr) 
                    {
                        prev_j->next = curr;
                    }
                    else 
                    {
                        head = curr;
                    }

                    curr->next = j;

                    curr = prev_curr->next;
                    is_sorted = false;
                    break;
                }

                prev_j = j;
                j = j->next;
            }

            if (is_sorted) {
                prev_curr = curr;
                curr = curr->next;
            }
        }
    }

    // Method for displaying the linked list
    void Display()
    {
        Node* temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
}; 
