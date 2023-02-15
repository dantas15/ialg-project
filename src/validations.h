#pragma once

namespace Validation
{
  void showInvalidCommandError()
  {
    cout << "\n	(ㆆ _ ㆆ) Comando inválido. Tente novamente.\n";
  }

  bool pageCommandExists(string inputCommand)
  {
    if (Navigation::shouldLeave(inputCommand))
    {
      return true;
    }

    char command = inputCommand[0];

    return command == Navigation::MAIN_PAGE ||
           command == Navigation::VIEW_ALL_ITEMS ||
           command == Navigation::SEARCH_CHOOSE_FIELD ||
           command == Navigation::ADD_ITEM;
  }
}