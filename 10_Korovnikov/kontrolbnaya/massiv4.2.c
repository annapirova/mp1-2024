#include"stdio.h"
int ZaMass(int A[])
{
    int a;
    printf("Kol-vo chisel v massive:");
    scanf_s("%d", &a);
    printf("Vvodite chisla: |a|<50\n");
    for (int i = 0; i < a; i++) { printf("nom.%d - ", i + 1); scanf_s("%d", &A[i]); }
    for (int i = 0; i < a; i++) { printf(" %d ", A[i]); }
    return a;
}
void Vivod(int A[], int s)
{
    for (int i = 0; i < s; i++) { printf(" %d ", A[i]); }
    printf("\n");
}
void Pere()
{
    printf("\n");
}
int Ob(int A[], int B[], int C[], int x, int y)
{
    int min = 100000, max = -100000, absol;
    int k = 0, w = 0; int S[100] = { 0 };
    for (int i = x; i < x + y; i++)
    {
        for (int j = k; j < y; j++)
        {
            A[i] = B[j]; break;
        }
        k++;
    }
    for (int i = 0; i < x + y; i++)
    {
        if (A[i] > max)max = A[i];
        if (A[i] < min)min = A[i];
    }
    if (max < 0)max = max * (-1);
    if (min < 0)min = min * (-1);
    if (max > min)absol = max; else absol = min;
    for (int i = 0; i < x + y; i++)
    {
        C[A[i] + absol]=1;
        S[A[i] + absol]++;
        if (S[A[i] + absol] == 1) w += 1; else w += 0;
    }
    k = 0;
    for (int i = 0; i <= 100; i++)
    {
        for (int j = 0; j < C[i]; j++)
        {
            A[k] = i - absol;
            k++;
        }
    }
    return x+y-w;
} 
int main()
{
    int x = 0, y = 0; int q = 0;
    int A[100] = { 0 }, B[100] = { 0 }, C[100] = { 0 };
    x = ZaMass(A); Pere(); y = ZaMass(B); Pere(); printf("\n1st:\n"); Vivod(A, x); printf("\n2nd:\n"); Vivod(B, y);
    q = Ob(A, B, C, x, y); Pere(); Vivod(A, x + y-q);

}