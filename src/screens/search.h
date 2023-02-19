namespace SearchScreen
{
  void renderSearch(string &overrideGlobalCommand)
  {
    int medsQuantity = 0;
    Medicine *meds = Binary::getAllMedicines(medsQuantity);

    if (medsQuantity == 0)
    {
      Validation::showInvalidCommandError("Não há medicamentos cadastrados.");
      overrideGlobalCommand = Navigation::MAIN;
      pressAnythingToContinue();
      return;
    }

    meds = ArrayHelpers::removeInactiveMeds(meds, medsQuantity);
    Sort::quicksortById(meds, 0, medsQuantity - 1);
    Binary::writeMedicines(meds, medsQuantity); // save sort to binary file

    long idToSearch;
    cout << "Insira o id para buscar: ";
    cin >> idToSearch;

    int index = Search::binarySearchById(meds, medsQuantity, idToSearch);

    if (index == -1)
    {
      Validation::showInvalidCommandError("Medicamento não encontrado!");
      overrideGlobalCommand = Navigation::MAIN;
      pressAnythingToContinue();
      return;
    }

    cout << "\nDigite " << Navigation::DELETE_ITEM << " para deletar o medicamento com id = " << meds[index].id;
    cout << "\nDigite " << Navigation::EDIT_ITEM << " para editar o medicamento com id = " << meds[index].id;
    cout << "\nDigite " << ViewAllItems::GO_BACK << " para voltar para a página inicial";

    string command;

    cout << "\nInsira uma opção: ";
    cin >> command;

    while (command != "-1")
    {
      if (command[0] == Navigation::DELETE_ITEM)
      {
        Binary::removeMedicineFromIndex(index);
        command = "-1";
      }
      else if (command[0] == Navigation::EDIT_ITEM)
      {
        bool success = Binary::editMedicineFromIndex(index);
        if (!success)
        {
          Validation::showInvalidCommandError("Erro ao editar, tente novamente!");
        }
        command = "-1";
      }
      else
      {
        cout << "\nDigite -1 para sair: ";
        cin >> command;
      }
    }
    overrideGlobalCommand = Navigation::MAIN;
    pressAnythingToContinue();
  }
}