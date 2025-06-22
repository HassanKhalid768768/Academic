#include<iostream>
#include<cstring>
using namespace std;
void
Repeat (char *CH, char *CH1)
{
  cout << "Enter  string : ";
  gets (CH);
  cout << "Enter sub string : ";
  gets (CH1);
}

int
main ()
{
  int size, size1;
 
  int index;
 
  char *c1 = new char[size];
  char *c2 = new char[size];
  
  Repeat (c1, c2);
  int s1 = sizeof (c1);
  int s2 = sizeof (c2);
  for (int k = 0; k < s1; k++)
    {
      if (c1[k] == c2[0])
	{
	  index = k;
	}
      for (int j = 0; j < s2; j++)
	{
	  if (c1[k] != c2[j])
	    {
	      break;
	      cout << "entered string is not present" << endl;
	    }
	  else
	    {
	      cout << "entered string is present";
	      index++;
	    }
	}
    }
  system ("pause");
  return 0;
}
