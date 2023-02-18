#pragma once

namespace Navigation
{
  // Main actions (available on mostly all pages)
  const char MAIN = 'M';
  const char VIEW_ALL_ITEMS = 'P';
  const char SEARCH_CHOOSE_FIELD = 'p';
  const char ADD_ITEM = 'a';
  const char SAVE_AND_LEAVE [] = "sL";
  const char LEAVE_WITHOUT_SAVING [] = "LF";

  // Main page options
  const char IMPORT_DATA_FROM_CSV = 'I';
  const char EXPORT_DATA_FROM_CSV = 'E';

  // Navigation between tables
  const char SPECIFIC_PAGE_PREFIX = 'g';
  const char NEXT_PAGE = 'k';
  const char PREVIOUS_PAGE = 'j';

  // Create / Update actions
  // EDIT_ITEM_FIELD,
  // EDIT_ITEM,
  const char DELETE_ITEM = 'D';

  // Dialog confirmations (preceds an important action)
  const char CONFIRM = 'Y';
  const char DECLINE = 'N';

  bool shouldLeave(string command = "")
  {
    bool leaveWithoutSaving = command == string(LEAVE_WITHOUT_SAVING);
    bool saveAndLeave = command == string(SAVE_AND_LEAVE);
    return leaveWithoutSaving || saveAndLeave;
  }
}