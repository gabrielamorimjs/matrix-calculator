#include <iostream>
#include <cstdlib>
#include <limits>

const int M_SIZE = 3;
typedef double matrix[M_SIZE][M_SIZE];

void mostraMatriz(const matrix &mat);
bool inputMatriz(matrix &mat);
void adicaoMatriz(const matrix &mat1, const matrix &mat2, matrix &result);
void subtracaoMatriz(const matrix &mat1, const matrix &mat2, matrix &result);
void multiplicacaoMatriz(const matrix &mat1, const matrix &mat2, matrix &result);
void transpostaMatriz(const matrix &mat1, matrix &result);
void defineMatriz();

using namespace std;

matrix matrizA;
matrix matrizB;
matrix result;

int main()
{
    int escolha = -1;

    cout << "Ao preencher as matrizes, separe os elementos individuais \n"
            "por um espaco (Por exemplo: 2 4 1.4 56.3...) \n\n";

    defineMatriz();

    system("CLS");

    while (escolha != 3)
    {
        cout << "Matriz A:\n";
        mostraMatriz(matrizA);
        cout << "\nMatriz B:\n";
        mostraMatriz(matrizB);

        cout << "\n** Voce escolhe uma das seguintes **\n\n"
             << "0 - Redefine Matriz\n"
             << "1 - Adicao\n"
             << "2 - Subtracao\n"
             << "3 - Multiplicacao\n"
             << "4 - Transposta\n"
             << "5 - Sair\n\n"
             << "Digite o numero que representa sua escolha do menu: ";

        while (!(cin >> escolha))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "\nERROR: Por favor, insira uma entrada valida!\n"
                 << "Insira sua escolha novamente: ";
        }

        cout << endl;

        switch (escolha)
        {
        case 0:
            defineMatriz();
            break;

        case 1:
            adicaoMatriz(matrizA, matrizB, result);
            cout << "A adicao de Matriz A e Matriz B eh:\n";
            mostraMatriz(result);
            break;

        case 2:
            subtracaoMatriz(matrizA, matrizB, result);
            cout << "Subtracao de Matriz A e Matriz B eh:\n";
            mostraMatriz(result);
            break;
        case 3:
            multiplicacaoMatriz(matrizA, matrizB, result);
            cout << "Multiplicacao de Matriz A e Matriz B eh:\n";
            mostraMatriz(result);
            break;
        case 4:
            transpostaMatriz(matrizA, result);
            cout << "Tranposta de Matriz eh:\n";
            mostraMatriz(result);
            break;
        case 5:
            cout << "Obrigado por usar, Felipe! :D\n";
            break;

        default:
            cout << "Isso nao eh uma escolha.\n";
        }

        cout << "\nPressione qualquer tecla...\n";

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();

        system("CLS");
    }

    return 0;
}

void defineMatriz()
{
    while (true)
    {
        cout << "insira 9 elementos em sua matriz A 3x3: \n";
        if (inputMatriz(matrizA))
            break;
    }

    while (true)
    {
        cout << "insira 9 elementos em sua matriz 3x3 B: \n";
        if (inputMatriz(matrizB))
            break;
    }
}

void mostraMatriz(const matrix &mat)
{
    for (int i = 0; i < M_SIZE; i++)
    {
        cout << "[";
        for (int j = 0; j < M_SIZE; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << "]" << endl;
    }
}

bool inputMatriz(matrix &mat)
{
    for (int i = 0; i < M_SIZE; i++)
    {
        for (int j = 0; j < M_SIZE; j++)
        {
            cin >> mat[i][j];
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cerr << "\nERROR: Por favor, insira uma entrada valida!\n"
                     << endl;
                return false;
            }
        }
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return true;
}

void adicaoMatriz(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for (int i = 0; i < M_SIZE; i++)
    {
        for (int j = 0; j < M_SIZE; j++)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtracaoMatriz(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for (int i = 0; i < M_SIZE; i++)
    {
        for (int j = 0; j < M_SIZE; j++)
        {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplicacaoMatriz(const matrix &mat1, const matrix &mat2, matrix &result)
{
    for (int i = 0; i < M_SIZE; i++)
    {
        for (int j = 0; j < M_SIZE; j++)
        {
            result[i][j] = mat1[i][j] * mat2[i][j];
        }
    }
}

void transpostaMatriz(const matrix &mat1, matrix &result)
{
    for (int i = 0; i < M_SIZE; i++)
    {
        for (int j = 0; j < M_SIZE; j++)
        {
            result[i][j] = mat1[j][i];
        }
    }
}
