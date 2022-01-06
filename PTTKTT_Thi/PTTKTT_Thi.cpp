#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
void swap(int& x, int& y);
void selectionSort(int a[], int n);
void insertionSort(int a[], int n);
void bubbleSort(int a[], int n);
void interchangeSort(int a[], int n);
void shellSort(int a[], int n);
void insertheap(int a[], int l, int r);
void heapSort(int a[], int n);
void quickSort(int a[], int l, int r);
void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);
void pigeonholeSort(int a[], int n);
void countingSort(int a[], int n);
void radixSort(int a[], int n);
void bucketSort(int a[], int n);
void readfile(int a[], int& n, const char filename[]);
void ghiFile(int a[], int n, const char filename[]);
void xuatMang(int a[], int n);
void menu();
int a[10000000];
void main()
{
    int n;
    int cn;
    do
    {
        

        menu();
        printf("\nBan hay chon mot chuc nang bat ky: ");
        scanf("%d", &cn);
        system("cls");

        switch (cn)
        {
        case 1:
        {
            readfile(a, n, "input1.inp");
            printf("\nNoi dung mang: ");
            xuatMang(a, n);
            break;
        }
        case 2:
        {
            readfile(a, n, "input2.inp");
            printf("\nNoi dung mang: ");
            xuatMang(a, n);
            break;
        }
        case 3:
        {
            selectionSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 4:
        {
            insertionSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 5:
        {
            bubbleSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 6:
        {
            interchangeSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 7:
        {
            shellSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 8:
        {
            heapSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 9:
        {
            quickSort(a, 0, n - 1);
            xuatMang(a, n);
            break;
        }
        case 10:
        {
            mergeSort(a, 0, n - 1);
            xuatMang(a, n);
            break;
        }
        case 11:
        {
            pigeonholeSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 12:
        {
            countingSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 13:
        {
            radixSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 14:
        {
            bucketSort(a, n);
            xuatMang(a, n);
            break;
        }
        case 15:
        {           
            ghiFile(a, n, "output.out");
            xuatMang(a, n);
            break;
        }
        default:
            break;
        }
    } while (cn != 0);
    getch();
}
void menu()
{
    
    printf("\nMenu");
    printf("\n0. Thoat chuong trinh");
    printf("\n1. Doc file 1000 va hien thi thong tin du lieu");
    printf("\n2. Doc file 2000000 va hien thi thong tin du lieu");
    printf("\n--------------------Thuat toan nhom 1--------------------");
    printf("\n3. xep theo Selection sort");
    printf("\n4. xep theo Insertion sort");
    printf("\n5. xep theo Bubble sort");
    printf("\n6. xep theo Interchange sort");
    printf("\n7. xep theo Shell sort");
    printf("\n--------------------Thuat toan nhom 2---------------------");
    printf("\n8. xep theo Heap sort");
    printf("\n9. xep theo Quick sort");
    printf("\n10. xep theo Merge sort");
    printf("\n--------------------Thuat toan nhom 3----------------------");
    printf("\n11. xep theo Pigeonhole sort");
    printf("\n12. xep theo Counting sort");
    printf("\n13. xep theo Radix sort");
    printf("\n14. xep theo Bucket sort");
    printf("\n------------------------------------------------------------");
    printf("\n15. Xuat ket qua vao file va hien thi ra man hinh");
}
void readfile(int a[], int& n, const char filename[])
{
    FILE* f;
    f = fopen(filename, "rt");
    fscanf(f, "%d", &n);
    for (int i = 0; i < n; i++)
        fscanf(f, "%d", &a[i]);
    fclose(f);
}
void ghiFile(int a[], int n, const char filename[])
{
    FILE* f;
    f = fopen(filename, "wt");
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%d ", a[i]);
    }
    fclose(f);
}
void xuatMang(int a[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%5d", a[i]);
}
void swap(int& x, int& y)
{
    int t = x;
    x = y;
    y = t;
}
void selectionSort(int a[], int n)
{
    int min;
    for (int i = 0; i < n - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        swap(a[min], a[i]);
    }
}
void insertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}
void bubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
}
void interchangeSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                swap(a[i], a[j]);
}
void shellSort(int a[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i += 1)
        {
            int temp = a[i];
            int j;
            for (j = i; j >= gap && a[j - gap] > temp; j -= gap)
                a[j] = a[j - gap];
            a[j] = temp;
        }
    }
}
void insertheap(int a[], int l, int r)
{
    int j;
    j = l * 2;
    while (j <= r)
    {
        if (j < r)
            if (a[j] < a[j + 1]) j++;
        if (a[j] <= a[l]) return;
        swap(a[l], a[j]);
        l = j;
        j = l * 2;
    }
}
void heapSort(int a[], int n)
{
    int l = n / 2;
    int r = n - 1;
    while (l >= 0)
        insertheap(a, l--, r);

    while (r > 0)
    {
        swap(a[0], a[r]);
        r--;
        insertheap(a, 0, r);
    }
}
void quickSort(int a[], int l, int r)
{
    int i = l, j = r, mid = (l + r) / 2;
    int x = a[mid];
    do
    {
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i < j) swap(a[i], a[j]);
        i++;
        j--;
    } while (i < j);
    if (l < j) quickSort(a, l, j);
    if (r > i) quickSort(a, i, r);
}
void merge(int a[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (i = 0; i < n1; i++)
        L[i] = a[l + i];
    for (j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);

        merge(a, l, m, r);
    }
}
void pigeonholeSort(int a[], int n)
{
    int min = a[0];
    int max = a[0];
    int i = 1;
    while (i < n)
    {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
        i++;
    }

    int range = max - min + 1;
    int* temp = (int*)malloc(range * sizeof(int));

    i = 0;
    while (i < range)
    {
        temp[i] = 0;
        i++;
    }

    i = 0;
    while (i < n)
    {
        temp[a[i] - min]++;
        i++;
    }

    int j = 0;
    i = 0;
    while (i < range)
    {
        while (temp[i] > 0)
        {
            a[j] = i + min;
            temp[i]--;
            j++;
        }
        i++;
    }
}
void countingSort(int a[], int n)
{
    int* output = (int*)malloc(n * sizeof(int));
    int max = a[0];
    int min = a[0];

    int i;
    for (i = 1; i < n; i++)
    {
        if (a[i] > max)
            max = a[i];
        else if (a[i] < min)
            min = a[i];
    }

    int k = max - min + 1;

    int* count = (int*)malloc(k * sizeof(int));
    for (i = 0; i < k; i++)
        count[i] = 0;

    for (i = 0; i < n; i++)
        count[a[i] - min]++;

    for (i = 1; i < k; i++)
        count[i] += count[i - 1];

    for (i = 0; i < n; i++)
    {
        output[count[a[i] - min] - 1] = a[i];
        count[a[i] - min]--;
    }

    for (i = 0; i < n; i++)
        a[i] = output[i];
}
void radixSort(int a[], int n)
{
    int m = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > m)
            m = a[i];

    for (int exp = 1; m / exp > 0; exp *= 10)
    {
        int* output = (int*)malloc(n * sizeof(int));
        int i, count[10] = { 0 };

        for (i = 0; i < n; i++)
            count[(a[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for (i = n - 1; i >= 0; i--)
        {
            output[count[(a[i] / exp) % 10] - 1] = a[i];
            count[(a[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            a[i] = output[i];
    }
}
void bucketSort(int a[], int n)
{
    int max = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    int* bucket = (int*)malloc((max + 1) * sizeof(int));
    for (int i = 0; i <= max; i++)
        bucket[i] = 0;

    for (int i = 0; i < n; i++)
        bucket[a[i]]++;

    for (int i = 0, j = 0; i <= max; i++)
    {
        while (bucket[i] > 0)
        {
            a[j++] = i;
            bucket[i]--;
        }
    }
}