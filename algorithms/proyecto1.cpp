#include <iostream>
#include <string>

struct stacknode {
    char c;
    stacknode* next;
};

class Dstack
{
    private:
        int size = 0;
        stacknode* top = NULL;

    public:
        void get_data()
        {
            std::string pattern;
            printf("Ingresa el patrón: ");
            getline(std::cin, pattern);
            for (auto c : pattern) {
                if (c == '(' || c == ')') push(c);
            }
        }

        int len() { return size; }

        void push(char cp)
        {
            size++;
            stacknode* temp_new = new stacknode;
            temp_new->c = cp;
            if (top) temp_new->next = top;
            top = temp_new;
        }

        char pop()
        {
            if (!top) throw;
            size--;
            char pop_value = top->c;
            stacknode* temp_pointer = top;
            top = temp_pointer->next;
            temp_pointer = NULL;
            return pop_value;
        }

        void print()
        {
            if (!top) return;
            stacknode* temp_pointer = top;
            do {
                std::cout << temp_pointer->c << std::endl;
                temp_pointer = temp_pointer->next;
            } while (temp_pointer);
        }

        bool balanced()
        {
            if (size%2 != 0) return false;
            int closing = 0;
            int opening = 0;
            stacknode* temp_pointer = top;
            while (temp_pointer) {
                if (temp_pointer->c == ')') ++closing;
                else if (temp_pointer->c == '(') {
                    if (opening == closing) return false;
                    else ++opening;
                }
                temp_pointer = temp_pointer->next;
            }
            if (closing != opening) return false;
            return true;
        }
};

int main(void)
{
    Dstack stack;
    stack.get_data();
    printf("Balanced: %d\n", stack.balanced());
    return 0;
}
