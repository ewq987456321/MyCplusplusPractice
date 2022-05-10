#include <cstdio>
#include <cstdlib>

int main() {
    int n;
    do {
        scanf("%d", &n);
    } while (n <= 0);
    int **arr = (int **)malloc(sizeof(int *) * n);
    int *count = (int *)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) {
        do {
            scanf("%d", &count[i]);
        } while (count[i] <= 0);
        arr[i] = (int *)calloc(count[i], sizeof(int));
        // arr[i] = (int *)malloc(sizeof(int) * count[i]);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count[i]; j++) {
            printf("%d", arr[i][j]);
        }
        printf("123\n");
    }
    for (int i = 0; i < n; i++) {
        free(arr[i]);
    }
    free(arr);
    free(count);
}
