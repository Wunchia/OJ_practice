#include <iostream>
#include <string>

#include "greeting.h"

int main(int argc, char* argv[]) {
  const std::string name = argc > 1 ? argv[1] : "Bazel";
  std::cout << Greet(name) << '\n';
  return 0;
}
