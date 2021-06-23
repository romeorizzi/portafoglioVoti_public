/**
* user:  VR457796_id572ecb
* fname: FRANCESCO
* lname: CECCONELLO
* task:  hanoi_with_toddler
* score: 30.0
* date:  2021-06-22 10:15:28.131389
*/
#include <iostream>
using namespace std;
int conteggio = 0;


void rec_hanoi(int num_disks, int type, char inizio, char ausiliario, char fine)
{
  if (type == 1) {
    if (num_disks == 1)
    {
      cout << "daddy " << "muove il disco " << num_disks << " dal piolo " << inizio << " al piolo " << fine << endl;
      return;
    }

    rec_hanoi(num_disks - 1, type, inizio, fine, ausiliario);
    cout << "toddler " << "muove il disco " << num_disks << " dal piolo " << inizio << " al piolo " << fine << endl;
    rec_hanoi(num_disks - 1, type, ausiliario, inizio, fine);
  }
  else {
    if (num_disks == 1)
    {
      conteggio++;
      return;
    }

    rec_hanoi(num_disks - 1, type, inizio, fine, ausiliario);
    conteggio++;
    rec_hanoi(num_disks - 1, type, ausiliario, inizio, fine);
  }
}


int main()
{
  int type;
  int num_disks;
  cin >> type >> num_disks;
  rec_hanoi(num_disks, type, 'A', 'C', 'B');
  if (type == 0){
    cout << conteggio << endl;
  }
  return 0;
}