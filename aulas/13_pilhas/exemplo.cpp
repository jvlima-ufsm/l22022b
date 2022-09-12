#include <iostream>
#include <vector>

int main(void)
{
  std::vector<int> pilha;
 
  pilha.push_back(10); 
  pilha.push_back(0); 
  pilha.push_back(99);
 
  while(pilha.empty() == false){
      std::cout << pilha.back() << ' ';
      pilha.pop_back();
  }

  std::cout << std::endl;
 
  return 0;
}