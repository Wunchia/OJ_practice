#include <iostream>

#include "greeting.h"

int main() {
  if (Greet("Bazel") != "Hello, Bazel!") {
    std::cerr << "Greet failed for Bazel\n";
    return 1;
  }
  if (Greet("") != "Hello, !") {
    std::cerr << "Greet failed for empty name\n";
    return 1;
  }
  return 0;
}
