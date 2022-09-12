#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>
#include <iterator>

using namespace std;

int main(void)
{
    vector<string> texto;
    vector<int> caracteres;
    ifstream entrada {"texto.txt"};

    // testamos se o arquivo foi aberto, senão aborta
    if(entrada.is_open() == false)
        throw runtime_error{"Nao foi possivel abrir arquivo!"};

    // iterador que pode ler objetivos do tipo T de uma entrada
    istream_iterator<string>  iter_entrada( entrada );

    // copia inserindo cada palavra lida no vetor
    //  - istream_iterator<string>() é um iterador vazio, ou seja, o fim da entrada
    //  - back_inserter( texto ) é um iterador que permite inserir no fim
    copy( iter_entrada, istream_iterator<string>(), back_inserter(texto));

    // aplica uma função lambda para cada palavra do texto, e insere o resultado
    // no vetor caracteres
    transform( texto.begin(), texto.end(), back_inserter(caracteres), 
         [](string s){ return s.size(); } );

    // copia cada elemento no iterador de saida
    // - ostream_iterator escreve elementos T na saída (cout) com separado "\n"
    copy( caracteres.begin(), caracteres.end(), ostream_iterator<int>{cout, "\n"} );

    return 0;
}