#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <math.h>
struct LL {
    int num = 0;
    LL *next = NULL;
};

int main() {
    LL *head = NULL, *current;
    char in;
    int total = 0, middle = 0, count = 0;
    float average = 0, SD = 0, SD_pre = 0;
    scanf("%c", &in);
    while (in != '\0') {
        if (in != 10) {
            printf("%d\n", in - '0');
            int in_int = in - '0';
            total += in_int;
            count += 1;

            LL *add = (LL *)malloc(sizeof(LL));
            add->num = in_int;
            add->next = head;
            head = add;
        }
        scanf("%c", &in);
    }
    current = head;
    for (int i = 0; i < count / 2; i++) {
        current = current->next;
    }
    average = total / (float)count;

    printf("total: %d\n", total);
    printf("average: %f\n", average);
    printf("middle: %d\n", current->num);
    current = head;
    while (current != NULL) {
        SD_pre += pow(current->num - average, 2);
        current = current->next;
    }
    SD_pre /= count;
    SD = sqrt(SD_pre);
    printf("SD: %f\n", SD);
}
