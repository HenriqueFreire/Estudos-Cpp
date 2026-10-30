#include <iostream>
using namespace std;

int main(){
  for(int i = 0; i < 10; ++i){
    cout << "for - " << i << "\n";
  }

  int j = 0;
  while(j < 10){
    cout << "while - " << j << "\n";
    ++j;
  }

  return 0;
}
