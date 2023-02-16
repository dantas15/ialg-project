#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// helpers, utils, etc...
#include "src/structs.h"
#include "src/navigation.h"
#include "src/dividers.h"
#include "src/defaultInputs.h"
#include "src/validations.h"
#include "src/stringHelpers.h"
#include "src/arrayHelpers.h"
#include "src/binary.h"

// Sort and search algorithms
#include "src/algorithms/sort.h"
#include "src/algorithms/search.h"

using namespace DefaultInputs;

// Pages headers
#include "src/headers/intro.h"
#include "src/headers/importDataFromCSV.h"
#include "src/headers/exportDataFromCSV.h"

const char DEFAULT_COMMAND = Navigation::MAIN;

int main()
{
  string global_input(1, DEFAULT_COMMAND); // Initialize variable with main page global_command
  string global_previousCommand(1, DEFAULT_COMMAND);

  while (!Navigation::shouldLeave(global_input))
  {
    string global_command;
    string global_nextCommand = ""; // This is used when you need to pass a global_command to another function]

    global_command = StringHelpers::removeWhiteSpacesFromString(global_input);

    // Set default page if global_command is empty
    if (isblank(global_command[0]))
    {
      global_command[0] = DEFAULT_COMMAND;
    }

    // - This switch is used to navigate between the main pages
    // there will be more navigation inside them specifically;
    // - Each of the main pages receive a reference to nextCommand
    // so they can override the input global_command on this file;
    switch (global_command[0])
    {
    case Navigation::MAIN:
      clearConsole();
      Intro::renderIntro();
      break;
    case Navigation::IMPORT_DATA_FROM_CSV:
      clearConsole();
      ImportDataFromCSV::renderImportData(global_nextCommand);
      break;
    case Navigation::EXPORT_DATA_FROM_CSV:
      ExportDataFromCSV::renderExportData();
    default:
      Validation::showInvalidCommandError();
      break;
    }

    global_previousCommand = global_command;
    if (global_nextCommand != "")
    {
      global_input = global_nextCommand;
    }
    else
    {
      showDivider();
      inputCommand(global_input);
    }
  }

  cout << "\n\n\t \\(^-^)/ Obrigado por utilzar nosso sistema! \\(^-^)/ \n\n";

  return EXIT_SUCCESS;
}