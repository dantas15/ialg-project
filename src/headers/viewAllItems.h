#pragma once

namespace ViewAllItems
{
  const int GO_BACK = -1;

  const int ID = 1;
  const int DESCRIPTION = 2;

  const int SHOW_BY_PAGE = 1;
  const int SHOW_ALL = 2;

  const int PAGE_SIZE = 10;

  void displayDataAsTable(Medicine *meds, int loopSize)
  {
    cout << "Índice\tId\t\tDescrição\t\tPrecos iguais\tValor\tPreço de mercado" << endl;
    cout << "----------------------------------------------------------------------------------------" << endl;
    for (int i = 0; i < loopSize; i++)
    {
      char desc[255];
      strcpy(desc, meds[i].description);
      if (strlen(desc) > 10)
      {
        desc[10] = '\0';
        strcat(desc, "..."); // add ellipsis if length is greater than 10
      }
      cout << i + 1 << "\t" << meds[i].id << "\t" << desc << "\t\t" << meds[i].pricesAreTheSame << "\t" << meds[i].value << "\t" << meds[i].marketPrice << endl;
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "Índice\tId\t\tDescrição\t\tPrecos iguais\tValor\tPreço de mercado" << endl;
  }

  void showByPage(int &sortType)
  {
    switch (sortType)
    {
    case ID:
      //
      break;
    case DESCRIPTION:
      //
      break;
    default:
      break;
    }
  }
  void showAll(int &sortType)
  {
    int medsQuantity = 0;
    Medicine *meds = Binary::getAllMedicines(medsQuantity);

    if (medsQuantity == 0)
    {
      Validation::showInvalidCommandError("Não há medicamentos cadastrados.");
    }
    else
    {
      // Remove the inactive ones
      meds = ArrayHelpers::removeInactiveMeds(meds, medsQuantity);

      switch (sortType)
      {
      case ID:
        Sort::quicksortById(meds, 0, medsQuantity - 1);
        Binary::writeMedicines(meds, medsQuantity); // save sort to binary file
        break;
      case DESCRIPTION:
        Sort::quicksortByDescription(meds, 0, medsQuantity - 1);
        Binary::writeMedicines(meds, medsQuantity); // save sort to binary file
        break;
      default:
        break;
      }
      // Display the sorted data
      displayDataAsTable(meds, medsQuantity);
    }

    delete[] meds;
  }

  void renderViewAllItems(string &overrideGlobalCommand)
  {
    showMainMenu();
    showHeader("Visualizar os medicamentos cadastrados");

    int showType = 0;
    while (showType != ID && showType != DESCRIPTION && showType != GO_BACK)
    {
      cout << endl;
      cout << "\t" << SHOW_BY_PAGE << " - Mostrar em páginas\n";
      cout << "\t" << SHOW_ALL << " - Mostrar tudo de uma vez\n";
      cout << "\nEscolha como deseja mostrar os medicamentos ou digite " << GO_BACK << " para voltar ao menu principal: ";
      cin >> showType;
    }
    if (showType == GO_BACK)
    {
      overrideGlobalCommand = Navigation::MAIN;
      return;
    }

    int sortType = 0;
    while (sortType != ID && sortType != DESCRIPTION)
    {
      cout << endl;
      cout << "\t" << ID << " - Ordenar por ID\n";
      cout << "\t" << DESCRIPTION << " - Ordenar por Descrição\n";
      cout << "\nEscolha como deseja ordenar os medicamentos: ";
      cin >> sortType;
    }

    switch (showType)
    {
    case SHOW_BY_PAGE:
      showByPage(sortType);
      break;
    case SHOW_ALL:
      showAll(sortType);
      break;
    default:
      break;
    }
  }
}