#pragma once

namespace Validation
{
  void showInvalidCommandError(string customMessage = "")
  {
    if (customMessage != "")
      cout << "\n	(ㆆ _ ㆆ) " << customMessage << "\n";
    else
      cout << "\n	(ㆆ _ ㆆ) Comando inválido. Tente novamente.\n";
  }

  bool pageCommandExists(string inputCommand)
  {
    if (Navigation::shouldLeave(inputCommand))
    {
      return true;
    }

    char command = inputCommand[0];

    return command == Navigation::MAIN ||
           command == Navigation::VIEW_ALL_ITEMS ||
           command == Navigation::SEARCH_CHOOSE_FIELD ||
           command == Navigation::ADD_ITEM;
  }
}