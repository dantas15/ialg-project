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


void renderMain()
{
  cout << "\t\tSistema de Cadastro em Arquivos com Ordenação\n";
  cout << "\t\t\tdevelopers: andre, elian, gustavo\n";
  cout << "\n* Para importar dados de um arquivo .csv, Insira '" << Navigation::IMPORT_DATA_FROM_CSV << "'";
  cout << "\n* Para exportar dados para um arquivo .csv, Insira '" << Navigation::EXPORT_DATA_FROM_CSV << "'";
}

int main()
{
  string input(1, Navigation::MAIN_PAGE); // Initialize variable with main page command
  string previousCommand(1, Navigation::MAIN_PAGE);
  showMainMenu();
  renderMain();
  inputCommand(input);

  while (!Navigation::shouldLeave(input)) {
    string command;
    string nextCommand = ""; // This is used when you need to pass a command to another function
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

    clearConsole();

    switch (command[0])
    {
    case Navigation::MAIN_PAGE:
      showMainMenu();
      renderMain();
      break;
    case Navigation::IMPORT_DATA_FROM_CSV:
      if (previousCommand[0] != Navigation::MAIN_PAGE)
      {
        ImportDataFromCSV::renderImportData();
      }
      break;
    case Navigation::EXPORT_DATA_FROM_CSV:
      if (previousCommand[0] != Navigation::MAIN_PAGE)
      {
        ImportDataFromCSV::renderImportData();
      }
    default:
      // Validation::showInvalidCommandError();
      break;
    }

    previousCommand = command;
    if (nextCommand != "")
    {
      input = nextCommand;
    }
    else
    {
      inputCommand(input);
    }
  }

  cout << "\n\n\t \(^-^)/ Obrigado por utilzar nosso sistema! \(^-^)/ \n\n";

  return EXIT_SUCCESS;
}