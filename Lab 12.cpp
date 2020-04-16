#include <iostream>
#include <string>

using namespace std;

class romanType
{
  public:
    romanType();
    void setRomanNumeral(string);
    string getRomanNumeral();
    int romanNumeralToIntegerNumber(string);
    void printRomanNumeral();
    void printIntegerNumber();
  private:
    string romanNumeral;
    int integerNumber;
    int numeralValue(char);
};

int main()
{
  // Declare local variables
  romanType romanNumerals;

  // Test with setting and getting MCXIV
  romanNumerals.setRomanNumeral("MCXIV");
  cout << "The roman numeral is " << romanNumerals.getRomanNumeral() << endl;
  romanNumerals.printRomanNumeral();
  romanNumerals.printIntegerNumber();
  cout << endl;

  // Test with setting and getting CCCLIX
  romanNumerals.setRomanNumeral("CCCLIX");
  cout << "The roman numeral is " << romanNumerals.getRomanNumeral() << endl;
  romanNumerals.printRomanNumeral();
  romanNumerals.printIntegerNumber();
  cout << endl;

  // Test with setting and getting MDCLXVI
  romanNumerals.setRomanNumeral("MDCLXVI");
  cout << "The roman numeral is " << romanNumerals.getRomanNumeral() << endl;
  romanNumerals.printRomanNumeral();
  romanNumerals.printIntegerNumber();
  cout << endl;

  return 0;
}

// Function Definitions
romanType::romanType()
{
  romanNumeral = "";
  integerNumber = 0;
}

void romanType::setRomanNumeral(string numeral)
{
  romanNumeral = numeral;
  integerNumber = romanNumeralToIntegerNumber(numeral);
  return;
}

string romanType::getRomanNumeral()
{
  return romanNumeral;
}

int romanType::romanNumeralToIntegerNumber(string numeral)
{
  // Define local varibale
  int stringLength = numeral.length();
  int integerValue = 0;
  int current;
  int next;
  // Loop through roman numeral
  for(int index = 0; index < stringLength - 1; index++)
  {
    current = numeralValue(numeral[index]);
    next = numeralValue(numeral[index + 1]);
    if(current >= next)
    {
      integerValue = integerValue + current;
    }
    else
    {
      integerValue = integerValue - current;
    }
  }
  integerValue = integerValue + numeralValue(numeral[stringLength - 1]);
  return integerValue;
}

void romanType::printRomanNumeral()
{
  cout << "The Roman Numeral is " << romanNumeral << "." << endl;
  return;
}

void romanType::printIntegerNumber()
{
  cout << "The Integer Number is " << integerNumber << "." << endl;
  return;
}

int romanType::numeralValue(char numeral)
{
  switch(numeral)
  {
    case 'M':
      return 1000;
    case 'D':
      return 500;
    case 'C':
      return 100;
    case 'L':
      return 50;
    case 'X':
      return 10;
    case 'V':
      return 5;
    case 'I':
      return 1;
    default:
      return 0;
  }
}
