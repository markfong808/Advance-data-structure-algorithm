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
  static int counter; // Counter to keep track of shuffle number

public:
  friend ostream &operator<<(ostream &out, const Shuffle &shuffle);

  Shuffle()
  {
    for (int i = 1; i <= 9; i++)
    {
      nums.push_back(i);
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
  if (argc < 2)
  {
    cout << "Usage: ./myhw <num_times>" << endl;
    return 1;
  }

  // converts a string to an integer
  // second argument
  int numTimes = atoi(argv[1]);

  for (int i = 0; i < numTimes; i++)
  {
    Shuffle b;
    cout << b << endl;
  }
  return 0;
}