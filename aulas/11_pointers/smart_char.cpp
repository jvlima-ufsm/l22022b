
#include <iostream>
#include <list>
#include <memory>
#include <cstring>

int main(void)
{
    std::string entrada;
    std::list< std::unique_ptr<char[]> > linhas;

    while( std::cin >> entrada ){
        if( entrada.size() > 0 ) {
            std::unique_ptr<char[]> ptr_linha( new char[ entrada.size() + 1 ] );
            strncpy( ptr_linha.get(), entrada.c_str(), entrada.size() );
            ptr_linha[entrada.size()] = '\0';
            linhas.push_back(  std::move( ptr_linha ) );
        }
    }

    return 0;
}
