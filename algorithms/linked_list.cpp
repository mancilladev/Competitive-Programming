#include <iostream>

struct node {
    long data;
    node* next;
};

class LinkedList {
    private:
        node* head = NULL;
        node* tail = NULL;

    public:
        void print (void) {
            if (!head) {
                std::cout << "[]" << std::endl;
                return;
            }
            std::cout << "[" << head->data << ", ";
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
                std::cout << temp->data << ", ";
            }
            std::cout << "\b\b]" << std::endl;
        }

        void prepend(long num)
        {
            node* temp = new node;
            temp->data = num;
            if (head) temp->next = head;
            else tail = temp;
            head = temp;
        }

        // it could be a great idea to append args
        void append(long num) {
            node* temp = new node;
            temp->data = num;
            if (!head) head = temp;
            else tail->next = temp;
            tail = temp;
        }

        long pop()
        {
            long to_return;
            node* temp = head;
            if (!temp->next) {
                to_return = temp->data;
                head = tail = NULL;
                return to_return;
            } else {
                node* next_temp = temp->next;
                while (next_temp->next) {
                    temp = next_temp;
                    next_temp = temp->next;
                }
                to_return = next_temp->data;
                tail = temp;
                temp->next = NULL;
                next_temp = NULL;
                return to_return;
            }
        }

        int search(long num)
        {
            int pos = 0;
            node* temp = head;
            while (temp->next) {
                if (temp->data == num) return pos;
                temp = temp->next;
                pos++;
            }
            if (temp->data == num) return pos;
            throw -1;
        }
};

int main(void)
{
    LinkedList list;
    list.prepend(5);
    list.pop();
    list.print();
    list.append(14);
    list.append(8);
    list.append(17);
    list.print();
    std::cout << "pop return:" << list.pop() << std::endl;
    list.print();
    list.prepend(21);
    list.print();
    std::cout << list.search(21) << std::endl;
    std::cout << list.search(8) << std::endl;
    return 0;
}
