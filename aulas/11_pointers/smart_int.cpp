
#include <iostream>
#include <list>
#include <memory>
#include <cstring>

int main(void)
{
    int entrada;
    std::list< std::unique_ptr<int> > numeros;

    while( std::cin >> entrada ){
        
        std::unique_ptr<int> ptr_numero( new int );
        *ptr_numero = entrada;
        numeros.push_back(  std::move( ptr_numero ) );
    }

    return 0;
}
