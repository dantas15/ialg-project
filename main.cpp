#include <iostream>
#include <cstring>

// helpers, utils, etc...
#include "src/navigation.h"
#include "src/dividers.h"
#include "src/defaultInputs.h"
#include "src/validations.h"

// Pages
#include "src/pages/importDataFromCSV.h"
#include "src/pages/exportDataFromCSV.h"

using namespace std;

void clearConsole() {
  system("clear");
}

void renderMain()
{
  cout << "\t\tSistema de Cadastro em Arquivos com Ordenação\n";
  cout << "\t\t\tdevelopers: andre, elian, gustavo";
  cout << "\n\n* Para importar dados de um arquivo .csv, Insira '" << Navigation::IMPORT_DATA_FROM_CSV << "'";
  cout << "\n* Para exportar dados para um arquivo .csv, Insira '" << Navigation::EXPORT_DATA_FROM_CSV << "'";
}

int main()
{
  string input = "";
  showMainMenu();
  renderMain();
  inputCommand(input);

  do
  {
    clearConsole();

    string command;
    for (char c : input)
    {
      if (c != ' ')
      {
        command += c;
      }
    }

    if (isblank(command[0]))
    {
      command[0] = Navigation::MAIN_PAGE;
    }

    switch (command[0])
    {
    case Navigation::MAIN_PAGE:
      showMainMenu();
      renderMain();
      break;
    default:
      break;
    }

    bool pageCommandExists = false;
    do
    {
      inputCommand(input);
      pageCommandExists = Validation::pageCommandExists(input, command[0]);

      if (!pageCommandExists)
      {
        Validation::showInvalidCommandError();
      }
    } while (!pageCommandExists);

  } while (Navigation::shouldLeave(input));

  return EXIT_SUCCESS;
}