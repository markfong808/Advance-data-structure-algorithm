#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <random>

using namespace std;

class Shuffle
{
private:
  vector<int> nums;
  // As a static variable, counter is shared among all instances of the Shuffle class. It means that all objects of the class will have access to and modify the same counter variable. This ensures that the shuffle number is incremented
  // Counter to keep track of shuffle number
  static int counter;

public:
  friend ostream &operator<<(ostream &out, const Shuffle &shuffle);

  Shuffle(const string &digits)
  {

    for (char digit : digits)
    {
      nums.push_back(digit - '0');
    }

    // Fisher-Yates Shuffle
    for (int i = nums.size() - 1; i > 0; i--)
    {
      int j = rand() % (i + 1);
      swap(nums[i], nums[j]);
    }
  }
};

int Shuffle::counter = 1;

string getLetterIndicator(int number)
{
  static const char *indicators[] = {"first", "second", "third", "fourth", "fifth", "sixth", "seventh", "eighth", "ninth", "tenth"};

  if (number >= 1 && number <= 10)
    return indicators[number - 1];
  else
    return to_string(number) + "th";
}

ostream &operator<<(ostream &out, const Shuffle &shuffle)
{
  string top_bottom_border = "+ - - - - - - - +";
  string oridinal = getLetterIndicator(Shuffle::counter);
  out << "The " << oridinal << " shuffled output is:" << endl;
  out << top_bottom_border << endl;

  for (int i = 0; i < shuffle.nums.size(); i += 3)
  {
    out << "|   " << shuffle.nums[i] << "   " << shuffle.nums[i + 1] << "   "
        << shuffle.nums[i + 2] << "   |" << endl;
  }
  out << top_bottom_border << endl;

  // Increment the counter
  Shuffle::counter++;
  return out;
}

int main(int argc, char **argv)
{
  string digits;
  cout << "Please input 9 digits to be randomly shuffled: ";
  cin >> digits;

  if (digits.length() != 9)
  {
    cout << "Invalid input. Please provide exactly 9 digits." << endl;
  }

  if (argc < 2)
  {
    cout << "Usage: ./myhw <num_times>" << endl;
    return 1;
  }

  // converts a string to an integer
  // second argument
  // argv[0] = ./myhw  , argv[1] = whatever integer user input
  int numTimes = atoi(argv[1]);

  for (int i = 0; i < numTimes; i++)
  {
    Shuffle b(digits);
    cout << b << endl;
  }
  return 0;
}