// https://www.acmicpc.net/problem/10799

#include <iostream>
#include <stack>
#include <string>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int result = 0;
	std::string inputData;
	std::stack<int> myStack;

	std::cin >> inputData;

	for (int check = 0; check < inputData.length(); check++)
	{
		if (inputData[check] == '(')
		{
			myStack.push(check);
		}
		else if (inputData[check] == ')')
		{
			if (myStack.top() + 1 == check)
			{
				result += myStack.size() - 1;
			}
			else
			{
				result++;
			}
			myStack.pop();
		}
	}

	std::cout << result << std::endl;
	return 0;
}