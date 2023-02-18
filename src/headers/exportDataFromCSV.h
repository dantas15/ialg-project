#pragma once
namespace ExportDataFromCSV
{
  void renderExportData(string &overrideGlobalCommand)
  {
    showMainMenu();
    showHeader("Exportar dados do programa para um arquivo .csv");

    string csvFileNameOrCommand;

    inputCommand(csvFileNameOrCommand, "Digite um comando ou o nome do arquivo .csv que será gerado com os dados do programa: ");

    while (!Navigation::shouldLeave(csvFileNameOrCommand))
    {
      // Verify if csvFileNameOrCommand has the .csv extension, otherwise add it
      if (csvFileNameOrCommand.substr(csvFileNameOrCommand.find_last_of(".") + 1) != "csv")
      {
        csvFileNameOrCommand += ".csv";
      }

      ofstream csvOutFile(csvFileNameOrCommand);

      if (!csvOutFile.is_open())
      {
        Validation::showInvalidCommandError("Erro ao abrir o arquivo.");
        csvOutFile.close();
      }
      else
      {
        int numberOfMedicines = 0;
        Medicine *medicines = Binary::getAllMedicines(numberOfMedicines);

        // If there are medicines, write them to the csv file
        if (numberOfMedicines > 0)
        {
          for (int i = 0; i < numberOfMedicines; i++)
          {
            if (medicines[i].active)
            {
              csvOutFile << medicines[i].id << ";" << medicines[i].value << ";" << medicines[i].pricesAreTheSame << ";" << medicines[i].description << ";" << medicines[i].marketPrice << "\n";
            }
          }
        }
        else
        {
          Validation::showInvalidCommandError("Não há medicamentos cadastrados.");
        }

        csvOutFile.close();
        delete[] medicines;

        cout << "\nDados exportados com sucesso em " << csvFileNameOrCommand << "!\n";
        cout << "Pressione qualquer tecla para continuar no menu principal\n";
        cin.ignore();
      }
      csvFileNameOrCommand = Navigation::LEAVE_WITHOUT_SAVING;
      overrideGlobalCommand = Navigation::MAIN;
      return;
    };
  };
}