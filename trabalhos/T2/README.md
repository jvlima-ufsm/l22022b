
# T2 - Campo minado

## Deadline

Prazo: **05/10/2022 (Qua)** pelo link do GitHub (https://classroom.github.com/a/tFNAO2Xo).

Você deve escolher seu nome na lista de alunos. Em seguida, o GitHub irá criar um repositório deste trabalho em seu usuário.

## Descrição

O jogo Campo Minado tem por objetivo revelar um campo de minas sem que alguma delas seja detonada.  O campo é organizado em quadrados que podem conter uma mina, ou um número informando o número de minas adjacentes a esse quadrado.

Por exemplo, em um campo 4x4 com duas minas (`*`):
```
....
*...
....
.*..
```
A representação com as minas e os números adjacentes:
```
1100
*100
2210
1*10
```

O objetivo deste T2 é receber um campo com minas e imprimir o campo com os números de minas adjacentes.

O programa deve ler o campo da entrada padrão (`std::cin`) no formato abaixo onde a primeira linha é o tamanho do campo (máximo de 50) seguido do campo com as minas.
```
4
....
*...
....
.*..
```

Vocês pode testar o programa com um campo em arquivo `txt` e executando como abaixo:
```
$ ./t2 < campo.txt
1100
*100
2210
1*10
```

## Dicas
- Utilize `std::string` como forma de ler palavras ou linhas do texto.
- O programa tem que fazer uso de alocação dinâmica de memória.
- Veja como ler uma linha inteira [aqui](../../aulas/introducao_cxx#entrada-e-saída).
- O código abaixo é um exemplo de como converter `std:string` para `char*`
```c++
#include <iostream>
#include <string>
#include <cstring>

int main(int argc, char** argv)
{
    std::string palavra;
    char* vetor;

    std::cin >> palavra; // vai ler apenas uma palavra digitada

    if(palavra.size() > 0){ // testa se palavra nao eh vazia
        vetor = new char[palavra.size() + 1]; // aloca tamanho da palavra mais 1 para `\0' no fim

        strncpy(vetor, palavra.c_str(), palavra.size());  // copia n bytes

        vetor[palavra.size()] = '\0'; // copia '\0' no fim apenas por garantia

        std::cout << "Copiado "  << palavra.size() <<  " bytes no vetor: " << vetor << std::endl;

        delete[] vetor; // libera memoria
    }
    return 0;
}
```

## Regras

- Usar somente C++!
- Obrigatório: `new` e `delete` para alocação dinâmica
- A correção utilizará principalmente o `valgrind`
- Não compila, zero.
- Plágio, zero.