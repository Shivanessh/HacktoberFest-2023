#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int shortestCommonSupersequenceLength(char X[], char Y[], int dp[][strlen(Y) + 1]) {
    int m = strlen(X);
    int n = strlen(Y);

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0)
                dp[i][j] = j; // If X is empty, the SCS is Y's length
            else if (j == 0)
                dp[i][j] = i; // If Y is empty, the SCS is X's length
            else if (X[i - 1] == Y[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1]; // Characters match
            else
                dp[i][j] = 1 + max(dp[i - 1][j], dp[i][j - 1]); // Choose the best option
        }
    }

    return dp[m][n];
}

void printSCS(char X[], char Y[]) {
    int m = strlen(X);
    int n = strlen(Y);
    int dp[m + 1][n + 1]; // Declare the dp array here

    int SCSLength = shortestCommonSupersequenceLength(X, Y, dp);
    char SCS[SCSLength + 1];

    int i = m, j = n, k = SCSLength;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            SCS[k - 1] = X[i - 1];
            i--;
            j--;
            k--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            SCS[k - 1] = X[i - 1];
            i--;
            k--;
        } else {
            SCS[k - 1] = Y[j - 1];
            j--;
            k--;
        }
    }

    while (i > 0) {
        SCS[k - 1] = X[i - 1];
        i--;
        k--;
    }

    while (j > 0) {
        SCS[k - 1] = Y[j - 1];
        j--;
        k--;
    }

    SCS[SCSLength] = '\0'; // Null-terminate the string

    // Reverse the SCS since it was constructed backwards
    for (int l = 0; l < SCSLength / 2; l++) {
        char temp = SCS[l];
        SCS[l] = SCS[SCSLength - l - 1];
        SCS[SCSLength - l - 1] = temp;
    }

    printf("Length of Shortest Common Supersequence: %d\n", SCSLength);
    printf("Shortest Common Supersequence: %s\n", SCS);
}

int main() {
    char X[] = "ABCBDAB";
    char Y[] = "BDCABA";

    printSCS(X, Y);

    return 0;
}
