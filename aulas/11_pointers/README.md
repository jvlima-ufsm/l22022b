# Smart pointers em C++

*Smart pointers* são objetos que tem comportamento de pointeiros mas também gerenciam pointeiros criados. Eles funcionam como capas para os ponteiros "crus" . Smart pointers liberam o ponteiro gerenciado em dois casos:
- destruido, ou sai de escopo
- outro ponteiro é atribuido ao smart pointer com `reset()` ou atribuição do operador `=`

Há basicamente 3 tipos de smart pointers:
- `unique_ptr` onde o ponteiro tem propriedade exclusiva, ou seja, não é compartilhado com outros objetivos ou outros smart pointers
- `shared_ptr` o ponteiro é compartilhado em outro lugares do código. Para tanto, ele usa contadores de referência para saber quantos smart pointers apontam para o mesmo ponteiro. Não estudaremos ele.
- `weak_ptr` quando o ponteiro compartilhado pode "sumir". Não estudaremos ele.

## Lista de ponteiros

Veja o exemplo abaixo onde cada número lido da entrada padrão (`std::cin`) é inserido em uma lista como um ponteiro:

```C++
#include <iostream>
#include <list>
#include <memory>
#include <cstring>

int main(void)
{
    int entrada;
    std::list< std::unique_ptr<int> > numeros;

    while( std::cin >> entrada ){
        
        std::unique_ptr<int> ptr_numero( new int );
        *ptr_numero = entrada;
        numeros.push_back(  std::move( ptr_numero ) );
    }

    return 0;
}
```

O tipo do smart pointer será `std::unique_ptr<int>`, ou seja, um smart pointer de ponteiros `int*`. Note como o ponteiro é alocado:
```C++
std::unique_ptr<int> ptr_numero( new int );
```
Outra forma seria por atribuição:
```C++
std::unique_ptr<int> ptr_numero = new int;
```
Referencias ao valor do smart pointer podem ser feitas usando `*` assim como em ponteiros "crus". Se você deseja acessar o valor de endereço do ponteiro use a função `get()`.

Por fim o smart pointer é inserido na lista. Note que usou-se `std::move` que move o conteúdo de um objeto ao outro para evitar cópia. Podemos usar `std::move` para mover o conteúdo de um vetor para outro, por exemplo. Neste exemplo de smart pointer, movemos a propriedade do ponteiro de `ptr_numero` ao elemento dentro da lista. Caso contrário, seria feito uma cópia do smart pointer na inserção.


## Lista de vetores 

Como seria o uso de um smart pointer para vetores?

Devemos especificar no tipo que ele se trata de um array como no exemplo abaixo. Dessa forma, podemos fazer referencias a posições do vetor com operador `[]`:
```C++
std::unique_ptr<int[]> ptr_numero( new int[] );
```

O exemplo abaixo usamos smart pointers do tipo `char[]` para inserir palavras em uma lista. 
```C++
#include <iostream>
#include <list>
#include <memory>
#include <cstring>

int main(void)
{
    std::string entrada;
    std::list< std::unique_ptr<char[]> > linhas;

    while( std::cin >> entrada ){
        if( entrada.size() > 0 ) {
            std::unique_ptr<char[]> ptr_linha( new char[ entrada.size() + 1 ] );

            strncpy( ptr_linha.get(), entrada.c_str(), entrada.size() );
            ptr_linha[entrada.size()] = '\0';
            
            linhas.push_back(  std::move( ptr_linha ) );
        }
    }

    return 0;
}
```

## Outras funcionalidades

Funções auxiliares de smart pointers são:
- `get()` retorna o valor (endereço) do pointeiro 
- `reset()` muda o conteúdo do smart pointer para um novo ponteiro. O ponteiro anterior, se presente, será liberado.
- `swap()` troca o conteúdo entre smart pointers
- `release()` retorna o ponteiro, ou `nullptr`, e deixa de gerenciar o ponteiro