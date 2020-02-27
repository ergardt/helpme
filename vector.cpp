#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

int getRandomNumber(int min, int max)
	{
	    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
	    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
	}

int main()
{
	int n;
	cout << "Enter n" << endl;
	cin >> n;
	vector <int> vec1(n);
	vector <int> vec2(n);
	cout << "First vector:" << endl;
	for (int i = 0; i < n; i++)
	{
		vec1[i] = getRandomNumber(-100, 100);
		cout << vec1.at(i) << " ";
	}
	cout << endl << "Second vector:" << endl;

	for (int i = 0; i < n; i++)
	{
		vec2[i] = vec1[i]*vec1[i];
		cout << vec2.at(i) << " ";
	}

	cout << endl;
	 
	vec1.clear();
	vec2.clear();
	return 0;

}
