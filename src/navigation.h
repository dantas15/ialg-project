#pragma once
namespace Navigation
{
  // Main actions (available on mostly all pages)
  char MAIN_PAGE = 'M';
  char VIEW_ALL_ITEMS = 'P';
  char SEARCH_CHOOSE_FIELD = 'p';
  char ADD_ITEM = 'a';
  char SAVE = 's';
  char LEAVE = 'L';

  // Always used when SAVE or LEAVE is pressed previously
  char SAVE_AND_LEAVE = 'L';
  char LEAVE_WITHOUT_SAVING = 'F';

  // Main page options
  char IMPORT_DATA_FROM_CSV = 'I';
  char EXPORT_DATA_FROM_CSV = 'E';

  // Navigation between tables
  char SPECIFIC_PAGE_PREFIX = 'g';
  char NEXT_PAGE = 'k';
  char PREVIOUS_PAGE = 'j';

  // Create / Update actions
  // EDIT_ITEM_FIELD,
  // EDIT_ITEM,
  char DELETE_ITEM = 'D';

  // Dialog confirmations (preceds an important action)
  char CONFIRM = 'Y';
  char DECLINE = 'N';
}