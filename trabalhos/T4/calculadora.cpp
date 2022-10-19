

#include <stack>
#include <iostream>

#define CATCH_CONFIG_MAIN // O Catch fornece uma main()
#include "catch.hpp"


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

// erro porque as pilhas estao vazias
TEST_CASE("Teste vazio") {
    Calculadora<int> c;
    c.cria();
    REQUIRE(c.fim() == false);
}


// apenas um numero, entao OK
TEST_CASE("Casos simples") {
    Calculadora<int> c;
    c.cria();
    c.operando(1);
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 1);
}

// dois numeros sem operador e um erro
TEST_CASE("1 2") {
    Calculadora<int> c;
    c.cria();
    c.operando(1);
    c.operando(2);
    REQUIRE(c.fim() == false);
}

// falta um numero nesse calculo
TEST_CASE("1+ = erro") {
    Calculadora<int> c;
    c.cria();
    c.operando(1);
    c.operador('+');
    REQUIRE(c.fim() == false);
}

// erro de formula
TEST_CASE("3* = erro") {
    Calculadora<int> c;
    c.cria();
    c.formula("3*");
    REQUIRE(c.fim() == false);
}

// soma simples
TEST_CASE("3+2+9 = 14") {
    Calculadora<int> c;
    c.cria();
    c.formula("3+2+9");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 14);
}

// soma com negativos
TEST_CASE("-1+3-5 = -3") {
    Calculadora<int> c;
    c.cria();
    c.formula("-1+3-5");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == -3);
}

// soma com negativos
TEST_CASE("30-15+8 = 23") {
    Calculadora<int> c;
    c.cria();
    c.formula("30-15+8");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 23);
}

// multiplicacao
TEST_CASE("3*8+7 = 31") {
    Calculadora<int> c;
    c.cria();
    c.formula("3*8+7");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 31);
}

// divisao e multiplicacao
TEST_CASE("3*7+4/3 = 22") {
    Calculadora<int> c;
    c.cria();
    c.formula("3*7+4/3");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 22);
}

// parentesis
TEST_CASE("(3+4)*2+7 = 21") {
    Calculadora<int> c;
    c.cria();
    c.formula("(3+4)*2+7");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 21);
}

// parentesis
TEST_CASE("3+4*(9+3) = 51") {
    Calculadora<int> c;
    c.cria();
    c.formula("3+4*(9+3)");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 51);
}

// parentesis
TEST_CASE("(3+1)*(4+7)+3-1 = 46") {
    Calculadora<int> c;
    c.cria();
    c.formula("(3+1)*(4+7)+3-1");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 46);
}

// parentesis errado
TEST_CASE("4+(1+2 = erro") {
    Calculadora<int> c;
    c.cria();
    c.formula("4+(1+2");
    REQUIRE(c.fim() == false);
}

// parentesis errado
TEST_CASE("4+(1+2)+1) = erro") {
    Calculadora<int> c;
    c.cria();
    c.formula("4+(1+2)+1)");
    REQUIRE(c.fim() == false);
}

TEST_CASE("7/4+1 = 2") {
    Calculadora<int> c;
    c.cria();
    c.formula("7/4+1");
    REQUIRE(c.fim() == true);
    REQUIRE(c.resultado() == 2);
}
