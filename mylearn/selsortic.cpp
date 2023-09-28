#include<iostream>

using namespace std;

int main() {
  string name[6] = {"Rachel", "Joey", "Ross", "Phoebe", "Monica", "Chandler"};
  int time[6] = {32, 24, 22, 27, 19, 35};
  int length = 6;
  for(int i = 0; i < length - 1; i++)
  {
    int min = time[i];
    int index = i;
    for(int j = i + 1; j < length -1; j++)
    {
      if(time[j] < min)
      {
        min = time[j];
        index = j;
      }
    }
    int temp = time[i];
    time[i] = time[index];
    time[index] = temp;
    string temp2 = name[i];
    name[i] = name[index];
    name[index] = temp2;
  }

  for (size_t i = 0; i < 6; i++)
  {
    cout << name[i] << time[i] << endl;
  }
  
}

