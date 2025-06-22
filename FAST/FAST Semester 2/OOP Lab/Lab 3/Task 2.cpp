#include <iostream>
using namespace std;

char** AllocateMemory(int &rows, int &cols){
char ** arr;
     arr = new char*[rows];
for(int i=0;i<rows;i++){
        arr[i] = new char[cols];
    }

    return arr;
}
void InputMatrix(char** matrix, const int rows, const int cols){

    for(int i=0;i<rows; i++){
        for(int j=0;j<cols;j++){
            cout << "["<<i<<"]["<<j<<"]";
            cin >> matrix[i][j];
        }
    }
}
void DisplayMatrix(char **matrix, const int &rows, const int &cols){
    for(int i=0;i<rows; i++){
        for(int j=0;j<cols; j++){
            cout << matrix[i][j] <<"  ";
        }
        cout << endl;
    }
}

char Adding(int &s1 , int &s2 , int &s3 , int &rows , int &cols , char **matrix)
{
    char *alphabets = new char[s1];
    char *numbers = new char[s2];
    char *specialchar = new char[s3];

    for(int  i = 0 ; i < rows ; i++)
    {
        for(int j = 0 ; j <  cols ; j++)
        {
            if((matrix[i][j] >= 65 && matrix[i][j] <=90) || (matrix[i][j] >= 97 && matrix[i][j] <= 122))
            {
                alphabets[i] = matrix[i][j];
            }
            else if(matrix[i][j] >= 48 && matrix[i][j] <= 57)
            {
                numbers[i] = matrix[i][j];
            }
            else{
                specialchar[i] = matrix[i][j];
        }
        }
    }

    for(int i = 0 ; i < sizeof(alphabets) ; i++)
    {
            cout << alphabets[i] << " "<<endl;
    }
     for(int i = 0 ; i < sizeof(numbers) ; i++)
     {

            cout << numbers[i] << " "<<endl;
     }
     for(int i = 0 ;i < sizeof(specialchar) ; i++)
     {
            cout<<specialchar[i] << " ";
    }
}

char* Resizing(char*& rold,long int rnew)
{
char* ptr;
ptr = new char[ rnew ];
for(long int i = 0;i < rnew ; ++i)
ptr [i] = rold[i];
delete [] rold;
rold = nullptr;
return ptr;
}


int main()
{
    int rows , cols;
    int s1 = 4 , s2 = 4 , s3 = 4;
    cout << "Enter Number of Rows : ";
    cin >> rows;
    cout << "Enter Number of Columns : ";
    cin >> cols;
    char **matrix;
    AllocateMemory(rows, cols);
    InputMatrix(matrix, rows, cols);
    DisplayMatrix(matrix, rows, cols);
    Adding(s1 , s2 , s3 , rows , cols , matrix);
    return 0;
}
