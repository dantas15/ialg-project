#pragma once

namespace DefaultInputs
{
  void inputCommand(string &input, string label = "Insira um comando: ")
  {
    cout << endl << label;
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
}