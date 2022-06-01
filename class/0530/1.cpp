#include <iostream>
#include <string>

using namespace std;

struct stake {
    char symbol = '0';
    stake *nextPtr = NULL;
};

bool push(char in, stake **head) {
    stake *current = *head;
    stake *add = new stake;
    add->symbol = in;
    if (current == NULL) {
        *head = add;
    } else {
        add->nextPtr = current;
        *head = add;
    }
    return true;
}

bool pop(char out, stake **head) {
    stake *current = *head;
    stake *del = *head;
    if (current != NULL && (current->symbol == '(' && out == ')' || current->symbol == '[' && out == ']' ||
                            current->symbol == '{' && out == '}')) {
        if (current == NULL) {
            return false;
        } else {
            *head = current->nextPtr;
            delete del;
        }
        return true;
    } else
        return false;
}

void free_data(stake **head) {
    stake *current = *head;
    while (*head != NULL) {
        stake *del = *head;
        current = *head;
        *head = current->nextPtr;
        delete del;
    }
}

int main(int argc, char *argv[]) {
    stake *head = NULL;
    string input, ans;
    bool checkout, checkin;
    while (cin >> input) {
        checkout = true;
        checkin = false;
        ans = "";
        for (int i = 0; i < input.length(); i++) {
            if (input[i] == '(' || input[i] == '[' || input[i] == '{') {
                checkin = push(input[i], &head);
            } else if (input[i] == ')' || input[i] == ']' || input[i] == '}') {
                checkout = pop(input[i], &head);
                if (!(checkout)) break;
            }
        }
        ans = (head == NULL && checkin && checkout) ? "vaild" : "invaild";
        cout << ans << endl;
        free_data(&head);
    }
    return 0;
}
