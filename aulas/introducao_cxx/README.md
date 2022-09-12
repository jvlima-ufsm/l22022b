
# Introdução a C++

O objetivo desta página é mostrar os principais conceitos de C++ que o diferem de C.

**IMPORTANTE**:  a biblioteca padrão C++ já possui muitas coisas prontas. Então, sempre procure os métodos disponíveis antes de reinventar a roda!

## Olá mundo

```C++
#include <iostream>

int main(void)
{
	std::string mensagem{"Ola mundo!"}
	// isso é um comentário
	std::cout << "Saida: " << mensagem << std::endl;
}
```

O que notamos nesse exemplo:
- ```iostream``` para entrada e saída básica
- ```std::string``` é uma estrutura (/classe/) C++ para string
- ```std::cout``` é a saída padrão
- ```std::endl``` é uma nova linha (```\n```)

## Compilação

Semelhante ao C, pode-se usar o GCC (```g++```) e Clang (```clang++```).  Em ambos
o C++11 pode não ser padrão, então precisamos passar a opção
```-std=c++11```:
```bash
g++ -std=c++11 -O2 -Wall -g  -o ola ola.cpp
```
**DICA:** Clang mostra erros de compilação de forma mais amigável, além de
ser mais eficiente que o GCC.

## Linha de comando

Para ler os parâmetros da linha de comando, use os parâmetros da ```main```
```argc``` e ```argv```.  O exemplo abaixo imprime todos os parâmetros passados:

```C++
#include <iostream>

// argc é o número de parâmetros passados
// argv é um vetor de strings com os valores
int main(int argc, char **argv)
{
    for(auto i= 0; i < argc; i++){
        std::cout << "Param " << i << " valor -> "
            << argv[i] << std::endl;
    }
    return 0;
}
```

## Variáveis

Declarações em C++ são semelhantes em C, com algumas melhorias.

### auto

Pode-se usar ```auto``` quando o tipo é deduzido pelo compilador como em:
```C++
auto x = 1;          // inteiro
auto y = 2.0;        // double
auto teste = true;   // booleano

// i abaixo é um inteiro
for(auto i= 0; i < 10; i++)
	std::cout << "Valor: " << i << std::endl;
```
### Inicialização padrão
É uma forma de padronizar a inicialização de variáveis em C++ usando
```{}```.  Por exemplo:
```C++
double x {1.0};                 // declara um double
int    a[] {1, 2, 3, 4};        // vetor com 4 elementos sem = 
int    b[] = {1, 2, 3, 4};      // mesma coisa
std::string nome {"Meu nome"} ; // uma string
```

**ATENÇÃO:** não funciona com *auto*.

### Casting (conversão)

C++ apresenta quatro tipos de conversão:
- ```static_cast``` converte entre tipos relacionados como ```int``` para ```char```,
ou ```double*``` para ```int*```.
- ```reinterpret_cast``` converte tipos não relacionados como inteiro para
  ponteiro, ou vice-versa.
- ```const_cast``` converte tipos que deferem quando são ```const``` ou ```volatile```.
- ```dynamic_cast``` (*não usado aqui*) converte com checagem de tipo em
  tempo de execução.

Alguns exemplos:
```C++
int num = 97;                        // inteiro
char letra = static_cast<char>(num); // agora letra A

char *dados = new char[100];          // 100 chars alocados
int* vetor = reinterpret_cast<int*>(dados); // mudei agora para int
```

## Passagem de parâmetros

### Referência
Passagem por referência possibilita passar variáveis por 
*referência* ao invés de valor ou ponteiro.
No exemplo abaixo, tem-se a opção de valor e referência ```&```:

```C++
void f(int val, int& ref)
{
    val++;   // incrementa a cópia local de val
    ref++;   // incrementa realmente a variável
}
```

**IMPORTANTE**: evite usar passagem por referência porque deixa o programa
mais difícil de entender.  Use apenas quando queremos evitar uma cópia
e não vamos alterar a variável (```const```), como por exemplo um vetor ou
uma string:
```C++
void imprimir(const std::string& texto) 
{
    std::cout << texto << std::endl; // não altera variável
}
```

## Estrutura de dados

A linguagem oferece estruturas semelhantes ao C chamadas *plain old
data* (POD), ou seja, sem funcionalidades de orientação a objetos do
C++. 
O uso de estruturas C++ oferece algumas vantagens em relação ao
C para desta disciplina (*eu acho*):
- Declaração de variável não precisa da palavra *struct*.
- Pode-se usar inicialização padrão, e incluir métodos dentro da
  estrutura.

Veja o exemplo:
```C++
#include <iostream>
#include <cmath>

struct Ponto {
    float x;
    float y;

    // zera o ponto 
    void zera(void) {
        x = 0.0f;
        y = 0.0f;
    }

    // distância deste ponto (x, y) até p1
    float distancia(Ponto& p1) const {
        return std::sqrt( std::pow((x-p1.x), 2) + std::pow((y-p1.y), 2) );
    }
};

int main(void)
{
    Ponto p1 {1.0, 1.0};
    Ponto p2;
    p2.zera();
    p2.x = 19.0;
    p2.y = 20.0;

    auto distancia = p1.distancia(p2);
    std::cout << "Distancia: " << distancia << std::endl;
}
```
Temos duas funções da estrutura ```Ponto```: ```zera()``` e ```distancia()```.  As duas
são da estrutura e manipulam ```(x,y)``` de cada variável.

Note que foi utilizada a inicialização padrão, iniciando os campos de ```Ponto``` em ordem:
```C++
Ponto p1 {1.0, 1.0};
```

## Entrada e saída 

As operações são efetuadas por *streaming* ou fluxo onde dados são lidos
ou escritos em sequência. Para tanto, C++ tem os streamings:
- ```std::ifstream``` para leitura.
- ```std::ofstream``` para escrita.

Neste exemplo são lidos dois números (```>>```) e escritos dois (```<<```).  Note
que a operação de *saída* é ```<<``` (esquerda) e *entrada* é ```>>``` (direita).
```C++
#include <iostream>
#include <fstream>

int main(void)
{
    int n1, n2;
    std::ifstream entrada {"entrada.txt"};
    std::ofstream saida {"saida.txt"};
    entrada >> n1 >> n2;
    saida << n1 << " " << n2 << std::endl;
    return 0;
}
```
Se queremos ler ```n``` números, precisamos testar se o arquivo terminou
ou *end-of-file* (EOF). Basta usar a função ```eof()```:
```C++
#include <iostream>
#include <fstream>

int main(void)
{
    int n;
    std::ifstream entrada {"numeros.txt"};
    std::ofstream saida {"saida.txt"};

    if(entrada.is_open() == false)
        throw std::runtime_error{"Nao foi possivel abrir arquivo!"};

    while(entrada.eof() == false){
        entrada >> n;
        saida << n << std::endl;
    }

    entrada.close();
    saida.close();
    return 0;
}
```

Caso precisamos ler algumas variáveis e depois o resto da linha,
podemos usar  ```std::getline``` que lê tudo até o final da linha em 
uma ```std::string```. 
Nesse exemplo, usa-se a função para ler matrícula e nome de um aluno
do arquivo ```alunos.txt```:
```C++
#include <iostream>
#include <fstream>
#include <vector>

struct Aluno {
    int matricula;
    std::string nome;
};

int main(void)
{
    int matricula;
    std::string nome;
    std::vector<Aluno> alunos;             // vetor de alunos
    std::ifstream entrada {"alunos.txt"};
    while( entrada >> matricula ) {        // le matricula por linha
        std::getline(entrada, nome);       // le resto da linha (nome)
        alunos.push_back( Aluno{matricula, nome} ); // adiciona no vetor
    }

    for(Aluno& v: alunos)
        std::cout << v.matricula << " -> " << v.nome << std::endl;
    return 0;
}
```

## Tratamento de erros

O tratamento de erros em C++ pode ser feito com exceções.
Alguns códigos mostram uma palavra-chave ```throw``` usada em C++ para criar uma
exceção ou erro em tempo de execução.
Uma  exceção padrão é a ```std::runtime_error```.

Um exemplo é um programa que só aceita números positivos:
```C++
#include <iostream>

int main(void)
{
    int n;
    std::cout << "Digite um numero: ";
    std::cin >> n;
    if(n < 0)
        throw std::runtime_error {"Digite apenas numeros positivos!"};
    std::cout << n << std::endl;
    return 0;
}
```

Tratar exceções depende da estrutura ```try/catch```, onde
o bloco ```try```  é o código protegido e ```catch``` é executado
somente quando ocorrer uma exceção.
```C++
#include <iostream>

int main(void)
{
    try {
        throw std::runtime_error{"um erro qualquer"};   // cria erro
    } catch(std::exception& e) {
        std::cout << "ERRO: " << e.what() << std::endl; // trata exceção
        throw;                                          // recria
    }
    return 0;
}
```

## Alocação de memória

### New e delete
A linguagem oferece a função ```new``` e ```delete``` para alocar e
liberar memória, respectivamente.
```C++
int* ptr1 = nullptr;       // nullptr é NULL em C++
int* ptr2 {nullptr};       // inicializador padrão

auto num = new int;       // aloca inteiro
*num = 33;
delete num;               // libera memória

auto vetor = new int[10]; // vetor de 10 números
delete[] vetor;           // libera um vetor 

int* vetor {new int[10]}; // outra forma
delete[] vetor;
```

### Matrizes

Pode-se criar matrizes como em C, porém com ```new``` e ```delete```.
Basta um vetor de ponteiros (```int**```) com cada posição um vetor (```int*```).

No exemplo abaixo, qualquer outro tipo pode ser usando trocando ```int``` por 
outro tipo.
```C++
int** matriz {nullptr};
int N = 10;
matriz = new int*[N];        // vetor com ponteiros
for(auto i = 0; i < N; i++)
    matriz[i] = new int[N];  // linha da matriz

// inicia valores
for(auto i = 0; i < N; i++)
    for(auto j = 0; j < N; j++)
        matriz[i][j] = 0;

// destroi matriz: cada linha e depois matriz
for(auto i = 0; i < N; i++)
    delete[] matriz[i];
delete[] matriz;
```

### Smart pointers
O suporte a *smart pointers* auxilia no gerênciamento de memória.  Ele
elimina a necessidade de liberar memória (*delete*), sendo liberada
automaticamente quando o programa não usa mais.

Nós veremos o uso dos ponteiros ```unique_ptr```, que armazena 
um ponteiro em modo exclusivo (único dono).
```C++
#include <iostream>
#include <memory>

int main(void)
{
    auto ptr1 = std::unique_ptr<int> {new int};           // ponteiro int
    *ptr1 = 13;                                           // inicializa valor
    std::cout << ptr1.get() << " " << *ptr1 << std::endl; // imprime o endereço e valor

    auto vetor = std::unique_ptr<int[]> {new int[10]};    // vetor de int (int[])
    for(auto i= 0; i < 10; i++)
        vetor[i] = i;

    // sem necessidade de delete: quando terminar a memória é liberada
    return 0;
}
```

Pode-se também retornar um ```unique_ptr``` de uma função:
```C++
#include <iostream>
#include <memory>

std::unique_ptr<float[]> 
foo(int n)
{
    std::unique_ptr<float[]> novo {new float[n]};
    return novo;
}

int main(void)
{
    auto vetor = foo(10);
    for(auto i= 0; i < 10; i++){
        vetor[i] = static_cast<float>(i)/10;
        std::cout << i << " -> " << vetor[i] << std::endl;
    }
    return 0;
}
```

Porém, *```unique_ptr``` não suporta operação de cópia* de variável porque o
acesso é modo exclusivo, ou seja, único dono.  C++11 proporciona o
```operador move``` que move o conteúdo ao invés de copiar:
```C++
auto ptr1 = std::unique_ptr<int> {new int};         // aloca ponteiro int
auto copia = std::move(ptr1);                       // move para copia
std::cout << "Ptr1: " << ptr1.get() << std::endl;   // saída: 0x0 (nullptr)
std::cout << "Copia: " << copia.get() << std::endl; // saída: endereço do ponteiro alocado
```

### Mover ao invés de copiar

Como dito anteriormente, C++11 proporciona o *operador move* que move o
conteúdo ao invés de copiar e deixa a estrutura antiga (*objeto*) vazio.
Este exemplo mostra como funciona ao mover uma ```string``` usando
```std::move```:
```C++
std::string str1 {"Texto"};                    // cria string
std::string copia = std::move(str1);           // move para copia
std::cout << "String 1: " << str1 << std::endl; // saida vazia
std::cout << "Copia: " << copia << std::endl;   // saida: "Texto"
```

## Templates
As templates C++ possibilitam programação genérica usando tipos como
parâmetros.  Elas basicamente descrevem como construir um conjunto de
funções ou estruturas que comportam-se da mesma forma.  Será uma das
formas usadas aqui para construir TADs (*tipos abstratos de dados*).

Considere uma função que retorna o elemento maior entre ```x``` e ```y```, podemos descrever com templates:
```C++
template<typename T>
void max(T x, T y)
{
    return (x > y) ? x : y;
}

// usando a função
valor = max<int>( 2, 3 );
```
```template<typename T>``` denota que uma template é declarada e que o
argumento de tipo ```T``` será usado.  O tipo ```T``` é valido dentro do bloco da
função, ou estrutura.  Então, toda vez que nos referimos a ```T```, ele é
substituido pelo tipo usado.

No caso de uma estrutura com template:
```C++
template<typename T>
struct Ponto {
    T x;
    T y;
};

// criando um ponto
Ponto<float> p1;  // ponto com float
Ponto<int>   p2; // ponto com int
```
descreve uma estrutura ```Ponto``` que tem `x` e `y` com tipo definido pelo
usuário.  Note que declaramos duas variáveis com tipos diferentes: ```int```
e ```float```.  O compilador irá gerar a estrutura com ambos os tipos usados
como parâmetro.

Dicas sobre templates: https://isocpp.org/wiki/faq/templates

## Números aleatórios
```C++
#include <iostream>
#include <random>
#include <functional>
#include <chrono>

int main(void)
{
    // a semente é o tempo desde 1/1/1970
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    // gerador de números
    std::default_random_engine generator(seed);
    
    // numeros aleatórios de 0 até 100
    auto rand = std::bind(std::uniform_int_distribution<int>{0,100}, generator);
    for(auto i= 0; i < 10; i++){
        std::cout << rand() << std::endl;
    }
    return 0;
}
```

## Tempo
```C++
#include <iostream>
#include <vector>
#include <chrono>

// elimina uso do std:: no programa
using namespace std;

int main(void)
{
  auto inicio = chrono::system_clock::now();
  vector<int> vetor(10000);
  for(auto& i : vetor) i = 33;
  auto fim = chrono::system_clock::now();
  
  // tempo em microsegundos 
  auto tempo = chrono::duration_cast<chrono::microseconds>(fim-inicio).count();
  cout << "Tempo (us): " << std::fixed << tempo << endl;
  return 0;
}
```
## Namespaces
Namespaces em C++ criam *escopos nomeados* e aumenta a modularidade do
código.  A ```std``` é o namespace padrão do C++.

No exemplo abaixo, definimos um namespace com uma função e uso:
```C++
namespace Uteis {
    void foo(void) {
        std::cout << "Funcao foo aqui" << std::endl;
    }
}

// usando a função assim
Uteis::foo();
```
## Funções lambda

TODO

## Standard Template Library (STL)
### Lista
A ```std::list``` é uma lista que suporta inserção e remoção de elementos de
qualquer lugar em tempo constante.
```C++
#include <iostream>
#include <list>
#include <random>
#include <functional>

int main(void)
{
    // Ver: http://en.cppreference.com/w/cpp/container/list
    std::list<int> lista;

    // cria um functor rand() que gera números aleatórios de 0 a 100
    auto seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    auto rand = std::bind(std::uniform_int_distribution<int>{0,100}, generator);
    
    // insere 20 elementos aleatórios
    for(auto i= 0; i < 20; i++)
        lista.push_back(rand());

    auto primeiro = begin(lista); // iterador C++
    auto ultimo = end(lista); // iterador C++
    std::cout << "Primeiro elemento: " << *primeiro << std::endl;
    std::cout << "Ultimo elemento: " << *ultimo << std::endl;

    // laço do C++ para containers
    for(auto& v: lista){
        // cada 'v' é um int&: uma referência
        std::cout << v << std::endl;
    }

    // limpa a lista
    lista.clear();

    return 0;
}
```
## Links úteis
- Referência para C++/C http://pt.cppreference.com
- Dicas importantes de C https://matt.sh/howto-c
- Formatar código com clang-format http://clang.llvm.org/docs/ClangFormat.html
- Dicas de formatação http://llvm.org/docs/CodingStandards.html
- Sobre C++11 http://herbsutter.com/elements-of-modern-c-style/

