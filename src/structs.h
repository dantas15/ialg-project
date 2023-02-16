#pragma once

// 1: long -> this was int first, but it had to change due to the data throwing an out_of_range exception
// 2: double
// 3: char[]
// 4: char[]
// 5: float[]
// ...

struct Medicine
{
  long id;
  double value;
  char pricesAreTheSame[8]; // "Positivo" or "Negativo"
  char description[255];
  float marketPrice;
  bool active;
};
