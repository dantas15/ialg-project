#pragma once

namespace Intro
{
  void renderIntro()
  {
    showMainMenu();
    cout << "\t\tSistema de Cadastro em Arquivos com Ordenação\n";
    cout << "\t\t\tdevelopers: andre, elian, gustavo\n";
    cout << "\n* Para importar dados de um arquivo .csv, Insira '" << Navigation::IMPORT_DATA_FROM_CSV << "'";
    cout << "\n* Para exportar dados para um arquivo .csv, Insira '" << Navigation::EXPORT_DATA_FROM_CSV << "'";
  }
}