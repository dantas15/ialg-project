#pragma once

namespace ImportDataFromCSV
{
  const string LEAVE_COMMAND = "-1";

  void renderImportData(string &overrideGlobalCommand)
  {

    string csvFileName;
    string inputLabel = "Digite o nome do arquivo (.csv) ou " + LEAVE_COMMAND + " para sair: ";

    showHeader("Importar dados de um arquivo .csv");
    inputCommand(csvFileName, inputLabel);

    while (csvFileName != LEAVE_COMMAND)
    {
      overrideGlobalCommand = Navigation::MAIN;

      // Verify if csvFileName has the .csv extension, otherwise add it
      if (csvFileName.substr(csvFileName.find_last_of(".") + 1) != "csv")
      {
        csvFileName += ".csv";
      }

      ifstream file(csvFileName);
      if (!file.is_open())
      {
        Validation::showInvalidCommandError("Erro ao abrir o arquivo.");
        file.close();
      }
      
      

      inputCommand(csvFileName, inputLabel);
    };
  };
}