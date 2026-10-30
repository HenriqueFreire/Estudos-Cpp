{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    # Compilador e ferramentas de build
    gcc
    cmake
    gnumake
    ninja

    # Depuração e análise
    gdb
    valgrind

    # Opcional: Linguagem e LSP para editores
    clang-tools # Fornece clangd para autocompletar no VS Code/Vim
  ];

  shellHook = ''
    echo "--- Ambiente de Desenvolvimento C++ Ativo ---"
    g++ --version | head -n 1
    cmake --version | head -n 1
    ninja --version | sed 's/^/ninja version /'
  '';
}
