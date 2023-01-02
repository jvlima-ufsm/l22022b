
# T7 - Algoritmo de Dijkstra

## Deadline

Prazo: **25/01/2023 (Qua)** pelo link do GitHub (https://classroom.github.com/a/1Tcdo8HZ).

Você deve escolher seu nome na lista de alunos. Em seguida, o GitHub irá criar um repositório deste trabalho em seu usuário.

## Descrição

Este trabalho consiste na implementação de caminhos mínimos com o algoritmo de
Dijkstra (ver [aqui](https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/dijkstra.html) e [aqui](https://www.freecodecamp.org/news/dijkstras-shortest-path-algorithm-visual-introduction/)) em um grafo não-direcionado, com pesos nas arestas, com listas de
adjacência.
O algoritmo de Dijkstra, publicado por [Edsger W. Dijkstra](https://en.wikipedia.org/wiki/Edsger_W._Dijkstra) em 1959, gera uma árvore de caminhos mínimos de um
 vértice origem
para todos os vértices alcançáveis a partir da origem.

A execução será baseada em TDD onde é preciso completar a função `dijkstra()` a fim de que os testes terminem com sucesso. 
O programa exemplo tem funções para ler um arquivo texto que contem a descrição do grafo
(vértices e arestas com pesos) com lista de adjacência utilizando
`std::map` e `std::list` e funções para criar vértices e arestas. 

O algoritmo de Dijsktra depende do uso de uma fila de prioridade
mínima, ou *heap mínimo* (ver [aqui](https://pt.wikipedia.org/wiki/Heap) e [aqui](https://www.ime.usp.br/~pf/analise_de_algoritmos/aulas/heap.html)), que mantem o elemento de menor chave (peso) no
topo do heap.  A TAD `Heap` do exemplo implementa uma fila de prioridade
semelhante a um heap.

Uma descrição do algoritmo  de Dijkstra segue abaixo:
```
// recebe o grafo, o vertice de fonte 'fonte'
void dijkstra(Grafo G, fonte){
  inicializa todos vertices do grafo G com chave infinita
  cria heap mínimo H 
  inicia chave da fonte com valor 0
  insere todos os vértices de G no heap 
  
  while( heap H não é vazio ){
      u = retira do heap H o vértice mínimo  (ou topo)
      for( cada vértice adjacente v de u ) {
        if( é possível melhorar o caminho entre (u,v) ? (v->chave > u->chave + a->peso) ){
          v->ant = u
          Coloca u como vértice anterior a v 
          Atualiza chave de v com peso de a mais chave de u (u->chave + a->peso)
          atualiza o heap com a chave nova de v 
        }
      }
  }
}
```


## Test Driven Development (TDD)

O código-exemplo do trabalho (https://github.com/jvlima-ufsm/tdd-dijkstra) usa o conceito de TDD (*Test Driven Development*) com o framework C++ [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).
O framework Catch2 consegue ser utilizado apenas com o arquivo header `catch.hpp` sem necessidade de instalação.

Note as estruturas utilizadas no exemplo são:
- `Arestas` para aresta e peso
- `Vertice` para vertices
- `Grafo` descreve o grafo
- `Heap` é a implementação de um heap com `std::vector`

Utilizar a estrutura `Heap` é simples, para declarar um heap mínimo:
```C++
auto compara = [](Vertice* v1, Vertice* v2) {return v1->chave > v2->chave;};
Heap<Vertice*, decltype(compara)> heap(compara);
```
Note que a inserção não atualiza o heap. Um exemplo de criação do heap
é:
```C++
for(auto& i : grafo){
  heap.insere(&i.second);
 }
heap.atualiza();
```
Para acessar o elemento mínimo, use a função `heap.topo()`.

**NÃO MODIFIQUE OS TESTES**, todos os testes estão prontos no arquivo `dijkstra.cpp`. A compilação e teste pode ser feita com os comandos:
```
$ g++ -Wall -std=c++11 -o dijkstra dijkstra.cpp 
```

Comentários sobre o exemplo:
- A execução irá mostrar o relatório de testes efetuados.
- Note que o programa não tem uma função `main()` porque não precisa! O Catch2 faz isso para nós
- **Não copie o repositório!** Na hora de criar o seus repostório de entrega, os arquivos estarão disponíveis.

## Dicas
- Não esqueça de iniciar as chaves do grafo para infinito (`std::numeric_limits<float>::max()`) exceto para a fonte que deve ser zero
- Cada alteração de peso tem que atualizar o heap


## Regras
- Usar somente C++!
- Não modifique os testes, apenas complete o código da calculadora e tudo será **Success**
- Não compila, zero.
- Plágio, zero.