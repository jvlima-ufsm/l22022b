
# T1 - Triângulos

## Deadline

Prazo: **21/09/2022** pelo link do GitHub (https://classroom.github.com/a/E5iezWGx).

Você deve escolher seu nome na lista de alunos. Em seguida, o GitHub irá criar um repositório deste trabalho em seu usuário.

## Descrição

Triângulos são polígonos formados por três lados e três ângulos internos que somam 180 graus. Para formar um triângulo é preciso que cada lado seja menor que a soma dos os outros dois lados.

Os tipos de triângulos são:
- **Equilátero** - os três lados são iguais.
- **Isósceles** - pelo menos dois lados são iguais.
- **Escaleno** - os três lados são diferentes.

O objetivo deste T1 é  ler os lados de um triângulo da entrada e imprimir o tipo do triângulo ou valores inválidos. 
Cada linha contem três lados `(a,b,c)`.
O programa fará a leitura dos lados da entrada padrão (`std::cin`) como os números inteiros (`0 < n <= 50`) digitados abaixo:
```
6 8 10
3 3 3
5 3 12
40 40 50
```

Ou seja, você deve imprimir o tipo de triângulo em cada linha.
A saída do programa deve ser:
```
$ ./t1 < lados.txt
escaleno
equilatero
invalido
isosceles
```

## Dicas

- Evitar chamadas a biblioteca C como `scanf` e `printf`.

## Regras

- Usar somente C++!
- Não compila, zero.
- Plágio, zero.

