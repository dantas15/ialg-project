#include <iostream>
#include "src/types/navigation.h"

using namespace std;

int main () {
  string command;

  cout << "--------------- Páginas ---------------";
  cout << "\n" << Navigation::MainActions::MAIN_PAGE << " = Página inicial";
  cout << "\t" << Navigation::ViewingAndListingActions::VIEW_ALL_ITEMS << " = visualizar todos";
  cout << "\t" << Navigation::SearchActions::CHOOSE_FIELD_TO_SEARCH << " = pesquisa";
  cout << "\n--------------- Comandos ---------------";
  cout << "\t" << Navigation::MainActions::SAVE << " = salvar";
  cout << "\t" << Navigation::MainActions::SAVE_AND_LEAVE << " = salvar e sair";
  cout << "\t" << Navigation::MainActions::LEAVE_WITHOUT_SAVING << " = sair sem salvar";

  cout << "\n----------------------------------------";

  cout << "\t\tSistema de Cadastro em Arquivos com Ordenação";
  cout << "\t\t\tdevelopers: andre, elian, gustavo";

  cout << "\n----------------------------------------";

  cout << "Insira um comando: ";
  cin >> command;
}