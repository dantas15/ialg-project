#pragma once

// 1: int
// 2: double
// 3: char[]
// 4: char[]
// 5: float[]
// ...
struct Medicine
{
  int id;
  double value;
  char* pricesAreTheSame; // "Positivo" or "Negativo"
  char* description;
  float marketPrice;
  bool active;
};
