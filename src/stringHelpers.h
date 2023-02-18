#pragma once

namespace StringHelpers
{
  string removeWhiteSpacesFromString(string input)
  {
    string newString = "";
    for (char c : input)
    {
      if (c != ' ')
      {
        newString += c;
      }
    }

    return newString;
  }

  void replaceCommasWithPoints(string &str)
  {
    for (int i = 0; i < (int)str.length(); i++)
    {
      if (str[i] == ',')
      {
        str[i] = '.';
      }
    }
  }
}