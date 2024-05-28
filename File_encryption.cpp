#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  string txt;
  cout << "Enter a Text : ";
  getline(cin, txt);

  int n;
  cout << "Enter a number  : ";
  cin >> n;

  for (int i = 0; i < txt.size(); i++)
  {
    txt[i] = txt[i] + n;
  }
  ofstream out("file.txt");
  if (out.is_open())
  {
    out << txt;
  }
  out.close();

  string str;

  cout << "Encrypted Text read from a file : ";  // encryption using a ceapher cipher algorithm
  ifstream in("file.txt");
  if (in.is_open())
  {
    while (!in.eof())
    {
      getline(in, str);
      cout << str << endl;
    }
  }
}
