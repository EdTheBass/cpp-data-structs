#include <iostream>
#define LOG(x) std::cout << x << std::endl
#define LOG_e(x, y) std::cout << x << y
#define NEWLINE() std::cout << std::endl;

class Node {
    public:
        int val;
        Node *next = NULL;
        Node(int val) {
            this->val = val;
        }
};

class LinkedList {
    public: 
        Node *first = NULL;
        Node *last = NULL;
        LinkedList(std::initializer_list<int> vals) {
            for (int i : vals) {
                if (first == NULL) {
                    first = new Node(i);
                    last = first;
                } else {
                    last->next = new Node(i);
                    last = last->next;
                }
            }
        }
        int get(int index) {
            Node *curr = first;
            for (int i=0;i<index;i++) {
                curr = curr->next;
            }
            return curr->val;
        }
        int len() {
            Node *curr = first;
            int len = 1;
            while (curr->next != NULL) {
                curr = curr->next;
                len++;
            }
            return len;
        }
        void log() {
            Node *curr = first;
            while (curr->next != NULL) {
                LOG_e(curr->val, ",");
                curr = curr->next;
            }
            LOG(curr->val);
        }
        void append(int val) {
            Node *newNode = new Node(val);
            Node *curr = first;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
        void insert(int val, int index) {
            Node *newNode = new Node(val);
            Node *curr = first;
            for (int i=0;i<index-1;i++) {
                curr = curr->next;
            }
            newNode->next = curr->next;
            curr->next = newNode;
        }
        void reverse() {
            Node *curr = first;
            Node *prev = first;
            Node *next;
            int len = 1;
            while (true) {
                if (len == 1) {
                    len++;
                    next = curr->next;
                    curr->next = NULL;
                    curr = next;
                } else if (curr->next == NULL) {
                    curr->next = prev;
                    break;
                } 
                else {
                    len++;
                    next = curr->next;
                    curr->next = prev;
                    prev = curr;
                    curr = next;
                }
            }
            last = first;
            first = curr;
        }
        void sort() {
            Node *curr = first;
            Node *next = curr->next;
            int tmp;
            bool changed = true;
            int len = 1;
            while (changed) {
                changed = false;
                curr = first;
                next = curr->next;
                while (curr->next != NULL) {
                    if (curr->val > next->val) {
                        changed = true;
                        tmp = curr->val;
                        curr->val = next->val;
                        next->val = tmp;
                    }
                    curr = curr->next;
                    next = curr->next;
                }
            }
        }
};
