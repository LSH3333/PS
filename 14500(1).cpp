#include <iostream>
using namespace std;

int main() {
    int n, m; /* 세로 n, 가로 m */
    cin >> n >> m;

    int arr[501][501];

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    int sum = 0;

    /* ㅁㅁㅁㅁ */
    for(int i = 0; ; i++) {
        if(i == n) break;
        for(int j = 0; ; j++) {
            if(j+3 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i][j+3]);
        }
    }

    /* ㅁ
       ㅁ
       ㅁ
       ㅁ */
    for(int i = 0; ; i++) {
        if(i+3 == n) break;
        for(int j = 0; ; j++) {
            if(j == m) break;
            sum = max(sum, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+3][j]);
        }
    }

    /* ㅁㅁ
       ㅁㅁ  */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j +1 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1]);
        }
    }

    /* ㅁ ㅁ ㅁ
          ㅁ    */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+1]);
        }
    }

    /* ㅁ
       ㅁ ㅁ
       ㅁ    */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+1][j+1]);
        }
    }

    /*    ㅁ
       ㅁ ㅁ ㅁ */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2]);
        }
    }

    /*  ㅁ
      ㅁ ㅁ
         ㅁ  */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1]);
        }
    }

    /* ㅁ
       ㅁ
       ㅁ ㅁ */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j] + arr[i+1][j] + arr[i+2][j] + arr[i+2][j+1]);
        }
    }

    /*      ㅁ
       ㅁ ㅁ ㅁ */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j+2] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2]);
        }
    }

    /*  ㅁ ㅁ
           ㅁ
           ㅁ   */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j+1]);
        }
    }

    /* ㅁ
       ㅁ ㅁ ㅁ */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+1][j+2]);
        }
    }

    /* ㅁ ㅁ
       ㅁ
       ㅁ    */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i+1][j] + arr[i+2][j]);
        }
    }

    /*   ㅁ
         ㅁ
      ㅁ ㅁ  */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j+1] + arr[i+1][j+1] + arr[i+2][j] + arr[i+2][j+1]);
        }
    }

    /* ㅁ ㅁ ㅁ
       ㅁ        */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j]);
        }
    }

    /* ㅁ ㅁ ㅁ
            ㅁ  */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i][j+2] + arr[i+1][j+2]);
        }
    }

    /*  ㅁ
        ㅁ ㅁ
           ㅁ  */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j+1]);
        }
    }

    /*   ㅁ ㅁ
       ㅁ ㅁ     */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j+1] + arr[i][j+2] + arr[i+1][j] + arr[i+1][j+1]);
        }
    }

    /*    ㅁ
       ㅁ ㅁ
       ㅁ   */
    for(int i = 0; ; i++) {
        if(i+2 == n) break;
        for(int j = 0; ; j++) {
            if(j+1 == m) break;
            sum = max(sum, arr[i][j+1] + arr[i+1][j] + arr[i+1][j+1] + arr[i+2][j]);
        }
    }

    /*  ㅁ ㅁ
           ㅁ ㅁ */
    for(int i = 0; ; i++) {
        if(i+1 == n) break;
        for(int j = 0; ; j++) {
            if(j+2 == m) break;
            sum = max(sum, arr[i][j] + arr[i][j+1] + arr[i+1][j+1] + arr[i+1][j+2]);
        }
    }

    cout << sum;
}
