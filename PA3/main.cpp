#include <iostream>
#include <chrono>
#include <cmath>

unsigned long long fatorial_recursivo(int n) {
  if (n <= 1) return 1;
  for (int i = 0; i < 1000000; i++) { sin(n); }
  return n * fatorial_recursivo(n - 1);
}

unsigned long long fatorial(int n) {
  unsigned long long resultado = 1;
  for (int i = 2; i <= n; i++) {
    resultado *= i;
  }
  return resultado;
}

int fibonacci_recursivo(int n) {
  if (n <= 1) return n;
  for (int i = 0; i < 1000000; i++) { sin(n); }
  return fibonacci_recursivo(n - 1) + fibonacci_recursivo(n - 2);
}

int fibonacci(int n) {
  if (n <= 1) return n;
  
  int a = 0, b = 1, resultado;
  for (int i = 2; i <= n; i++) {
    resultado = a + b;
    a = b;
    b = resultado;
  }
  return b;
}

int main() {

  auto start1 = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado do fatorial iterativo: " << fatorial(25) << std::endl;
  auto end1 = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> duration1 = end1 - start1;
  std::cout << "Tempo de execução: " << duration1.count() << " segundos." << std::endl;

  std::cout << std::endl;

  auto start2 = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado do fatorial recursivo: " << fatorial_recursivo(25) << std::endl;
  auto end2 = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> duration2 = end2 - start2;
  std::cout << "Tempo de execução: " << duration2.count() << " segundos." << std::endl;

  std::cout << std::endl;

  auto start3 = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado do Fibonacci iterativo: " << fibonacci(25) << std::endl;
  auto end3 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> duration3 = end3 - start3;
  std::cout << "Tempo de execução: " << duration3.count() << " segundos." << std::endl;

  std::cout << std::endl;

  auto start4 = std::chrono::high_resolution_clock::now();
  std::cout << "Resultado do Fibonacci recursivo: " << fibonacci_recursivo(25) << std::endl;
  auto end4 = std::chrono::high_resolution_clock::now(); 
  std::chrono::duration<double> duration4 = end4 - start4;
  std::cout << "Tempo de execução: " << duration4.count() << " segundos." << std::endl;


  return 0;
}
