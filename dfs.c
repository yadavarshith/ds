#include <stdio.h>

int stack[5], top = -1, n, a[10][10], known[10];

void push(int val) {
    stack[++top] = val;
}

int pop() {
    int val = stack[top--];
    printf("%d ", val);
    return val;
}

int stackempty() {
    if(top==-1) return 1;
    else    return 0;
}
void dfs(int sv) {
    push(sv);
    known[sv] = 1;

    while (!stackempty()) {
        int v = pop();

        for (int i = 0; i < n; i++) {
            if (a[v][i] && !known[i]) { // If edge exists and not yet visited
                push(i);
                known[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, sv;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (i = 0; i < n; i++) {
        known[i] = 0; // Initialize the `known` array
    }

    printf("Enter the starting vertex (0 to %d): ", n - 1);
    scanf("%d", &sv);

    printf("DFS Traversal starting from vertex %d:\n", sv);
    dfs(sv);
    printf("\n");

    return 0;
}
