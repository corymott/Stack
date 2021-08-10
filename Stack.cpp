#include<iostream>
#include<string>
#include<fstream>

class Stack 
{
private:
	int top;
	int arr[5];

public:
	Stack() 
	{
		top = -1;

		for (int i = 0; i < 5; i++)
		{
			arr[i] = 0;
		}
	}

	bool isEmpty()
	{
		if (top == -1)
		{
			return true;
		} else { return false; }
	}

	bool isFull()
	{
		if (top == 4)
		{
			return true;
		} else { return false; }
	}

	void push(int value)
	{
		if (isFull())
		{
			std::cerr << "Unable to push, stack is full." << std::endl;
		}
		else
		{
			top++;
			arr[top] = value;
		}
	}

	int pop()
	{
		if (isEmpty())
		{
			std::cerr << "Unable to pop, stack is empty." << std::endl;
		}
		else
		{
			int popValue = arr[top];
			arr[top] = 0;
			top--;

			return popValue;
		}
	}

	int count()
	{
		int total = 0;

		for (int i = 0; i < 5; i++)
		{
			if (arr[i] != 0) total++;
		}

		return total;
	}

	int peek(int pos)
	{
		if (isEmpty())
		{
			std::cerr << "No data available, stack is empty." << std::endl;
			return 0;
		} else { return arr[pos]; }
	}

	void change(int pos, int value)
	{
		arr[pos] = value;

		std::cout << "Value changed at" << pos << std::endl;
	}

	void display()
	{
		std::cout << "Displaying stack values:" << std::endl;

		for (int i = 4; i >= 0; i--)
		{
			std::cout << arr[i] << std::endl;
		}
	}

	void output()
	{
		std::string fileName;

		std::cout << "Enter the full file name that you would like to export to (must end in .txt): ";
		std::cin >> fileName;
		std::cout << std::endl;

		std::ofstream output;

		output.open(fileName);

		if (output.fail())
		{
			std::cerr << "Could not open file " << fileName << ". Output failed." << std::endl;
		}
		else
		{
			output << "Stack output: " << std::endl << std::endl;

			for (int i = 4; i >= 0; i--)
			{
				output << arr[i] << std::endl;
			}

			std::cout << "Output succesful." << std::endl;
		}
	}
};

int main()
{
	Stack st1;

	int menuReturn;

	int operationMenu(Stack &st);

	do
	{
		menuReturn = operationMenu(st1);
	} while (menuReturn != 0);

	std::cout << "Stack interface complete. Ending program.";

	return 0;
}

int operationMenu(Stack &st)
{
	int option, pos, value;

	std::cout << "Please select the operation you would like to perform:" << std::endl;
	std::cout << "(1) Push" << std::endl << "(2) Pop" << std::endl;
	std::cout << "(3) isEmpty()" << std::endl << "(4) isFull()" << std::endl;
	std::cout << "(5) peek()" << std::endl << "(6) count()" << std::endl;
	std::cout << "(7) change()" << std::endl << "(8) display()" << std::endl;
	std::cout << "(9) Clear Screen" << std::endl << "(10) Output stack to a file" << std::endl;
	std::cout << "(0) Exit Program" << std::endl;

	std::cin >> option;

	switch (option) 
	{
	case 0: 
		break;

	case 1:
		std::cout << "Enter the value that you would like to add to the stack: ";
		std::cin >> value;
		std::cout << std::endl;

		st.push(value);

		break;
	case 2:
		std::cout << "Popping top value." << std::endl;
		st.pop();

		break;

	case 3:
		if (st.isEmpty())
		{
			std::cout << "Stack is empty." << std::endl;
		}
		else
		{
			std::cout << "Stack is NOT empty." << std::endl;
		}

		break;

	case 4:
		if (st.isFull())
		{
			std::cout << "Stack is full." << std::endl;
		}
		else
		{
			std::cout << "Stack is NOT full." << std::endl;
		}

		break;

	case 5:
		std::cout << "Enter the position of the stack you would like to view (0 -> 4): ";
		std::cin >> pos;
		std::cout << std::endl;

		if (pos <= 4 && pos >= 0)
		{
			st.peek(pos);
		}
		else
		{
			std::cerr << "The value " << pos << "is not within the acceptable range. Returning to main menu.";
			break;
		}

		break;

	case 6:
		st.count();

		break;

	case 7 :
		std::cout << "Enter the position of the stack you would like to modify (0 -> 4): ";
		std::cin >> pos;
		std::cout << std::endl;

		if (pos <= 4 && pos >= 0)
		{
			std::cout << "Enter the value you would like to place in this position: ";
			std::cin >> value;
			std::cout << std::endl;

			st.change(pos, value);
		}
		else
		{
			std::cerr << "The value " << pos << "is not within the acceptable range. Returning to main menu." << std::endl << std::endl;
			break;
		}

		break;

	case 8:
		st.display();

		break;

	case 9 :
		system("cls");

		break;

	case 10:
		st.output();

		break;

	default:
		std::cout << "Enter proper option." << std::endl;

		break;

	}

	std::cout << std::endl << std::endl;

	return option;

}