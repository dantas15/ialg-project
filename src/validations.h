#pragma once

namespace Validation
{
  using namespace Navigation;

  void showInvalidCommandError()
  {
    cout << "\n	(ㆆ _ ㆆ) Comando inválido. Tente novamente.\n";
  }

  bool pageCommandExists(string inputCommand)
  {
    if (shouldLeave(inputCommand))
    {
      return true;
    }

    char command = inputCommand[0];

    return command == MAIN_PAGE ||
           command == VIEW_ALL_ITEMS ||
           command == SEARCH_CHOOSE_FIELD ||
           command == ADD_ITEM;
  }
}