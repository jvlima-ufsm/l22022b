
# T5 - Árvore Binária de Busca

## Deadline

Prazo: **21/11/2022 (Seg)** pelo link do GitHub (https://classroom.github.com/a/cD-A1zfR).

Você deve escolher seu nome na lista de alunos. Em seguida, o GitHub irá criar um repositório deste trabalho em seu usuário.

## Descrição

Uma árvore binária de busca (ABB) satisfas as propriedades abaixo:
- A sub-árvore da esquerda possui apenas nós menores do que o nó raiz
- A sub-árvore da direita possui apenas nós maiores do que o nó raiz
- As sub-árvores da esquerda e direita também devem ser árvores ABB (definição recursiva)

Podemos percorrer uma ABB de três formas: pré-ordem, em-ordem, e pós-ordem.
- **Percurso Pré-ordem** - visitar a raiz, percorrer a sua sub-árvore esquerda em pré-ordem, e percorrer a sua sub-árvore direita em pré-ordem.
- **Percurso Em-ordem** - percorrer a sua sub-árvore esquerda em em-ordem, visitar a raiz, percorrer a sua sub-árvore direita em em-ordem.
- **Percurso Pós-ordem** -  percorrer sua sub-árvore esquerda em pós-ordem, percorrer sua sub-árvore direita em pós-ordem, visitar a raiz.

**Objetivo** - Dado um conjunto de números de uma ABB em percurso pré-ordem, o objetivo deste trabalho é encontrar o percurso pós-ordem da ABB.

## Test Driven Development (TDD)

O código-exemplo do trabalho (https://github.com/jvlima-ufsm/tdd-abb) usa o conceito de TDD (*Test Driven Development*) com o framework C++ [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).
O framework Catch2 consegue ser utilizado apenas com o arquivo header `catch.hpp` sem necessidade de instalação.

**NÃO MODIFIQUE OS TESTES**, todos os testes estão prontos no arquivo `arvore.cpp`. A compilação e teste pode ser feita com os comandos:
```
$ g++ -Wall -std=c++11 -o calc arvore.cpp 
```

A struct de árvore `Arvore` deve ser completada. Note que a struct é um `template` podendo ser números, letras, ou qualquer outro tipo com suporte a comparação. Algumas funções já foram descritas para uso nos testes mas cada um podem (deve) adicionar mais funções a esta struct. As funções descritas são:
- `inicia()` recebe uma lista de itens em pré-ordem para criar a árvore ABB.
- `vazio()` testa se a árvore está vazia.
- `posOrdem()` recebe uma lista vazia onde irá inserir os itens da árvore ABB em pós-ordem.
- `destroi()` deve liberar a memória utilizada pela ABB.


Comentários sobre o exemplo:
- A execução irá mostrar o relatório de testes efetuados.
- Note que o programa não tem uma função `main()` porque não precisa! O Catch2 faz isso para nós.
- **Não copie o repositório!** Na hora de criar o seu repostório de entrega, os arquivos estarão disponíveis.

## Dicas
- As entradas estão em pré-ordem! Cuidado para não confundir.

## Regras
- Usar somente C++!
- Não modifique os testes, apenas complete o código da calculadora e tudo será **Success**
- Não compila, zero.
- Plágio, zero.