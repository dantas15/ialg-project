namespace Validation
{
  void showInvalidCommandError()
  {
    cout << "\n	(ㆆ _ ㆆ) Comando inválido. Tente novamente.\n";
  }

  bool pageCommandExists(string inputCommand, char contextChar)
  {
    if (inputCommand.length() > 1)
    {
      return false;
    }

    char command = inputCommand[0];

    bool exists = false;
    switch (contextChar)
    {
    case Navigation::MAIN_PAGE:
      exists = command == Navigation::IMPORT_DATA_FROM_CSV || command == Navigation::EXPORT_DATA_FROM_CSV;
      break;
    case Navigation::VIEW_ALL_ITEMS:
      exists = command == Navigation::NEXT_PAGE || command == Navigation::PREVIOUS_PAGE || command == Navigation::SPECIFIC_PAGE_PREFIX;
      break;
    case Navigation::SEARCH_CHOOSE_FIELD:
      exists = command == Navigation::NEXT_PAGE || command == Navigation::PREVIOUS_PAGE || command == Navigation::SPECIFIC_PAGE_PREFIX;
      break;
    case Navigation::ADD_ITEM:
      exists = command == Navigation::SAVE || command == Navigation::LEAVE;
      break;
    }
    return exists;
  }
}