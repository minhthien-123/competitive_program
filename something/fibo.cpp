#include <iostream>
#include <time.h>
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;  // uint = 0 -> 2^32-1

#define maxd 25000
#define rdigit 9

#define bdigit 30
#define radix (1 << 30)
#define radix9 1000000000

using namespace std;

int plus2(uint *a, uint *b, uint *c, int d)
{
    uint n = 0;
    for (int i = 0; i < d; i++) {
        n += b[i] + c[i];  // sum with carry
        a[i] = n & (radix - 1); // and with (radix - 1) ~ mod
        n = n >> 30; // shift right ~ div 2^bdigit
    }
    if (n > 0) a[d++] = n;   // add a new digit
    return d;
}

int plus9(uint *a, uint *b, uint *c, int d)
{
    uint n = 0;
    cout<<"a[2] in plus "<<b[d-1]<<endl;
    for (int i = 0; i < d; i++) {
        n += b[i] + c[i];  // add with carry
        a[i] = n % radix9;
        n /= radix9;
        cout<<endl<<"n = "<<n<<endl;
    }
    if (n > 0) a[d++] = n;   // add a new digit
    cout<<"d = "<<d<<endl;
    cout<<"a[d-1] in plus "<<a[d-1]<<endl;
    return d;
}

int nhanhe10_9voi1so(uint * a, int d, uint x) { // a la so trong he co so 10^9,
                                      //0 <= x < 10^9
    int i;
    long long n = 0;
    for (i=0; i<d; i++) {
        n = a[i] * (long  long) x + n;
        a[i] = n % radix9;
        n = n / radix9;
    }
    if (n > 0) {
        a[d] = n;
        d++;
    }

    return d;
}

uint so[2] = {73741824, 1}; // Day la so bieu dien 2^30 = 1,073,741,824

int max2(int a, int b) {
    if (a > b) return a;
        else return b;
}

int nhan2sotronghe10_9(uint * a, int d) {
    int i, d2;
    uint temp[maxd];
    memset(temp, maxd * sizeof(uint), 0);
    for (i=0; i<d; i++) temp[i+1] = a[i];
    cout<<temp[d]<<endl;
    temp[0] = 0;
    d2 = d+1;

    d = nhanhe10_9voi1so(a, d, so[0]);

    d = max2(d, d2);
    for (i=d+1; i<d2; i++) a[i] = 0;
    for (i=d2+1; i<d; i++) temp[i] = 0;
    cout<<endl<<"temp[d-1] in nhan 2 so = "<<temp[d-1]<<endl;
    d = plus9(a, temp, a, d);
    cout<<"a[d-1] in nhan 2 so: "<<a[d-1]<<endl;
    return d;
}

int hoocne(uint * a, int d) {
    int i;
    uint temp[maxd];
    memset(temp, maxd * sizeof(uint), 0);
    temp[0] = a[d-1];
    int d2 = 1;
    uint temp2[maxd];

    for (i=d-1; i>=1; i--) {
        d2 = nhan2sotronghe10_9(temp, d2);
        temp2[0] = a[i-1];
        int k;
        for (k=1; k<d2; k++) temp2[i] = 0;
        d2 = plus9(temp, temp, temp2, d2);
    }

    for (i=0; i<d2; i++) a[i] = temp[i];
    cout<<"OK";
    return d2;
}

int main() {
    time_t start = clock();

    int n = 999, d = 1;

    uint f[3][maxd];
    for (int i = 0; i < 3; i++)
        //memset(f[i], maxd * sizeof(uint), 0);   // fill zero
        for (int j=0; j<maxd; j++) f[i][j] = 0;
    f[1][0] = 1;        // f(1) = 1; 0 is position of first digit
    f[2][0] = 2;

    for (int i = 3; i <= n; i++) {   //compute f(i)
        int i0 = i % 3, i1 = (i-1) % 3, i2 = (i-2) % 3;
                         // indexes of f(i), f(i-1), f(i-2)
        d = plus2(f[i0], f[i1], f[i2], d);
        if (i % 100000 == 0)
           printf("%d with %d digits.\n", i , d);
    }

    printf("Number of digits (in array): %d\n", d);
    time_t end = clock();
    printf("Computing time (seconds): %d\n", (end - start) / CLOCKS_PER_SEC );

//f[n%3][0] = 473741824;
//f[n%3][1] = 13;
//d = 2;
    d = hoocne(f[n%3], d);
    //d = nhan2sotronghe10_9(f[n%3], d);

printf("F(%d) =  \n", n);
int i;
printf("%u.", f[n%3][d-1]);
for (i=d-2;i>=0; i--) printf("%09u.", f[n%3][i]);

    getchar();
    return 0;
}
