#include<iostream>

using namespace std;

class Set {
  private:
    int * data = new int[capacity];
  int noOfElements;
  int capacity;

  public:

    Set(int cap = 0) {
      capacity = cap;
    }

  Set(int noe, int c) {
      noOfElements = noe;
      capacity = c;
    }

    ~Set() {
      delete data;
    }

  void insert() {
    for (int i = 0; i < noOfElements; i++) {
      cout << "ENTER DATA : ";
      cin >> data[i];
    }
  }

  int remove(int toberemoved) {
    int temp[noOfElements] = {
      0
    };
    int j = 0;

    for (int i = 0; i < noOfElements; i++) {
      if (data[i] != toberemoved) {
        temp[j] = data[i];
        j++;
      }
    }

    for (int i = 0; i < noOfElements - 1; i++) {
      data[i] = temp[i];
    }

    cout << "New Array : " << endl;
    for (int i = 0; i < noOfElements - 1; i++) {
      cout << data[i] << endl;
    }

  }

  int getCardinality() {

    cout << noOfElements - 1;
  }

  int calcUnion(Set s, Set s2) {
    int temp[s.noOfElements + s2.noOfElements], count = 0;
    for (int i = 0; i < s.noOfElements; i++) {
      temp[count] = s.data[i];
      count++;
    }

    for (int i = 0; i < s2.noOfElements; i++) {
      temp[count] = s2.data[i];
      count++;
    }

    for (int i = 0; i < s.noOfElements + s2.noOfElements; i++) {
      cout << temp[i] << " ";
    }

  }

  void calcDifference(Set s, Set s2) {

    int temp[s.noOfElements + s2.noOfElements], count = 0;
    for (int i = 0; i < s.noOfElements; i++) {
      temp[count] = s.data[i];
      count++;
    }

    for (int i = 0; i < s2.noOfElements; i++) {
      temp[count] = s2.data[i];
      count++;
    }

    int temp2[count] = {
      0
    };

    int j = 0;

    for (int i = 0; i < count - 1; i++)
      if (temp[i] != temp[i + 1])
        temp2[j++] = temp[i];

    temp2[j++] = temp[count - 1];

    for (int i = 0; i < count; i++)
      cout << temp2[i];

  }

  int isMember(Set s, int val) {
    int k = 0;
    for (int i = 0; i < s.noOfElements; i++) {
      if (val == s.data[i]) {
        k = 1;
      }
    }
    if (k == 0) {
      cout << endl << "Element is not in set";
    } else if (k == 1) {
      cout << endl << "Element is in set";
    }
  }

};

int main() {
  int NoOfElements, Data, Capacity, toberemoved, val;

  cout << "Enter Capacity of Array : ";
  cin >> Capacity;

  do {
    cout << endl << "Enter No of Elements : ";
    cin >> NoOfElements;
  } while (NoOfElements > Capacity);
  cout << endl;

  Set s(NoOfElements, Capacity);
  s.insert();
//  cout << endl << "Enter element to check in array : ";
//  cin >> val;
//  s.isMember(s, val);
//  cout << endl;

  cout << endl << "Enter data to be removed : ";
  cin >> toberemoved;
  cout << endl;
  s.remove(toberemoved);
  cout << endl;
  cout << "New number of elements in set : ";
  s.getCardinality();

  cout << endl << endl << "Enter Capacity of Array : ";
  cin >> Capacity;

  do {
    cout << endl << "Enter No of Elements : ";
    cin >> NoOfElements;
  } while (NoOfElements > Capacity);
  cout << endl;

  Set s2(NoOfElements, Capacity);
  s2.insert();
//  cout << endl << "Enter element to check in array : ";
//  cin >> val;
//  s2.isMember(s2, val);
//  cout << endl;

  cout << "Union : ";
  s.calcUnion(s, s2);
  cout << "Intersection : ";
  s.calcDifference(s, s2);

}
