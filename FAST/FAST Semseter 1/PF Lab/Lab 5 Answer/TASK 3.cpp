#include <iostream>
using namespace std;
int main()
{
    const float CalorieBurntPerMin = 3.6;

    float CaloriesBurned = 0;

    for (int i = 5; i <= 30; i += 5)
    {
        CaloriesBurned = (i * CalorieBurntPerMin);

        cout << "Calories burned after " << i << " minutes = "<<CaloriesBurned<<endl;
    }
return 0;
}