#include <iostream>
#include <cstring>
#include "HeaderFinal.h"
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

void addTask(Task& task)
{

	char* name = new char[255];
	cout << "Enter name: ";
	cin >> name;
	int size1 = strlen(name);
	task.name = new char[size1 + 1];
	strcpy(task.name, name);

	cout << "Enter priority: ";
	cin >> task.priority;

	char* description = new char[255];
	cout << "Enter description: ";
	cin >> description;
	int size2 = strlen(description);
	task.description = new char[size2 + 1];
	strcpy(task.description, description);

	cout << "Enter date and time: " << endl;
	cout << "Year: ";
	cin >> task.year;
	bool validMonth = false;
	while (!validMonth)
	{
		cout << "Month: ";
		cin >> task.month;
		if (task.month >= 1 && task.month <= 12)
		{
			validMonth = true;
		}
		else
		{
			cout << "Invalid month. Please enter a month between 1 and 12." << endl;
		}
	}

	bool validDay = false;
	while (!validDay)
	{
		cout << "Day: ";
		cin >> task.day;

		if ((task.month == 1 || task.month == 3 || task.month == 5 || task.month == 7 || task.month == 8 || task.month == 10 || task.month == 12) && (task.day >= 1 && task.day <= 31))
		{
			validDay = true;
		}
		else if ((task.month == 4 || task.month == 6 || task.month == 9 || task.month == 11) && (task.day >= 1 && task.day <= 30))
		{
			validDay = true;
		}
		else if (task.month == 2)
		{
			bool leapYear = (task.year % 4 == 0 && task.year % 100 != 0) || (task.year % 400 == 0);
			if ((leapYear && task.day >= 1 && task.day <= 29) || (!leapYear && task.day >= 1 && task.day <= 28))
			{
				validDay = true;
			}
			else {
				cout << "Invalid day for February. ";
				if (leapYear)
				{
					cout << "February in a leap year can have 29 days." << endl;
				}
				else
				{
					cout << "February can have 28 days." << endl;
				}
			}
		}
		else
		{
			cout << "Invalid day. Please enter a valid day for the given month." << endl;
		}
	}
	bool validHour = false;
	while (!validHour)
	{
		cout << "Hour: ";
		cin >> task.hour;
		if (task.hour >= 0 && task.hour <= 23)
		{
			validHour = true;
		}
		else
		{
			cout << "Invalid hour. Please enter an hour between 0 and 23." << endl;
		}
	}

	bool validMinute = false;
	while (!validMinute)
	{
		cout << "Minute: ";
		cin >> task.minute;
		if (task.minute >= 0 && task.minute <= 59)
		{
			validMinute = true;
		}
		else
		{
			cout << "Invalid minute. Please enter minutes between 0 and 59." << endl;
		}
	}

	delete[] name;
	delete[] description;


}

void showTask(Task& task)
{
	cout << "Name: " << task.name << endl;
	cout << "Priority: " << task.priority << endl;
	cout << "Description: " << task.description << endl;
	cout << "Date and time: " << task.year << "-" << task.month << "-" << task.day << " " << task.hour << ":" << task.minute << endl;
}

void deleteTask(Task* listTask, int& quantity)
{
	char name[225];

	cout << " Enter task that you want to delete: " << endl;
	cout << "Name: ";
	cin >> name;

	for (int i = 0; i < quantity; i++)
	{
		if (strcmp(listTask[i].name, name) == 0)
		{
			delete[] listTask[i].name;
			delete[] listTask[i].description;
			for (int j = i; j < quantity - 1; j++)
			{
				listTask[j] = listTask[j + 1];
			}
			--quantity;
			cout << "Task delete." << endl;
			return;
		}
	}
	cout << "Task not found." << endl;
}

void editTask(Task& task)
{
	char* name = new char[225];
	cout << "Enter new name: ";
	cin >> name;
	int size = strlen(name);
	delete[] task.name;
	task.name = new char[size + 1];
	strcpy(task.name, name);

	cout << "Enter new priority: ";
	cin >> task.priority;

	char* description = new char[225];
	cout << "Enter description name: ";
	cin >> description;
	int size1 = strlen(description);
	delete[] task.description;
	task.description = new char[size1 + 1];
	strcpy(task.description, description);

	cout << "Enter new date: " << endl;
	cout << "Year: ";
	cin >> task.year;
	bool validMonth = false;
	while (!validMonth)
	{
		cout << "Month: ";
		cin >> task.month;
		if (task.month >= 1 && task.month <= 12)
		{
			validMonth = true;
		}
		else
		{
			cout << "Invalid month. Please enter a month between 1 and 12." << endl;
		}
	}

	bool validDay = false;
	while (!validDay)
	{
		cout << "Day: ";
		cin >> task.day;

		if ((task.month == 1 || task.month == 3 || task.month == 5 || task.month == 7 || task.month == 8 || task.month == 10 || task.month == 12) && (task.day >= 1 && task.day <= 31))
		{
			validDay = true;
		}
		else if ((task.month == 4 || task.month == 6 || task.month == 9 || task.month == 11) && (task.day >= 1 && task.day <= 30))
		{
			validDay = true;
		}
		else if (task.month == 2)
		{
			bool leapYear = (task.year % 4 == 0 && task.year % 100 != 0) || (task.year % 400 == 0);
			if ((leapYear && task.day >= 1 && task.day <= 29) || (!leapYear && task.day >= 1 && task.day <= 28))
			{
				validDay = true;
			}
			else
			{
				cout << "Invalid day for February. ";
				if (leapYear)
				{
					cout << "February in a leap year can have 29 days." << endl;
				}
				else
				{
					cout << "February can have 28 days." << endl;
				}
			}
		}
		else
		{
			cout << "Invalid day. Please enter a valid day for the given month." << endl;
		}
	}

	bool validHour = false;
	while (!validHour)
	{
		cout << "Hour: ";
		cin >> task.hour;
		if (task.hour >= 0 && task.hour <= 23)
		{
			validHour = true;
		}
		else {
			cout << "Invalid hour. Please enter an hour between 0 and 23." << endl;
		}
	}

	bool validMinute = false;
	while (!validMinute)
	{
		cout << "Minute: ";
		cin >> task.minute;
		if (task.minute >= 0 && task.minute <= 59)
		{
			validMinute = true;
		}
		else
		{
			cout << "Invalid minute. Please enter minutes between 0 and 59." << endl;
		}
	}

}

void showAllTask(Task* listTask, int quantity)
{
	for (int i = 0; i < quantity; i++)
	{
		cout << "Task " << i + 1 << ":" << endl;
		showTask(listTask[i]);
	}
}

Task* searchByName(Task* listTask, int quantity, char* findName)
{
	for (int i = 0; i < quantity; i++)
	{
		if (strcmp(findName, listTask[i].name) == 0)
		{
			return &listTask[i];
		}
	}
	return nullptr;
}

Task* searchByPriority(Task* listTask, int quantity)
{
	int priority;
	cout << "Enter priority to search: ";
	cin >> priority;

	bool found = false;
	for (int i = 0; i < quantity; i++)
	{
		if (listTask[i].priority == priority)
		{
			showTask(listTask[i]);
			found = true;
			return &listTask[i];
		}
	}
	if (!found)
	{
		cout << "No tasks found with priority " << priority << "." << endl;
	}
}

Task* searchByDescription(Task* listTask, int quantity, char* findDescription)
{
	for (int i = 0; i < quantity; i++)
	{
		if (strcmp(findDescription, listTask[i].description) == 0)
		{
			return &listTask[i];
		}
	}
	return nullptr;
}

Task* searchByDateTime(Task* listTask, int quantity)
{
	int year, month, day, hour, minute;
	cout << "Enter date and time to search: ";
	cout << "Year: ";
	cin >> year;
	cout << "Month: ";
	cin >> month;
	cout << "Day: ";
	cin >> day;
	cout << "Hour: ";
	cin >> hour;
	cout << "Minute: ";
	cin >> minute;

	for (int i = 0; i < quantity; i++)
	{
		if (listTask[i].year == year && listTask[i].month == month && listTask[i].day == day && listTask[i].hour == hour && listTask[i].minute == minute)
		{
			showTask(listTask[i]);
			return &listTask[i];
		}
	}

}

void showForDay(Task* listTask, int year, int month, int day, int quantity)
{
	bool found = false;
	for (int i = 0; i < quantity; i++)
	{
		if (listTask[i].year == year && listTask[i].month == month && listTask[i].day == day)
		{
			showTask(listTask[i]);
			found = true;
		}
	}
	if (!found)
	{
		cout << "No tasks found for the specified day." << endl;
	}
}

void showForWeek(Task* listTask, int year, int month, int startDay, int quantity)
{
	bool found = false;
	for (int i = 0; i < quantity; ++i)
	{
		if (listTask[i].year == year && listTask[i].month == month &&
			listTask[i].day >= startDay && listTask[i].day < startDay + 7)
		{
			showTask(listTask[i]);
			found = true;
		}
	}
	if (!found)
	{
		cout << "No tasks found for the specified week." << endl;
	}
}

void showForMonth(Task* listTask, int year, int month, int quantity)
{
	bool found = false;
	for (int i = 0; i < quantity; ++i)
	{
		if (listTask[i].year == year && listTask[i].month == month)
		{
			showTask(listTask[i]);
			found = true;
		}
	}
	if (!found)
	{
		cout << "No tasks found for the specified month." << endl;
	}
}

void sortByPriority(Task* listTask, int quantity)
{
	for (int i = 0; i < quantity - 1; ++i)
	{
		for (int j = 0; j < quantity - i - 1; ++j)
		{
			if (listTask[j].priority > listTask[j + 1].priority)
			{
				Task temp = listTask[j];
				listTask[j] = listTask[j + 1];
				listTask[j + 1] = temp;
			}
		}
	}
	showAllTask(listTask, quantity);
}

int compareDateTime(Task& a, Task& b)
{
	if (a.year != b.year)
	{
		return a.year - b.year;
	}
	if (a.month != b.month)
	{
		return a.month - b.month;
	}
	if (a.day != b.day)
	{
		return a.day - b.day;
	}
	if (a.hour != b.hour)
	{
		return a.hour - b.hour;
		return a.minute - b.minute;
	}
}

void sortByDateTime(Task* listTask, int quantity)
{
	for (int i = 0; i < quantity - 1; ++i)
	{
		for (int j = 0; j < quantity - i - 1; ++j)
		{
			if (compareDateTime(listTask[j], listTask[j + 1]) > 0)
			{
				Task temp = listTask[j];
				listTask[j] = listTask[j + 1];
				listTask[j + 1] = temp;
			}
		}
	}
	showAllTask(listTask, quantity);
}
