void inputCommand(string &input)
{
  showDivider();
  cout << "\nInsira um comando: ";
  getline(cin, input);
}

void inputString(string &input)
{
  getline(cin, input);
}

void inputInt(int &input)
{
  cin >> input;
}

void inputFloat(float &input)
{
  cin >> input;
}

void inputDouble(double &input)
{
  cin >> input;
}