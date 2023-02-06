#pragma once

namespace Navigation
{
  enum MainActions
  {
    MAIN_PAGE = 'M',
    SAVE = 's',
    SAVE_AND_LEAVE = 'sL',
    LEAVE_WITHOUT_SAVING = 'FL',
  };

  enum ViewingAndListingActions {
    VIEW_ALL_ITEMS = 'P',
    SPECIFIC_PAGE = 'p',
    NEXT_PAGE = 'k',
    PREVIOUS_PAGE = 'j',
  };

  enum SearchActions {
    CHOOSE_FIELD_TO_SEARCH = 'p',
    SEARCH_FIELD,
  };

  enum CreateAndUpdateActions {
    EDIT_ITEM_FIELD,
    ADD_ITEM = 'a',
    EDIT_ITEM,

    DELETE_ITEM = 'D',
    
    CONFIRM = 'Y',
    DECLINE = 'N'
  };
}