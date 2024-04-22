#include <iostream>
#include <fstream>
using namespace std;

void bubbleSort(int arr[], int n) // сортировка пузырьком
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    ifstream inputFile("input.txt"); // потоки для файла
    ofstream outputFile("output.txt");

    int n = 10;
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            inputFile >> arr[i][j];
        }
    }
    inputFile.close();

    // Сортировка диагоналей, параллельных побочной диагонали
    for (int k = 0; k < n; k++)
    {
        int diag[100];
        int k_diag = 0;
        for (int i = 0; i < n - k; i++)
        {
            diag[k_diag++] = arr[i][n - 1 - i - k];
        }
        bubbleSort(diag, k_diag);
        k_diag = 0;
        for (int i = 0; i < n - k; i++)
        {
            arr[i][n - 1 - i - k] = diag[k_diag++];
        }
    }

    for (int k = n - 2; k >= 0; k--)
    {
        int diag[100];
        int k_diag = 0;
        for (int i = 0; i < n - k; i++)
        {
            diag[k_diag++] = arr[i + k][n - 1 - i];
        }
        bubbleSort(diag, k_diag);
        k_diag = 0;
        for (int i = 0; i < n - k; i++)
        {
            arr[i + k][n - 1 - i] = diag[k_diag++];
        }
    }

    // Запись отсортированного массива в файл
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            outputFile << arr[i][j] << " ";
        }
        outputFile << "\n";
    }
    outputFile.close();

    return 0;
}