#include <iostream>
using namespace std;

int main(){
  int num = 12;

  if(num > 10){
    cout << "num é maior que 10!";
  }else if (num < 0){
    cout << "num é menor que 0!";
  }else{
    cout << "num está entre 0 e 10!";
  }

  return 0;
}
