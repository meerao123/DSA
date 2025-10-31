#include <stdio.h>

void sortDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n, k;
    printf("Enter number of events: ");
    scanf("%d", &n);

    int A[n];
    printf("Enter activity points for each event:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);

    printf("Enter maximum events you can participate in (k): ");
    scanf("%d", &k);

    sortDesc(A, n);

    int sum = 0;
    for (int i = 0; i < k && i < n; i++)
        sum += A[i];

    printf("Maximum activity points you can earn = %d\n", sum);

    return 0;
}
