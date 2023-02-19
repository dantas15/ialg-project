#pragma once

namespace DefaultInputs
{
  void inputCommand(string &input, string label = "Insira um comando: ")
  {
    cout << endl
         << label << " ";
    cin >> input;
    input = StringHelpers::removeWhiteSpacesFromString(input);
  }
}