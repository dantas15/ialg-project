#pragma once

using namespace std;

void clearConsole()
{
  system("clear");
}

void showDivider()
{
  cout << "\n\n-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n\n";
}
void showHeader(string header)
{
  cout << "\n------------------------------" << header << "------------------------------\n";
}

void showMainMenu()
{
  showHeader("Páginas");
  cout << Navigation::MAIN << " = Página inicial";
  cout << "\t" << Navigation::VIEW_ALL_ITEMS << " = visualizar todos";
  cout << "\t" << Navigation::SEARCH_CHOOSE_FIELD << " = pesquisa";

  showHeader("Comandos");
  cout << "\t" << Navigation::SAVE_AND_LEAVE << " = salvar e sair";
  cout << "\t" << Navigation::LEAVE_WITHOUT_SAVING << " = sair sem salvar";

  showDivider();
}
