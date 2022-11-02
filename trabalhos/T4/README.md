
# T4 - Planilha com Calculadora 

## Deadline

Prazo: *04/11/2022 (Qua)** pelo link do GitHub (https://classroom.github.com/a/BFTVPcUv).

Você deve escolher seu nome na lista de alunos. Em seguida, o GitHub irá criar um repositório deste trabalho em seu usuário.

## Descrição

Este trabalho consiste na implementação de uma **planilha** de números inteiros.
Esta planilha deve suportar referências a outras células e operações aritméticas. Uma célula pode ter um valor `int` ou uma fórmula matemática iniciando com `=`. As células devem ser nomeadas em linhas (1 até 60) e colunas (A até Z). As operações aritméticas devem ser em `int` e devem usar uma cálculadora mais referências a outras células. Se houver algum valor na fórmula que inicia com letra, ela será uma referência a outra célula. A planilha tem limites de 60 linhas (1-60) e 24 colunas (A-Z).

Note que a função que calcula o valor de uma célula deve ser recursiva. Ou seja, quando encontrar uma referência a outra célula, chama ela mesma para calcular o valor daquela célula. Faça um mecanismo que evite recursividade infinita em seu programa.

A planilha deve ter uma estrutura chamada `Planilha` que vai conter dados e funções da planilha. Implemente as células com uma estrutura auxiliar `Celula` contendo a fórmula e o valor atual. Note que a atualização de uma célula pode alterar o valor de outras. As células devem ser armazenadas em um `std::map` do C++ onde o índice é o nome da célula. Veja o exemplo abaixo:
```C++
#include <map>
#include <iostream>

struct Celula {
  // Seu codigo aqui
  std::string formula;
};

int main(int argc, char **argv)
{
  std::map<std::string, Celula> celulas;

  celulas["D21"] = Celula();
  celulas["D21"].formula = "=1+1";
  celulas["A1"] = Celula();
  celulas["A1"].formula = "22";


  for(auto it= celulas.begin(); it != celulas.end(); it++)
    std::cout << it->first << " " << it->second.formula << std::endl;

  return 0;
}
```

Cada expressão em uma célula será **in-fixa**. Após ler a expressão o programa deve chamar as funções de calculadora para determinar o valor.

Uma expressão aritmética in-fixa é a notação convencional, onde um operador aparece entre dois operandos. Parênteses são necessários para especificar a ordem das operações. Por exemplo:
```
((x * x) + 2)/(x + 1)
```

Por exemplo, a entrada:
```
A1 3
B1 2
C1 =A1+B1
D1 =1+C1/2
A13 =C1
```
Produz o resultado:
```
A1 3
A13 5
B1 2
C1 5
D1 4
```

A Planilha deve imprimir todas as células não vazias.

## Calculadora

A nossa calculadora deve utiliza o algoritmo de duas pilhas de Dijkstra ([Dijkstra's Two Stack Algorithm](https://algs4.cs.princeton.edu/13stacks/)).
A calculadora tem duas pilhas, uma de operadores e outra de
operandos. Um operando é sempre colocado na pilha de operandos. Um
operador, antes de ser colocado na pilha de operadores, verifica o
operador no topo e, caso o operador tenha maior precedência, opera-o
sobre os dois operandos do topo e coloca o resultado no topo da pilha
de operandos, até que a pilha esteja vazia ou que o operador do topo
seja um abre-parênteses. O fecha parênteses opera todos os operadores
do topo até encontrar um abre parênteses. O método `fim()` opera todos
os operadores até esvaziar a pilha de operadores.

As três regras básicas para resolução da calculadora são:
1. Para cada operador, 2 operandos devem existir.
2. Se encontrar `)` resolve tudo até encontrar o `(` correspondente.
3. Se o operador do topo da pilha tem maior precedência que o atual (a
   ser empilhado), resolve a pilha até não haver mais operadores com
   maior precedência.

Um exemplo da expressão `3/2+1` onde vamos arredondar divisões com a função `std::round`:
1. empilha `3`.
2. empilha `'/'`.
3. empilha `2`.
4. antes de empilha `'+ '` verifica-se que `'/'` tem precedência sobre `'+'`
   e se calcula todos os operadores da pilha `(3/2)`, sendo o resultado
   empilhado na pilha de operandos (`2`). Após, empilha `'+'`.
5. empilha `1`.
6. termina o cálculo (`2+1`).

A estrutura template de exemplo usada é essa:
```C++
template<typename T>
struct Calculadora {

    // ver http://en.cppreference.com/w/cpp/container/stack
    std::stack<T> operandos;    // números, basicamente
    std::stack<char> operadores; // operadores: +, -, /, *
    // podem incluir mais dados, se necessário

    // cria a calculadora
    void cria(void){
    }

    // destroi a calculadora, limpa as pilhas
    void destroi(void){
        while(operandos.empty() == false)
            operandos.pop();
        while(operadores.empty() == false)
            operadores.pop();
    }

    // insere um novo operando para o calculo
    void operando(T op) {
        operandos.push(op);
    }

    // insere um novo operador para o calculo (pode ser '+', '-', '*', '/', '**')
    // se for um abre parenteses '(' tudo ok. 
    // se for um fecha parenteses ')', deve-se calcular tudo dentro.
    void operador(char op){
        // verficar aqui o operador inserido
        operadores.push(op);
    }

    // recebe uma formula in-fixa como entrada e coloca nas pilhas
    void formula(std::string form){

    }

    // finaliza o calculo e verifica erros.
    // retorna false se erro detectado
    bool fim(void) {
        if(operandos.empty())
            return false;

        return true;
    }

    // retorna o resultado calculo (topo da pilha de operandos)
    // esse resultado sera parcial se ainda nao foi chamado calc_fim().
    T resultado(void) {
        if(operandos.empty())
            return static_cast<T>(0);

        return operandos.top();
    }
};
```

As funções que **devem** ser completadas são:
- `cria()` inicia a calculadora (se precisar)
- `destroi()` limpa as pilhas 
- `operando()` empilha um operando tipo `T` 
- `operador()` empilha um operador tipo `char`
- `formula()` recebe um `std::string` e empilha os operadores e operandos 
- `fim()` resolve tudo que esta nas pilhas e retorna `true` se, e somente se, restar apenas 1 operando nas pilhas ou retorna `false` caso contrário
- `resultado()` retorna o resultado calculado

## Test Driven Development (TDD)

Recomenda-se a uso do código exemplo [calculadora.cpp](calculadora.cpp) para testar e desenvolver a calculadora da planilha.

O código-exemplo da calculadora usa o conceito de TDD (*Test Driven Development*) com o framework C++ [Catch2](https://github.com/catchorg/Catch2/tree/v2.x).
O framework Catch2 consegue ser utilizado apenas com o arquivo header `catch.hpp` sem necessidade de instalação.

Todos os testes estão prontos no arquivo `calculadora.cpp`. A compilação e teste pode ser feita com os comandos:
```
$ g++ -Wall -std=c++11 -o calc calculadora.cpp 
```

Comentários sobre o exemplo:
- A execução irá mostrar o relatório de testes efetuados.
- Note que o programa não tem uma função `main()` porque não precisa! O Catch2 faz isso para nós.

## Regras
- Crie uma estrutura chamada `Planilha` para este trabalho, e uma função `main` simples como dados em exemplos anteriores.
- A planilha deve imprimir todas as células da planilha não vazias.
- Números de divisão inteiros devem ser arredondados com `std::round`.
- Usar somente C++!
- Use `std::stack` ou `std::vector`
- Não compila, zero.
- Plágio, zero.