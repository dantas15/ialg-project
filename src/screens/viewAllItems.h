#pragma once

namespace ViewAllItems
{
  const int GO_BACK = -1;

  const int ID = 1;
  const int DESCRIPTION = 2;

  const int SHOW_BY_PAGE = 1;
  const int SHOW_ALL = 2;

  const int PAGE_SIZE = 10;

  const char SPECIFIC_PAGE_PREFIX = 'p';
  const char NEXT_PAGE = 'k';
  const char PREVIOUS_PAGE = 'j';

  void showNavigationMenu()
  {
    showDivider();

    // cout << "\nDigite " << NEXT_PAGE << " para ir para a próxima página";
    // cout << "\nDigite " << PREVIOUS_PAGE << " para ir para a página anterior";
    // cout << "\nDigite " << SPECIFIC_PAGE_PREFIX << " + número da página para ir para uma página específica (Ex.: " << SPECIFIC_PAGE_PREFIX << "3 para a página 3)";
    cout << "\nDigite " << Navigation::DELETE_ITEM << " + índice para deletar o medicamento especificado (Ex.: " << Navigation::DELETE_ITEM << "10 para o índice 10 )";
    cout << "\nDigite " << Navigation::EDIT_ITEM << " + índice para editar o medicamento especificado (Ex.: " << Navigation::DELETE_ITEM << "8 para o índice 8 )";
    cout << "\nDigite " << GO_BACK << " para voltar para a página inicial";

    showDivider();
  }

  void displayDataAsTable(Medicine *meds, int loopSize, int currentPage = -1, int totalPages = -1)
  {
    cout << "Índice\tId\t\tDescrição\tPrecos iguais\tValor\tPreço de mercado" << endl;
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
      if (meds[i].active)
      {
        cout << i;
      }
      else
      {
        cout << "(Inativo)";
      }
      cout << "\t" << meds[i].id << "\t" << desc << "\t" << meds[i].pricesAreTheSame << "\t" << meds[i].value << "\t" << meds[i].marketPrice << endl;
    }
    cout << "----------------------------------------------------------------------------------------" << endl;
    cout << "Índice\tId\t\tDescrição\tPrecos iguais\tValor\tPreço de mercado" << endl;
    if (currentPage != -1 && totalPages != -1)
    {
      cout << "Página " << currentPage << " de " << totalPages << endl;
    }
  }

  void showByPage(int &sortType)
  {
  }
  void showAll(Medicine *meds, int &medsQuantity)
  {
    // Display the sorted data
    displayDataAsTable(meds, medsQuantity);
    delete[] meds;

    string command;

    showNavigationMenu();
    cout << "Insira um comando: ";
    cin >> command;

    while (command != "-1")
    {
      if (command[0] == Navigation::DELETE_ITEM)
      {
        Binary::removeMedicineFromIndex(stoi(command.substr(1)));
      }
      else if (command[0] == Navigation::EDIT_ITEM)
      {
        bool success = Binary::editMedicineFromIndex(stoi(command.substr(1)));
        if (!success)
          Validation::showInvalidCommandError("Erro ao editar, tente novamente!");
      }
      else
      {
        Validation::showInvalidCommandError();
      }

      showNavigationMenu();
      cout << "Insira um comando: ";
      cin >> command;
    }
  }

  void renderViewAllItems(string &overrideGlobalCommand)
  {
    showMainMenu();
    showHeader("Visualizar os medicamentos cadastrados");

    int sortType = 0;
    while (sortType != ID && sortType != DESCRIPTION)
    {
      cout << endl;
      cout << "\t" << ID << " - Ordenar por ID\n";
      cout << "\t" << DESCRIPTION << " - Ordenar por Descrição\n";
      cout << "\nEscolha como deseja ordenar os medicamentos ou digite " << GO_BACK << " para voltar ao menu principal: ";
      cin >> sortType;
    }
    if (sortType == GO_BACK)
    {
      overrideGlobalCommand = Navigation::MAIN;
      return;
    }

    int showType = 0;
    while (showType != ID && showType != DESCRIPTION && showType != GO_BACK)
    {
      // cout << endl;
      // cout << "\t" << SHOW_BY_PAGE << " - Mostrar em páginas\n";
      // cout << "\t" << SHOW_ALL << " - Mostrar tudo de uma vez\n";
      // cout << "\nEscolha como deseja mostrar os medicamentos: ";
      // cin >> showType;
      showType = SHOW_ALL; // show paginated is not implemented yet :/
    }

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

      switch (showType)
      {
      case SHOW_BY_PAGE:
        delete[] meds;
        showByPage(sortType);
        break;
      case SHOW_ALL:
        showAll(meds, medsQuantity);
        break;
      default:
        delete[] meds;
        break;
      }
      overrideGlobalCommand = Navigation::MAIN;
      return;
    }
  }
}