#include <iostream>

// Um 'struct' em C++. Por padrão, seus membros são PÚBLICOS.
struct Ponto2D_Struct {
  double x;
  double y;
};

// Uma 'class' em C++. Por padrão, seus membros são PRIVADOS.
class Ponto2D_Class {
public:
  // Para permitir acesso externo, precisamos de um construtor público
  // e/ou métodos de acesso públicos.
  Ponto2D_Class(double x_val, double y_val) : x(x_val), y(y_val) {}

  void imprimir() const {
    std::cout << "Classe: (" << x << ", " << y << ")\n";
  }

private:
  double x;
  double y;
};

int main() {
  // Com o struct, podemos acessar e modificar os membros diretamente.
  Ponto2D_Struct p_struct;
  p_struct.x = 10.0;
  p_struct.y = 20.0;
  std::cout << "Struct: (" << p_struct.x << ", " << p_struct.y << ")\n";

  // Com a classe, o acesso direto aos membros privados é proibido.
  Ponto2D_Class p_class(30.0, 40.0);
  // p_class.x = 50.0; // ERRO DE COMPILAÇÃO! 'x' é privado.
  p_class.imprimir();

  return 0;
}

/*
  Explicação: struct vs. class

  A única diferença técnica entre `struct` e `class` em C++ é o nível de acesso
  padrão de seus membros:
  - `struct`: Membros são `public` por padrão.
  - `class`: Membros são `private` por padrão.

  Além disso, a herança também tem um padrão diferente:
  - `struct Herdeiro : Base { ... }` -> herança `public` por padrão.
  - `class Herdeiro : Base { ... }` -> herança `private` por padrão.

  Fora isso, eles são funcionalmente idênticos. Ambos podem ter construtores,
  destrutores, métodos, herança, etc.

  Convenção e Implicações para HFT:

  A convenção moderna, especialmente em código de alta performance, é usar:
  - `struct`: Para agrupar dados passivos (Plain Old Data - POD). Pense neles
    como um "pacote" de variáveis. Eles não têm lógica complexa ou "invariantes"
    (regras que devem ser mantidas entre seus membros). Exemplos: uma mensagem
    de rede, um ponto 2D/3D, uma ordem de mercado. O acesso direto aos membros
    é desejável e esperado.

  - `class`: Para criar tipos de dados que têm "invariantes" e encapsulam
    lógica. Os membros são privados para garantir que o estado do objeto só
    possa ser modificado através de métodos públicos, que podem impor regras e
    garantir a consistência dos dados.

  Em HFT, você verá muitos `struct`s para representar pacotes de dados que
  mapeiam diretamente para mensagens de protocolo ou para agrupar dados que
  serão processados em conjunto, maximizando a clareza e minimizando o
  boilerplate de getters/setters. `class`es são usadas para componentes mais
  complexos do sistema, como o próprio matching engine, um gerenciador de
  conexões, etc.
*/