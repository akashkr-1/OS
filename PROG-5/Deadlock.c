#include <stdio.h>

void deadlockDetection(int n, int m, int alloc[n][m], int request[n][m], int avail[m]) {
    int finish[n], safeSeq[n];
    int i, j, k, count = 0;

    for (i = 0; i < n; i++)
        finish[i] = 0;

    while (count < n) {
        int found = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 1;
                for (j = 0; j < m; j++) {
                    if (request[i][j] > avail[j]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if (!found) {
            printf("System is not in a safe state (Deadlock detected).\n");
            return;
        }
    }

    printf("System is in safe state.\nSafe Sequence is: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");
}

int main() {
    printf("USN: 1BM24CS027\n");
    int n, m, i, j;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], request[n][m], avail[m];

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter the request matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &request[i][j]);

    printf("Enter the available resources:\n");
    for (j = 0; j < m; j++)
        scanf("%d", &avail[j]);

    deadlockDetection(n, m, alloc, request, avail);

    return 0;
}
