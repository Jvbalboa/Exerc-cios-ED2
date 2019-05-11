#include <iostream>
#include <time.h>

using namespace std;

int Hash(int valor, int tam); //Fun��o que gera a chave h
void insereVal(int val, int *vet, int tam); //Fun��o que insere o valor no vetor[h]

int main()
{
    int tam; //n�mero de elementos a serem gerados
    int sobra; //tamanho do vetor, com sobra
    cout << "Digite o tamanho do vetor: ";
    cin >> tam;
    //Calcula sobra ------------------------------------------------------
    if(tam<100)
        sobra = tam * 1.5;
    else
        sobra = tam * 1.15;
    //--------------------------------------------------------------------
    int *vet = new int[sobra];
    int val;
    //inicializa com -1
    for(int i=0; i<sobra; i++)
        vet[i] = -1;
    srand (time(NULL));
    //insere valores aleat�rios
    for(int i=0; i<tam; i++)
    {
        val = rand();
        insereVal(val, vet, sobra);
    }
    //Imprime vetor
    cout << endl;
    for(int i=0; i<sobra; i++)
        cout << vet[i] <<endl;
    return 0;
}

int Hash(int valor, int tam)
{
    return valor % tam;
}

void insereVal(int val, int *vet, int tam)
{
    int h = Hash(val, tam);
    bool inseriu = false;
    //Se a posi��o � vazia, insere
    if(vet[h] == -1)
    {
        vet[h] = val;
        inseriu = true;
        cout << "Valor = " << val << "  Chave = " << h << endl;
    }
    //Sen�o, procura uma posi��o
    else
    {
        for(int i=h+1; i<tam; i++)
            if(vet[i] == -1)
            {
                vet[i] = val;
                inseriu = true;
                cout << "Valor = " << val << "  Chave = " << i << endl;
                break;
            }
    }
    if(!inseriu)
        cout << "N�o h� mais espa�o " << "Chave: " << h <<endl;

}
