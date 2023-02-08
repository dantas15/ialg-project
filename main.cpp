#include <iostream>
#include "src/navigation.h"
#include "src/dividers.h"

using namespace std;

int main()
{
  string command;

  showMainMenu();

  cout << "\t\tSistema de Cadastro em Arquivos com Ordenação\n";
  cout << "\t\t\tdevelopers: andre, elian, gustavo";
  cout << "\n\n* Para importar dados de um arquivo .csv, Insira '" << Navigation::IMPORT_DATA_FROM_CSV << "'";
  cout << "\n* Para exportar dados para um arquivo .csv, Insira '" << Navigation::EXPORT_DATA_FROM_CSV << "'";

  showDivider();

  cout << "\nInsira um comando: ";
  cin >> command;
}