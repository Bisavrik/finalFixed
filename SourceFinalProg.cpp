#include <iostream>
#include <cstring>
#include "HeaderFinal.h"
#define INTEGER
#pragma warning(disable : 4996)

using namespace std;

struct Task
{
	char* name;
	int priority;
	char* description;
	int year;
	int month;
	int day;
	int hour;
	int minute;
};

int main()
{
	cout << "How many tasks do you want: ";
	int quantity;
	cin >> quantity;

	Task* listTask = new Task[quantity];

	for (int i = 0; i < quantity; i++)
	{
		cout << "Enter task " << i + 1 << ":" << endl;
		addTask(listTask[i]);
	}

	const int maxSize = 100;

	while (true)
	{
		cout << "Options: " << endl;
		cout << "1. Add new tasks." << endl;
		cout << "2. Delete tasks." << endl;
		cout << "3. Edit tasks." << endl;
		cout << "4. Show all tasks." << endl;
		cout << "5. Search by name." << endl;
		cout << "6. Search by priority." << endl;
		cout << "7. Search by description." << endl;
		cout << "8. Search by date and time." << endl;
		cout << "9. Show tasks for day." << endl;
		cout << "10. Show tasks for week." << endl;
		cout << "11. Show tasks for month." << endl;
		cout << "12. Sort by priority." << endl;
		cout << "13. Sort by date and time." << endl;
		cout << "14. Exit." << endl;
		cout << "Choose option: ";

		int option;
		cin >> option;

		switch (option)
		{
		case 1:
		{
			if (quantity < maxSize)
			{
				Task* temp = new Task[quantity + 1];
				for (int i = 0; i < quantity; i++)
				{
					temp[i] = listTask[i];
				}
				delete[] listTask;
				listTask = temp;
				cout << "Enter new task:" << endl;
				addTask(listTask[quantity]);
				++quantity;

			}
			else
			{
				cout << "Max size of tasks." << endl;
			}
		}
		break;
		case 2:
			deleteTask(listTask, quantity);
			break;
		case 3:
		{
			cout << "Enter index of task to change: ";
			int index;
			cin >> index;
			if (index >= 0 && index < quantity)
			{
				cout << "Enter new data for task " << index + 1 << ":" << endl;
				editTask(listTask[index]);
			}

		}
		break;
		case 4:
			showAllTask(listTask, quantity);
			break;
		case 5:
		{
			char findName[225];
			cout << "Enter name for search: ";
			cin >> findName;
			Task* task = searchByName(listTask, quantity, findName);
			if (task != nullptr)
			{
				showTask(*task);
			}
			else
			{
				cout << "Task not found." << endl;
			}
		}
		break;
		case 6:
			searchByPriority(listTask, quantity);
			break;
		case 7:
		{
			char findDescription[225];
			cout << "Enter description for search: ";
			cin >> findDescription;
			Task* task = searchByDescription(listTask, quantity, findDescription);
			if (task != nullptr)
			{
				showTask(*task);
			}
			else
			{
				cout << "Task not found." << endl;
			}
		}
		break;
		case 8:
			searchByDateTime(listTask, quantity);
			break;
		case 9:
		{
			int year, month, day;
			cout << "Enter year: ";
			cin >> year;
			cout << "Enter month: ";
			cin >> month;
			cout << "Enter day: ";
			cin >> day;
			cout << "Tasks for day: " << endl;
			showForDay(listTask, year, month, day, quantity);
		}
		break;
		case 10:
		{
			int year, month, startDay;
			cout << "Enter year: ";
			cin >> year;
			cout << "Enter month: ";
			cin >> month;
			cout << "Enter start day of the week: ";
			cin >> startDay;
			cout << "Tasks for week: " << endl;
			showForWeek(listTask, year, month, startDay, quantity);
		}
		break;
		case 11:
		{
			int year, month;
			cout << "Enter year: ";
			cin >> year;
			cout << "Enter month: ";
			cin >> month;
			cout << "Tasks for month: " << endl;
			showForMonth(listTask, year, month, quantity);
		}
		break;
		case 12:
		{
			cout << "Sorted by priority: " << endl;
			sortByPriority(listTask, quantity);
		}
		break;
		case 13:
		{
			cout << "Sorted by date and time: " << endl;
			sortByDateTime(listTask, quantity);
		}
		break;
		case 14:
		{
			cout << "Exiting program." << endl;
			for (int i = 0; i < quantity; i++)
			{
				delete[] listTask[i].name;
				delete[] listTask[i].description;
			}
			delete[] listTask;
			return 0;
		}

		default:
			cout << "Invalid option. Please try again." << endl;
			break;
		}
	}
	return 0;
}
