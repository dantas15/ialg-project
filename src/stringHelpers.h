#pragma once

namespace StringHelpers 
{
  string removeWhiteSpacesFromString(string input)
  {
    // Remove whitespaces from input
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
}