// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;
unsigned long long N;
long long** matrix;
long long** matrixproduct(long long** matrixA,long long** matrixB)
{
    long long** product = new long long* [2];
    product[0] = new long long[2];
    product[1] = new long long[2];
    product[0][0] = matrixA[0][0] * matrixB[0][0]+ matrixA[0][1] * matrixB[1][0];
    product[0][1] = matrixA[0][0] * matrixB[0][1]+ matrixA[0][1] * matrixB[1][1];
    product[1][0] = matrixA[1][0] * matrixB[0][0]+ matrixA[1][1] * matrixB[1][0];
    product[1][1] = matrixA[1][0] * matrixB[0][1]+ matrixA[1][1] * matrixB[1][1];
    product[0][0] %= 1000000007;
    product[0][1] %= 1000000007;
    product[1][0] %= 1000000007;
    product[1][1] %= 1000000007;
    return product;
}
long long** fibonacci(long long n)
{
    if (n < 0)
    {
        long long** zeros = new long long* [2];
        zeros[0] = new long long[2];
        zeros[1] = new long long[2];
        zeros[0][0] = 0;
        zeros[0][1] = 0;
        zeros[1][0] = 0;
        zeros[1][1] = 0;
        return zeros;
    }
    else if (n < 2)
    {
        return matrix;
    }
    long long** product=fibonacci(n/2);
    if (n % 2 != 0)
    {
        return matrixproduct(matrixproduct(product, product), matrix);
    }
    else
    {
        return matrixproduct(product, product);
    }
}
int main()
{
    matrix = new long long* [2];
    matrix[0] = new long long[2];
    matrix[1] = new long long[2];
    matrix[0][0] = 1;
    matrix[1][0] = 1;
    matrix[0][1] = 1;
    matrix[1][1] = 0;
    cin >> N;
    cout << fibonacci(N-1)[0][0];
}
