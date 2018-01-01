// https://www.acmicpc.net/problem/1406

#include <iostream>
#include <string>
#include <stack>

int main()
{
	std::ios_base::sync_with_stdio(false);

	int numOfOrder;
	char input;
	std::string origin, result = "";
	std::stack<char> left, right;

	std::cin >> origin;
	std::cin >> numOfOrder;

	for (int index = 0; index < origin.length(); index++)
	{
		left.push(origin[index]);
	}

	for (int index = 0; index < numOfOrder; index++) 
	{
		std::cin >> input;
		switch (input)
		{
		case 'L' :
			if (!left.empty())
			{
				right.push(left.top());
				left.pop();
			}
			break;
		case 'D' :
			if (!right.empty())
			{
				left.push(right.top());
				right.pop();
			}
			break;
		case 'B' :
			if (!left.empty())
			{
				left.pop();
			}
			break;
		case 'P' :
			std::cin >> input;
			left.push(input);
			break;
		}
	}

	while (!left.empty())
	{
		right.push(left.top());
		left.pop();
	}

	while (!right.empty())
	{
		result += right.top();
		right.pop();
	}

	std::cout << result << std::endl;

	return 0;
}