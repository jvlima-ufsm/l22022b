#include <iostream>
#include <algorithm>
#include <fstream>
#include <iterator>

using namespace std;

int main(void)
{
    ifstream entrada {"numeros.txt"};
    // testamos se o arquivo foi aberto, senão aborta
    if(entrada.is_open() == false)
        throw runtime_error{"Nao foi possivel abrir arquivo!"};

    // iterador que pode ler objetivos do tipo T de uma entrada
    istream_iterator<int>  iter_entrada( entrada );

    // copia inserindo cada numero lido no vetor
    //  - istream_iterator<int>() é um iterador vazio, ou seja, o fim da entrada
    //  - ostream_iterator escreve elementos T na saída (cout) com separado "\n"
    copy( iter_entrada, istream_iterator<int>(), ostream_iterator<int>{cout, "\n"}  );

    return 0;
}