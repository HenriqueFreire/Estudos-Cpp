#include <fstream>  // Para std::ofstream, std::ifstream
#include <iostream> // Para std::cin, std::cout, std::endl
#include <string>   // Para std::string, std::getline

int main() {
  // --- 1. Saída de Dados (Escrita) para o Console com std::cout ---
  std::cout << "--- Escrita para o Console (std::cout) ---" << std::endl;
  std::cout << "Olá, mundo!"
            << std::endl; // Imprime uma string e quebra de linha
  int idade = 30;
  std::cout << "Minha idade é: " << idade << " anos."
            << std::endl; // Imprime variável
  double preco = 19.99;
  std::cout << "O preço é: R$" << preco << std::endl; // Imprime double

  std::cout << '\n'; // Imprime uma linha em branco

  // --- 2. Entrada de Dados (Leitura) do Console com std::cin ---
  std::cout << "--- Leitura do Console (std::cin) ---" << std::endl;
  int numero;
  std::cout << "Digite um número inteiro: ";
  std::cin >> numero; // Lê um número inteiro do teclado
  std::cout << "Você digitou: " << numero << std::endl;

  double valor;
  std::cout << "Digite um valor decimal: ";
  std::cin >> valor; // Lê um valor decimal
  std::cout << "Você digitou: " << valor << std::endl;

  // IMPORTANTE: Limpar o buffer do teclado após std::cin >>
  // std::cin >> deixa o caractere de nova linha no buffer,
  // o que pode causar problemas com std::getline() subsequente.
  std::cin.ignore(); // Ignora o restante da linha atual no buffer de entrada

  std::string nome;
  std::cout << "Digite seu nome (com espaços): ";
  std::getline(std::cin, nome); // Lê uma linha inteira, incluindo espaços
  std::cout << "Olá, " << nome << "!" << std::endl;

  std::cout << '\n';

  // --- 3. Escrita de Dados para um Arquivo com std::ofstream ---
  std::cout << "--- Escrita para Arquivo (std::ofstream) ---" << std::endl;
  // Cria um objeto ofstream para escrever no arquivo
  // "exemplo.txt" será criado ou sobrescrito se já existir
  std::ofstream arquivoSaida("exemplo.txt");

  // Verifica se o arquivo foi aberto com sucesso
  if (arquivoSaida.is_open()) {
    arquivoSaida << "Este é um texto escrito no arquivo." << std::endl;
    arquivoSaida << "Números também podem ser escritos: " << 12345 << std::endl;
    arquivoSaida << "E variáveis: " << nome << std::endl;
    arquivoSaida.close(); // Fecha o arquivo
    std::cout << "Dados escritos em 'exemplo.txt' com sucesso." << std::endl;
  } else {
    std::cerr << "Erro ao abrir o arquivo para escrita!" << std::endl;
  }

  std::cout << '\n';

  // --- 4. Leitura de Dados de um Arquivo com std::ifstream ---
  std::cout << "--- Leitura de Arquivo (std::ifstream) ---" << std::endl;
  // Cria um objeto ifstream para ler do arquivo
  std::ifstream arquivoEntrada("exemplo.txt");
  std::string linha;

  // Verifica se o arquivo foi aberto com sucesso
  if (arquivoEntrada.is_open()) {
    std::cout << "Conteúdo de 'exemplo.txt':" << std::endl;
    // Lê o arquivo linha por linha até o final
    while (std::getline(arquivoEntrada, linha)) {
      std::cout << linha << std::endl;
    }
    arquivoEntrada.close(); // Fecha o arquivo
  } else {
    std::cerr << "Erro ao abrir o arquivo para leitura!" << std::endl;
  }

  std::cout << '\n';

  // --- 5. Escrita em Modo de Anexar (Append) ---
  std::cout << "--- Escrita em Modo de Anexar (std::ofstream::app) ---"
            << std::endl;
  // Abre o arquivo em modo de anexar (ios::app), para adicionar conteúdo ao
  // final
  std::ofstream arquivoAnexar("exemplo.txt", std::ios::app);

  if (arquivoAnexar.is_open()) {
    arquivoAnexar << "Esta linha foi adicionada ao final." << std::endl;
    arquivoAnexar.close();
    std::cout << "Nova linha adicionada a 'exemplo.txt' com sucesso."
              << std::endl;
  } else {
    std::cerr << "Erro ao abrir o arquivo para anexar!" << std::endl;
  }

  std::cout << '\n';

  // --- 6. Leitura do Arquivo Atualizado ---
  std::cout << "--- Leitura do Arquivo Atualizado ---" << std::endl;
  std::ifstream arquivoEntradaAtualizado("exemplo.txt");
  if (arquivoEntradaAtualizado.is_open()) {
    std::cout << "Conteúdo atualizado de 'exemplo.txt':" << std::endl;
    while (std::getline(arquivoEntradaAtualizado, linha)) {
      std::cout << linha << std::endl;
    }
    arquivoEntradaAtualizado.close();
  } else {
    std::cerr << "Erro ao abrir o arquivo atualizado para leitura!"
              << std::endl;
  }

  return 0;
}
