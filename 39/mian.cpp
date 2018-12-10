#include <iostream>
#include <vector>
using namespace std;

bool InputVaild = false;
class Solution {
public:
	//检测输入是否为空
	bool CheckInput(vector<int> num)
	{
		InputVaild = false;
		if (num.empty() || num.size() <= 0)
			InputVaild = true;
		return InputVaild;
	}
	//检测出现最多的数字是否超过数组一半
	bool CheckMoreThanHalf(vector<int> num, int val)
	{
		size_t time = 0;
		for (size_t i = 0; i < num.size(); ++i)
		{
			if (num[i] == val)
			{
				++time;
			}
		}
		if (time * 2 <= num.size())
		{
			InputVaild = true;
			return false;
		}
		return true;

	}
	int MoreThanHalfNum_Solution(vector<int> numbers) {
		if (numbers.empty())
			return 0;
		int time = 1;
		int val = numbers[0];
		for (size_t i = 1; i < numbers.size(); i++)
		{
			if (time == 0)
			{
				val = numbers[i];
				time = 1;
			}
			else if (numbers[i] == val)
				time++;
			else
				time--;
		}
		if (!CheckMoreThanHalf(numbers, val))
			val = 0;
		return val;
	}
};
int main()
{
	Solution s;
	vector<int> v= { 1,2,3,2,2,2,5,4,2 };
	s.MoreThanHalfNum_Solution(v);
	return 0;
}