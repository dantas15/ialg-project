#include <iostream>
#include <cstring>

using namespace std;

// helpers, utils, etc...
#include "src/navigation.h"
#include "src/dividers.h"
#include "src/defaultInputs.h"
#include "src/validations.h"

// Pages headers
#include "src/headers/intro.h"
#include "src/headers/importDataFromCSV.h"
#include "src/headers/exportDataFromCSV.h"

const char DEFAULT_COMMAND = Navigation::MAIN;

int main()
{
  string input(1, DEFAULT_COMMAND); // Initialize variable with main page command
  string previousCommand(1, DEFAULT_COMMAND);
  showMainMenu();
  Intro::renderIntro();
  inputCommand(input);

  while (!Navigation::shouldLeave(input))
  {
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

    // Set default page if command is empty
    if (isblank(command[0]))
    {
      command[0] = DEFAULT_COMMAND;
    }

    // - This switch is used to navigate between the main pages
    // there will be more navigation inside them specifically;
    // - Each of the main pages receive a reference to nextCommand
    // so they can override the input command on this file;
    switch (command[0])
    {
    case Navigation::MAIN:
      Intro::renderIntro();
      break;
    case Navigation::IMPORT_DATA_FROM_CSV:
      ImportDataFromCSV::renderImportData();
      break;
    case Navigation::EXPORT_DATA_FROM_CSV:
      ImportDataFromCSV::renderImportData();
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