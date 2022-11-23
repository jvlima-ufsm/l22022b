
# T6 - Árvore AVL

## Deadline

Prazo: **19/12/2022 (Seg)** pelo link do GitHub (https://classroom.github.com/a/tniHWUIM).

Você deve escolher seu nome na lista de alunos. Em seguida, o GitHub irá criar um repositório deste trabalho em seu usuário.

## Descrição

Uma árvore binária é denominada **AVL** (dos seus criadores Georgy
Adelson-Velsky e Landis) se para todos os nós, **as alturas de suas duas
sub-árvores diferem no máximo em uma unidade**, sendo assim balanceada.
Operações de consulta, inserção e remoção de nós tem custo $O(\log n)$.


**Objetivo** - Dado um conjunto de números para inserção em uma ABB AVL, complete as funções do trabalho para verificação com TDD.

## Test Driven Development (TDD)

O código-exemplo do trabalho (https://github.com/jvlima-ufsm/tdd-avl) usa o conceito de TDD (*Test Driven Development*) com o framework C++ [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).
O framework Catch2 consegue ser utilizado apenas com o arquivo header `catch.hpp` sem necessidade de instalação.

**NÃO MODIFIQUE OS TESTES**, todos os testes estão prontos no arquivo `arvore.cpp`. A compilação e teste pode ser feita com os comandos:
```
$ g++ -Wall -std=c++11 arvore.cpp 
```

As funções que manipulam a struct de árvore `Abb` devem ser completadas. Note que a struct é um `template` podendo ser números, letras, ou qualquer outro tipo com suporte a comparação. Algumas funções já foram descritas para uso nos testes mas cada um podem (deve) adicionar mais funções a esta struct. As funções descritas são:
- `abb_inicia()` recebe uma lista de valores e retorna uma árvore AVL.
- `abb_insere()` insere um novo valor e retorna a raiz da AVL.
- `abb_remove()` remove o valor `v` e retorna a raiz da AVL.
- `abb_vazio()` testa se a árvore está vazia.
- `abb_preOrdem()` recebe uma lista vazia onde irá inserir os itens da árvore AVL em pré-ordem.
- `abb_esq_rotate()` efetua uma rotação à esquerda tendo `x` como pivô, retorna o nó `x`.
- `abb_dir_rotate()` efetua uma rotação à direita tendo `x` como pivô, retorna o nó `x`.
- `abb_destroi()` deve liberar a memória utilizada pela AVL.


Comentários sobre o exemplo:
- A execução irá mostrar o relatório de testes efetuados.
- Note que o programa não tem uma função `main()` porque não precisa! O Catch2 faz isso para nós.
- **Não copie o repositório!** Na hora de criar o seu repostório de entrega, os arquivos estarão disponíveis.

## Dicas
- Os testes são incrementais, ou seja, cada um deles aumenta a dificuldade.

## Regras
- Usar somente C++!
- Não modifique os testes, apenas complete o código da calculadora e tudo será **Success**
- Não compila, zero.
- Plágio, zero.