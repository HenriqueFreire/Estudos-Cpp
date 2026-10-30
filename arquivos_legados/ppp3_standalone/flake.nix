{
  description = "Modern C++23 Environment for Programming: Principles and Practice Using C++ (3rd Edition)";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs }:
    let
      supportedSystems = [ "x86_64-linux" "aarch64-linux" "x86_64-darwin" "aarch64-darwin" ];
      forAllSystems = nixpkgs.lib.genAttrs supportedSystems;
      nixpkgsFor = forAllSystems (system: import nixpkgs { inherit system; });
    in {
      devShells = forAllSystems (system:
        let
          pkgs = nixpkgsFor.${system};
        in {
          default = pkgs.mkShell {
            packages = with pkgs; [
              # Compilers & Build Tools (C++23 support)
              gcc14
              llvmPackages_18.clang
              llvmPackages_18.lldb
              cmake
              ninja

              # Language Server & Formatting
              llvmPackages_18.clang-tools # provides clangd, clang-format, clang-tidy

              # Debugging & Memory Profiling
              gdb
              valgrind
              cppcheck

              # Testing Frameworks
              gtest
              catch2_3
            ];

            shellHook = ''
              echo "🚀 C++23 Development Environment (PPP3 - Bjarne Stroustrup)"
              echo "Compiler: $(g++ --version | head -n 1)"
              echo "Clang:    $(clang++ --version | head -n 1)"
              echo "Debugger: $(gdb --version | head -n 1)"
              echo "--------------------------------------------------------"
              echo "To compile single file (C++23):"
              echo "  g++ -std=c++23 -Wall -Wextra -pedantic -g main.cpp -o main"
              echo "--------------------------------------------------------"
            '';
          };
        }
      );
    };
}
