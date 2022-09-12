#  Algoritmos e Containers C++ STL

A C++ STL (Standard Template Library) consiste em iteradores, containers (ou TADs), algoritmos, e funções parte da bibliteca padrão do C++.

##  Containers

Containers são TADs que armazenam uma sequencia de objetos que podem ser classificados em:
- **Sequenciais** como vetores e listas
- **Associativos** como mapas e conjuntos
- **Adaptadores** com acesso especializado como pilha
- **Quase containers** que não tem todas as funcionalidades como `string`

|   | Containers Sequenciais |
|---:|------------------|
| `vector<T>`       |  Vetor de elementos `T` |
| `list<T>`         | Lista duplamente encadeada de elementos `T` |
| `forward_list<T>` | Lista encadeada de `T` |
|   | **Containers Associativos Ordenados** |
| `map<K,V>`      |  Mapa ordenado de chaves `K` para `V` |
| `multimap<K,V>` | Mapa ordenado de chaves `K` para `V`, permite chaves duplicadas |
| `set<K>`        | Conjunto ordenado de chaves `K` |
| `multiset<K>`   | Conjunto ordenado de chaves `K`, permite chaves duplicadas |
|   | **Containers Adaptadores** |
| `priority_queue<T>` |  Fila de prioridade de `T` |
| `queue<T>`          | Fila de `T` com `push()` e `pop()` |
| `stack<T>`          | Pilha de `T` com `push()` e `pop()` |


Os containers também possuem métodos semelhantes para tamanho:
|   | Métodos de tamanho e capacidade |
|---:|------------------|
| `x=c.size()` | `x` seria o número de elementos |
| `c.empty()`  | testa se está vazio |
| `x=c.max_size()` | `x` é capacidade máxima possível de `c` |
| `x=c.capacity()` | `x` é o espaço alocado  de `c` |
| `c.reserve(n)` | Reserva espaço para `n` elementos |
| `c.resize(n)` | Muda de tamanho de `c` para `n` |
| `c.shrink_to_fit()` | Faz `c.capacity()` ficar igual a `c.size()` |
| `c.clear()` | Remove todos os elementos de `c` |

E métodos comuns para acesso:
|   | Métodos de acesso |
|---:|------------------|
| `c.front()` |  O primeiro elemento de `c` |
| `c.back()` | O último elemento de `c` |
| `c[i]` | Acessa o elemento `i` de `c` |
| `c.at(i)` | Acessa o elemento `i` de `c`, causa `out_of_range` se não existe |
| `c[k]` | Acessa o elemento `k` de `c` em mapas |
| `c.at(k)` | Acessa o elemento `k` de `c` em mapas, causa `out_of_range` se não existe |

## Algoritmos STL

Há em torno de 80 métodos definidos em `<algorithm>` que podem alterar ou não o conteúdo de containers. Muitos algoritmos podem ser implementados usando métodos genéricos da STL ao invés de códigos próprios. A STL implementa algoritmos testados e eficientes exaustivamente em um amplo leque de estruturas de dados. Alguns usuários de C++ argumentam que até laços devem ser evitados pois iremos encontrar métodos equivalentes dentro da STL.


### Sem alteração do container

Um dos algoritmos mais simples é o `for_each` que aplica uma operação em cada elemento como incrementar todos os elementos de `v`:
```C++
std::for_each( v.begin(), v.end(), [](int& x){ ++x; } );
```

As funções de predicado testam uma condição dentro de uma sequencia:
|   | Predicados |
|---:|------------------|
| `all_of(b,e,f)` |  `f(x)` é verdadeiro para todos `x` em `[b:e)`? |
| `any_of(b,e,f)` |  `f(x)` é verdadeiro para qualquer `x` em `[b:e)`? |
| `none_of(b,e,f)` |  `f(x)` é falso para todos `x` em `[b:e)`? |

Podemos testar se todos os elementos de `v` são maiores que zero como abaixo:
```C++
assert( std::all_of(v.begin(), v.end(), [](double x){return x>0;}) );
```

As funções para contar ocorrências são:
|   | Funções `count()` |
|---:|------------------|
| `x=count(b,e,v)` |  `x` conta ocorrências de `v` em `[b:e)` |
| `x=count_if(b,e,f)` | `x` conta ocorrências de `v` em `[b:e)` tal que `f(*p)` |

Podemos contar o número de espaços ou *whitespaces* (qualquer coisa em branco) com `isspace`:
```C++
auto n_space = count(s.begin(), s.end(), ' ');
auto n_whitespace = count_if(s.begin(), s.end(), isspace);
```

A familia de algoritmos `find()` faz busca linear de elementos ou aplica um predicado:
|   | Algoritmos `find()` |
|---:|------------------|
| `p=find(b,e,v)` |  `p` aponta para o primeiro elemento em `[b:e)` onde `*p==v` |
| `p=find_if(b,e,f)` |  `p` aponta para o primeiro elemento em `[b:e)` onde `f(*p)` |
| `p=find_if_not(b,e,f)` |  `p` aponta para o primeiro elemento em `[b:e)` onde `!f(*p)` |
| `p=find_first_of(b,e,b2,e2)` |  `p` aponta para o primeiro elemento em `[b:e)` onde `*p==*q` para algum `q` em `[b2:e2)` |
| `p=find_first_of(b,e,b2,e2,f)` |  `p` aponta para o primeiro elemento em `[b:e)` onde `f(*p,*q)` para algum `q` em `[b2:e2)` |
| `p=adjacent_find(b,e)` |  `p` aponta para o primeiro elemento em `[b:e)` onde `*p==*(p+1)` |
| `p=adjacent_find(b,e,f)` |  `p` aponta para o primeiro elemento em `[b:e)` onde `f(*p,*(p+1))` |
| `p=find_end(b,e,b2,e2)` |  `p` aponta para o último elemento em `[b:e)` onde `*p==*q` para algum `q` em `[b2:e2)` |
| `p=find_end(b,e,b2,e2,f)` |  `p` aponta para o último elemento em `[b:e)` onde `f(*p,*q)` para algum `q` em `[b2:e2)` |

As funções `equal()` comparam pares:
|   | Algoritmos `equal()` |
|---:|------------------|
| `equal(b,e,b2)` | `v==v2` para todos `[b:e)` e `[b2:b2+(e-b))`? |
| `equal(b,e,b2,f)` | `f(v,v2)` para todos `[b:e)` e `[b2:b2+(e-b))`? |

Os métodos `search()` procura ocorrências de elementos de uma sequencia em outra:
|   | Algoritmos `search()` |
|---:|------------------|
| `p=search(b,e,b2,e2)` | `p` aponta para o primeiro `*p` em `[b:e)` onde `[p:p+(e2-b2))`  iguala `[b2,e2)` |
| `p=search(b,e,b2,e2,f)` | `p` aponta para o primeiro `*p` em `[b:e)` onde `[p:p+(e2-b2))`  iguala `[b2,e2)` usando `f` |
| `p=search_n(b,e,n,v)` | `p` aponta para o primeiro `*p` em `[b:e)` onde cada `[p:p+n)` é `v` |
| `p=search_n(b,e,n,v,f)` | `p` aponta para o primeiro `*p` em `[b:e)` onde cada `*q` em `[p:p+n)` tem `f(*p,v)` |

### Algoritmos de alteração de containers

O mais básico método é o `transform()` que aplica uma função em uma sequencia.
|   | Algoritmos `transform()` |
|---:|------------------|
| `p=transform(b,e,out,f)` | Aplica `*q=f(*p1)` para todo `*p1` em `[b:e)` escrevendo para `*q` em `[out:out+(e-b))`; `p=out+(e-b)` |
 | `p=transform(b,e,b2,out,f)` | Aplica `*q=f(*p1,*p2)` para todo `*p1` em `[b:e)` e `*p2` em `[b2:b2+(e-b))` correspondente, escrevendo para `*q` em `[out:out+(e-b))`;`p=out+(e-b)` |

Também podemos copiar sequências com `copy()`:
|   | Algoritmos `copy()` |
|---:|------------------|
| `p=copy(b,e,out)` | Copia todos os elementos em `[b:e)` para `[out,p)` sendo `p=out+(e-b)` |
| `p=copy_if(b,e,out,f)` | Copia todos os elementos em `[b:e)` para `[out,p)` dado que `f(x)` |
| `p=copy_n(b,n,out)` | Copia os primeiros `n` elementos em `[b:b+n)` para `[out,p)` sendo `p=out+n` |
| `p=copy_backward(b,e,out)` | Copia todos os elementos em `[b:e)` para `[out,p)` començando pelo último elemento; `p=out+(e-b)` |
| `p=move(b,e,out)` | Move todos os elementos em `[b:e)` para `[out,p)` sendo `p=out+(e-b)` |
| `p=move_backward(b,e,out)` | Move todos os elementos em `[b:e)` para `[out,p)` començando pelo último elemento; `p=out+(e-b)` |


Os métodos `unique()` removem elementos duplicados adjacentes. 
O `unique` não remove duplicados mas sim move elementos repetidos para o fim da sequencia além de `p` retornado. 
|   | Algoritmos `unique()` |
|---:|------------------|
| `p=unique(b,e)` | Move elementos em `[b:e)` tal que `[b:p)` não tem adjacentes duplicados |
| `p=unique_copy(b,e,out)` | Copia `[b:e)` para `[out:p)`, não copia adjacentes duplicados |
| `p=unique_copy(b,e,out,f)` | |
Um algoritmo para remover duplicados pode ser:
```C++
sort(c.begin(), c.end());
auto p = unique(c.begin(), c.end());
c.erase(p, c.end());
```

Os métodos `remove()` removem elementos de acordo com o critério. Os elementos removidos são na verdade movido ao final para posterior remoção como em `unique()`:
|   | Algoritmos `remove()` |
|---:|------------------|
| `p=remove(b,e,v)` | Remove (move p/ o fim) elementos com valor `v` tal que `[b:p)` são `!(*q==v)`  | 
| `p=remove_copy(b,e,out,v)` | Copia elementos de `[b:e)` tal que `!(*q==v)` para `[out,p)` | 

Na tabela abaixo temos outros algoritmos para inversão, substituição, rotação, e particionamento de sequencias.
|   | Algoritmos de alterações diversos |
|---:|------------------|
| `reverse(b,e)` | Inverte a ordem dos elementos | 
| `p=reverse_copy(b,e,out)` | Copia `[b:e)` para `[out,p)` em ordem reversa | 
| `p=replace(b,e,v,v2)` | Substitui elementos de `[b:e)` com valor `v` por `v2` |
| `p=replace_copy(b,e,out,v,v2)` | Copia `[b:e)` para `[out,p)`, e substitui valores `v` por `v2` |
| `p=rotate(b,m,e)` | move os elementos a esquerda, trata `[b:e)` como um círculo |
| `p=rotate_copy(b,m,e,out)` | Copia `[b:e)` para `[out:p)` rotacionado |
| `random_shuffle(b,e)` | Embaralha `[b:e)` como gerador aleatório padrão |
| `p=partition(b,e,f)` | Separa elementos  entre `[b:p)` e `[p:e)` dado por `f(*p1)` |
| `p=partition_point(b,e,f)` | Para `[b:e)` `p` é o ponto que `all_of(b,p,f)` e `none_of(p,e,f)` |

Por fim, temos métodos para preechimento de sequencias por valor ou função:
|   | Algoritmos `fill()`  e `generate()` |
|---:|------------------|
| `fill(b,e,v)` | Atribui `v` para cada elemento de `[b:e)` | 
| `p=fill_n(b,n,v)` | Atribui `v` para cada elemento de `[b:b+n)`, `p=b+n` | 
| `p=generate(b,e,f)` | Atribui `f()` para cada `[b:e)` | 
| `p=generate_n(b,n,f)` | Atribui `f()` para cada elemento de `[b:b+n)`, `p=b+n` | 

### Ordenação

Os algoritmos de ordenação são uns dos mais básicos da Computação e usados em muitos aplicativos. Abaixo temos os métodos básicos da STL para ordenação:
|   | Algoritmos `sort()` |
|---:|------------------|
| `sort(b,e)` | Ordena `[b:e)` | 
| `sort(b,e,f)` | Ordena `[b:e)` usando `f(*p,*q)` | 
| `stable_sort(b,e)` | Ordena `[b:e)` e mantem a ordem de elementos iguais | 
| `partial_sort(b,m,e)` | Ordena parte de `[b:e)` e ordena`[b:m)` | 
| `p=partial_sort_copy(b,e,b2,e2)` | Ordena parte de `[b:e)`  | 

# Algoritmos sem laço?

Lembram do exemplo de abrir um arquivo e imprimir números ? Podemos fazer tal programa sem laços usando algoritmos e iteradores C++ para entrada e saída como no exemplo abaixo:
```C++
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
```
O `istream_iterator` é um tipo de iterador chamado *stream iterator* que permite ler ou escrever de uma entrada ou saída. Nesse exemplo, cada elemento é lido como se fosse um operador de leitura `>>` para o tipo `int`. No caso do `ostream_iterator`, ele escreve cada elemento (`<<`) com tipo `int` e separador `\n`.


Um outro exemplo é ler palavras de um arquivo texto, inserir em um vetor, e contar o número de caracteres de cada palavra.
```C++
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
```
Nesse exemplo, usei um iterador de inserção cujo objetivo é permitir inserir novos elementos em um container por meio de um iterador. Os tipos de iteradores são:
|   | Iteradores de inserção |
|---:|------------------|
| `insert_iterator(c,p)` | cria um `insert_iterator` que aponta para a posição `p` | 
| `back_inserter(c)` | cria um `back_insert_iterator` que aponta para `back()` de `c` | 
| `front_inserter(c)` | cria um `front_insert_iterator` que aponta para `front()` de `c`|

Outro de iterador é o reverso acessível por `c.rbegin()` e `c.rend()`.

Obviamente, os exemplo podem ser melhorados com selecionar números positivos, ordenação, etc.

# Links
- https://sean-parent.stlab.cc/papers-and-presentations/
- https://en.cppreference.com/w/