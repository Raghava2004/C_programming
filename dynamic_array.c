#include <stdio.h>
#include <stdlib.h>

struct list {
    int *data;
    int numItems;
    int size;
};  

void append(struct list *l, int item);

int main() {
    int amount = 0;
    char c;
    struct list l;
    l.numItems = 0;
    l.size = 2;
    l.data = malloc(l.size * sizeof(int));

    if (l.data == NULL) {
        printf("Memory can't be initialized.\n");
        return 1;
    }

    printf("Enter the number of elements: ");
    scanf("%d", &amount);

    for (int i = 0; i < amount; i++) {
        append(&l, i + 1);
    }

    printf("List appended. Press 'P' to print the data: ");
    scanf(" %c", &c);

    if (c == 'P' || c == 'p') {
        for (int i = 0; i < l.numItems; i++) {
            printf("%d ", l.data[i]);
        }
        printf("\n");
    }

    free(l.data);
    l.data = NULL;
    return 0;
}

void append(struct list *l, int item) {
    if (l->numItems >= l->size) {
        l->size += 2;
        l->data = realloc(l->data, l->size * sizeof(int));
        if (l->data == NULL) {
            printf("Memory reallocation failed.\n");
            exit(1);
        }
    }

    l->data[l->numItems] = item;
    l->numItems++;
}
