namespace Create
{
  void renderCreate(string &overrideGlobalCommand)
  {
    clearConsole();
    showHeader("Criar um novo medicamento");

    Medicine med;

    cout << "\nInsira o número de identificação: ";
    cin >> med.id;

    string aux;
    cout << "Insira a descrição do medicamento: ";
    cin.ignore();
    getline(cin, aux);
    strcpy(med.description, aux.c_str());

    cout << "\nInsira o valor do medicamento (use '.' ao invés de ','): ";
    cin >> med.value;

    cout << "\nInsira o valor do medicamento (use '.' ao invés de ','): ";
    cin >> med.marketPrice;

    string pricesAreTheSame;

    // not exactly precise
    if (double(med.marketPrice) == med.value)
      pricesAreTheSame = "Positivo";
    else
      pricesAreTheSame = "Negativo";

    strcpy(med.pricesAreTheSame, pricesAreTheSame.c_str());

    med.active = true;

    bool success = Binary::insertNewMed(med);

    if (success)
      cout << "\nMedicamento criado com sucesso!\n";

    overrideGlobalCommand = Navigation::MAIN;
  }
}