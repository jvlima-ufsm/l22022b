# Listas em C++

`std::list` é um container C++ da STL do tipo lista duplamente encadeada otimizada para inserções e remoções. Uma alternativa deste tipo de lista é o `std::forward_list` sendo uma lista encadeada simples.

Os métodos e atributos de uma `list` podem ser vistos em: http://www.cplusplus.com/reference/list/list/

## Criando listas

As listas C++ são templates aceitando qualquer tipo como no examplo abaixo de uma lista vazia:

```C++
#include <iostream>
#include <list>

int main(void)
{
  std::list<int> lista {2,3,4};
 
  lista.push_back(10);  // insere no fim
  lista.push_front(0);  // insere no começo
 
  for(auto it = begin(lista); it != end(lista); it++)
    std::cout << *it << ' ';

  std::cout << std::endl;
 
  return 0;
}
```

```
$ g++ -Wall -g  lista1.cpp
$ ./a.out
0 2 3 4 10    
```
Comentários do código:
- notem que `push_back` e `push_front` inserem na lista
- usamos inicialização padrão `{}`
- usamos **iteradores C++** que são "ponteiros" em containers C++ a fim de navegar ou manipular uma estrutura. 

**IMPORTANTE**: o `end()` da lista (e outros) passa do fim da lista! Portanto, se tentar acessar o elemento `lista.end()` o programa terá falha de segmentação pois esta posição não existe em memória.

## Inserção

A inserção pode ser feita com `push_back` ou `push_front`, ou com a posição dada por um iterador.

```C++
#include <iostream>
#include <list>

int main(void)
{
  std::list<int> lista {2,3,4};
 
  lista.insert( end(lista), 10);   // insere no fim
  lista.insert( begin(lista), 0);  // insere no começo
  lista.insert( ++begin(lista), 1); // insere depois do 1o elemento da lista
 
  for(auto it = begin(lista); it != end(lista); it++)
    std::cout << *it << ' ';

  std::cout << std::endl;
  return 0;
}
```

```
g++ -Wall -g  lista2.cpp
./a.out
0 1 2 3 4 10
```

## Remoção

A remoção por valores pode ser feita com `remove` ou `remove_if`.
```C++
#include <iostream>
#include <list>

bool removeNegativos(const int& v)
{
    return (v < 0);
}


int main(void)
{
  std::list<int> lista {0,1,2,3,-5,4,-1,2};
 
  lista.remove( 2 );   // remove todos os elementos igual a 2
  lista.remove_if( removeNegativos );  // aplica uma função que decide quem remover
 
  for(auto it = begin(lista); it != end(lista); it++)
    std::cout << *it << ' ';
  std::cout << std::endl;
 
  return 0;
}
```
```
$ g++ -Wall -g  lista1.cpp
$ ./a.out
0 1 3 4 
```

Outras funções disponíveis:
- `unique()` remove elementos duplicados da lista.
- `pop_front()` remove o primeiro elemento.
- `pop_back()` remove o último elemento

## Ordenação

Podemos ordenar elementos de uma lista com `sort()` ou inverter a ordem com `reverse()`.

Lembrando que as funções funcionam com **tipos fundamentais**, ou seja, tipo primários do C++ (`int`, `char`, `double`, `bool`, `string`, etc). As comparações com `struct` ou tipo derivados depende da implementação de operadores (https://en.cppreference.com/w/cpp/language/operators).

## Tamanho  e capacidade

Uma lista encadeada pode ter tamanho praticamente ilimitado. As funções disponíveis são:
- `empty()` verifica se a lista está vazia
- `size()` retorna o tamanho da lista
- `max_size()` retorno o potencial máximo de capacidade que esta lista pode ter.
- `clear()` limpa a lista
