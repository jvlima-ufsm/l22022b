
#include <iostream>

template<typename T>
struct Arvore {
    T dado;
    Arvore<T>* esq;
    Arvore<T>* dir;

    // inicia o no da arvore com valores nulos
    void inicia(T v)
    {
        dado = v;
        esq = nullptr;
        dir = nullptr;
    }

    // insere um no pre-alocado na arvore
    void insere( Arvore<T>* no )
    {
        // o novo valor e menor que o meu?
        if( no->dado < dado )
            if( esq == nullptr )
                esq = no;
            else 
                esq->insere( no );
        else // o novo valor e maior ou igual
            if( dir == nullptr )
                dir = no;
            else
                dir->insere( no );
    }

    // faz o percurso pre-ordem.
    // A visita e imprimir o valor de cada no
    void emOrdem(void)
    {
        // primeiro esquerda
        if( esq != nullptr )
            esq->emOrdem();
        // assumindo que podemos imprimir o dado
        std::cout << dado << " ";
        // depois direita 
        if( dir != nullptr )
            dir->emOrdem();
    }   

    // Libera a memoria de cada no filho 
    // Idealmente, nao poderia liberar a memoria porque nao foi esta struct
    // que alocou. Mas vamos liberar por praticidade.
    void destroi(void)
    {
        if( esq != nullptr ){
            esq->destroi();
            delete esq;
        }
        if( dir != nullptr ){
            dir->destroi();
            delete dir;
        }
    }
};

int main(void)
{
    Arvore<int> raiz;
    Arvore<int>* no;

    raiz.inicia(5);
    // no da direita
    no = new Arvore<int>;
    no->inicia(10);
    raiz.insere( no );
    // no da esquerda
    no = new Arvore<int>;
    no->inicia(2);
    raiz.insere( no );
    
    raiz.emOrdem();
    std::cout << "FIM\n";

    raiz.destroi();
    return 0;
}