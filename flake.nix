{
  description = "Modern C++23 Development & Study Hub - Henrique Freire";

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
              # Modern Compilers & Build System (C++20 / C++23)
              gcc14
              llvmPackages_18.clang
              llvmPackages_18.lldb
              cmake
              ninja

              # Language Server, Linters & Formatters
              llvmPackages_18.clang-tools # clangd, clang-format, clang-tidy
              cppcheck

              # Debugging & Memory Profiling
              gdb
              valgrind

              # Unit Testing
              gtest
              catch2_3
            ];

            shellHook = ''
              # Prevent space-in-path issues with Nix wrappers
              export NIX_LDFLAGS="''${NIX_LDFLAGS#-rpath *outputs/out/lib}"

              echo "🚀 C++ Unified Study Hub Environment (C++23 Modern)"
              echo "Compiler: $(g++ --version | head -n 1)"
              echo "Clang:    $(clang++ --version | head -n 1)"
              echo "Debugger: $(gdb --version | head -n 1)"
              echo "--------------------------------------------------------"
              echo "Quick Compile Command (C++23 + AddressSanitizer):"
              echo "  g++ -std=c++23 -Wall -Wextra -pedantic -g -fsanitize=address main.cpp -o main"
              echo "--------------------------------------------------------"
            '';
          };
        }
      );
    };
}
