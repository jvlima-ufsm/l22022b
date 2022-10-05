
# T3 - Previdência Simplificada

## Deadline

Prazo: **12/10/2022 (Qua)** pelo link do GitHub (https://classroom.github.com/a/NeuX6G36).

Você deve escolher seu nome na lista de alunos. Em seguida, o GitHub irá criar um repositório deste trabalho em seu usuário.

## Descrição

A previdência privada é um plano de aposentadoria complementar por sistema de capitalização, ou seja, o contribuinte é o responsável por custear seu benefício. O patrimônio total será o valor acumulado por contribuições mais o rendimento dos valores investidos que pode ser resgatado ou convertido em renda.

O grande benefício da previdência privada é a vantagem fiscal, ou seja, a tributação diminui conforme o tempo de aplicação. A tabela regressiva de imposto de renda (IR) reduz a alíquota em cinco pontos a cada dois anos conforme a tabela abaixo:
|  Prazo | Alíquota de IR |
|---:|------------------:|
| Até 2 anos| 35% |
| 2 a 4 anos| 30% |
| 4 a 6 anos | 25% | 
| 6 a 8 anos | 20% | 
| 8 a 10 anos | 15% | 
| Acima de 10 anos | 10% | 

Os planos de previdência tem um ou mais fundos de investimento. Os fundos emitem cotas em cada aporte, ou seja, a fração de patrimônio investido. O número de cotas em cada aporte ou resgate depende do valor da cota na data da operação. Vale salientar o regaste sempre incide sobre as cotas mais antigas adquiridas,  ou seja, em uma política LIFO (*last in, first out*).

Sua tarefa é simular aportes e resgates em um plano de previdência simplificado. As operações descritas em uma linha contem:
- A operação sendo `A` para aporte e `R` para resgate
- O valor da operação. Um resgate total é definido por um valor negativo
- O valor da cota no momento da operação
- O ano da operação

A saída em cada operação de resgaste será:
- O valor da operação de resgate bruto (se houver) sem descontar IR
- O IR devido sobre o lucro na operação de acordo com a tabela regressiva

Por exemplo, a entrada:
```
A 1000.0 1.0 2010
R -1 1.5 2022
```
Produz o resultado:
```
1500.00 50.00
```
A aplicação de `R$ 1.000,00` valorizou `50%` e  o IR cobrado depois de 10 anos é `10%` sobre o lucro ou `R$ 50,00`.

Outro exemplo:
```
A 1000.0 1.0 2010
A 1000.0 1.0 2011
A 1000.0 1.0 2012
A 1000.0 1.0 2013
A 1000.0 1.0 2015
R 500.0 1.2 2016
R 2000.0 1.3 2018
R -1 1.9 2020
```
Saída:
```
500.00 16.67
2000.00 83.56
5785.26 546.06
```

## Dicas
- Use uma lista `std::list` para simular o comportamento de aportes em fundos.
- Crie uma `struct` para guardar informações sobre aportes como valor de cota, número de cotas, e ano do aporte.
- Faça o cálculo baseado em cotas para resgates parciais.
- Se usar [Smart pointers](../../aulas/11_pointers) deve-ser mover o ponteiro (`std::move`) para inserir e remover/consultar.
- Consulte o material sobre [Listas em C++](../../aulas/09_listas) 

## Regras

- Usar somente C++!
- Obrigatório: `std::list`
- Deve usar alocação dinâmica de memória.
- Smart pointers é permitido.
- Não compila, zero.
- Plágio, zero.