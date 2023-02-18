#pragma once

namespace ImportDataFromCSV
{
  const string LEAVE_COMMAND = "-1";

  void renderImportData(string &overrideGlobalCommand)
  {

    string csvFileNameOrCommand;
    string inputLabel = "Digite o nome do arquivo (.csv) dentro da pasta `put_csv_here` ou digite " + LEAVE_COMMAND + " para voltar: ";

    showHeader("Importar dados de um arquivo .csv");
    inputCommand(csvFileNameOrCommand, inputLabel);

    while (csvFileNameOrCommand != LEAVE_COMMAND)
    {
      overrideGlobalCommand = Navigation::MAIN;

      // Verify if csvFileNameOrCommand has the .csv extension, otherwise add it
      if (csvFileNameOrCommand.substr(csvFileNameOrCommand.find_last_of(".") + 1) != "csv")
      {
        csvFileNameOrCommand += ".csv";
      }

      string filePath = "put_csv_here/" + csvFileNameOrCommand;
      cout << "\nCaminho procurado (partindo do root do projeto): " << filePath << endl;
      ifstream file(filePath);
      if (!file.is_open())
      {
        Validation::showInvalidCommandError("Erro ao abrir o arquivo.");
        file.close();
      }
      else
      {
        int medsSize = 0;
        Medicine *medicines = new Medicine[0];

        string line, field;
        int i = 0;
        while (getline(file, line))
        {
          stringstream ss(line);
          medicines = ArrayHelpers::increaseArraySize(medicines, medsSize);

          getline(ss, field, ';');
          medicines[i].id = stol(field);

          getline(ss, field, ';');
          StringHelpers::replaceCommasWithPoints(field);
          medicines[i].value = stod(field);

          getline(ss, field, ';');
          strcpy(medicines[i].pricesAreTheSame, field.c_str());

          getline(ss, field, ';');
          strcpy(medicines[i].description, field.c_str());

          getline(ss, field, ';');
          StringHelpers::replaceCommasWithPoints(field);
          medicines[i].marketPrice = stof(field);

          // default value for `active` is true
          medicines[i].active = true;

          i++;
        }

        // Sort medicines by id
        Sort::quicksortById(medicines, 0, medsSize-1);

        // Save sorted medicines data to binary file
        Binary::writeMedicines(medicines, medsSize);
        delete[] medicines;

        // Go back to main menu once the file is imported
        overrideGlobalCommand = Navigation::MAIN;
        pressAnythingToContinue();
        return;
      }

      inputCommand(csvFileNameOrCommand, inputLabel);
    };

    // Go back to main menu if user typed -1
    overrideGlobalCommand = Navigation::MAIN;
  };
}