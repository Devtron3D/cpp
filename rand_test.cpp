
/*
	testing a use of vector and the rand function
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;



int number();
void check(vector<int>& count, vector<int>& num, int& ínput);
void display(vector<int>& count, vector<int>& num);

int main()
{

	vector<int> count;
	vector<int> num;

	srand(static_cast<unsigned int>(time(0)));

	int large = 0;
	int small = 0;
	int temp = 0;

	for (double i = 0; i < 1000; ++i)
	{
		temp = number();

		if (i == 0)
		{
			small = temp;
			large = temp;
		}


		if (temp <= small)
		{
			small = temp;
		}
		else
		if (temp >= large)
		{
			large = temp;
		}
		
		check(count, num, temp);
	}



	cout << endl << "small: " << small << endl;
	cout << "large: " << large << endl;
	cout << count.size() << endl;
	display(count, num);

	system("pause");
}


int number()
{
	  //seed random number generator

	int secretNumber = rand() % 10;  // random number between 1 and 100


	//cout << secretNumber << endl;
	return (secretNumber);
}

void check(vector<int>& count, vector<int>& num, int& input)
{
	typedef vector<int>::size_type vec_sz;

	vec_sz size = num.size();
	

	// do a check if the vector is 0,then input something
	int zero = 0;

	if (size == zero)
	{
		int one = 1;
		count.push_back(one);
		num.push_back(input);
	}
	else
	{
		// add more to the vectors
		for (vec_sz i = 0; i < size; ++i)
		{
			if (input == num[i])
			{
				++count[i];
				break;
			}
			else
			if (i == size -1 && input != num[i] )
			{
				int one = 1;
				count.push_back(one);
				num.push_back(input);

			}
		}
	}
}

void display(vector<int>& count, vector<int>& num)
{
	cout << endl;

	typedef vector<int>::size_type vec_sz;
	vec_sz size = num.size();

	for (vec_sz i = 0; i < size; ++i)
	{
		cout << num[i] << " : " << count[i] << endl;

	}

	cout << endl;


}