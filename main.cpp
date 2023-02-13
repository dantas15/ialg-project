#include <iostream>
#include <cstring>

using namespace std;

// helpers, utils, etc...
#include "src/navigation.h"
#include "src/dividers.h"
#include "src/defaultInputs.h"
#include "src/validations.h"

// Pages headers
#include "src/headers/startPage.h"
#include "src/headers/importDataFromCSV.h"
#include "src/headers/exportDataFromCSV.h"

const char DEFAULT_PAGE = Navigation::MAIN_PAGE;

int main()
{
  string input(1, DEFAULT_PAGE); // Initialize variable with main page command
  string previousCommand(1, DEFAULT_PAGE);
  showMainMenu();
  StartPage::renderStartPage();
  inputCommand(input);

  while (!Navigation::shouldLeave(input)) {
    string command;
    string nextCommand = ""; // This is used when you need to pass a command to another function
    
    // Remove whitespaces from input
    for (char c : input)
    {
      if (c != ' ')
      {
        command += c;
      }
    }

    if (isblank(command[0]))
    {
      command[0] = DEFAULT_PAGE;
    }

    switch (command[0])
    {
    case Navigation::MAIN_PAGE:
      StartPage::renderStartPage();
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
      Validation::showInvalidCommandError();
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

  cout << "\n\n\t \\(^-^)/ Obrigado por utilzar nosso sistema! \\(^-^)/ \n\n";

  return EXIT_SUCCESS;
}