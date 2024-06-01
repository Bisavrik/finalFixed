#ifdef INTEGER
#define Task
#define addTask
#define showTask
#define deleteTask
#define editTask
#define showAllTask
#define searchByName
#define searchByPriority
#define searchByDescription
#define searchByDateTime
#define showForDay
#define showForWeek
#define showForMonth
#define sortByPriority
#define compareDateTime
#define sortByDateTime
#endif

struct Task;
void addTask(Task& task);
void showTask(Task& task);
void deleteTask(Task* listTask, int& quantity);
void editTask(Task& task);
void showAllTask(Task* listTask, int quantity);
Task* searchByName(Task* listTask, int quantity, char* findName);
Task* searchByPriority(Task* listTask, int quantity);
Task* searchByDescription(Task* listTask, int quantity, char* findDescription);
Task* searchByDateTime(Task* listTask, int quantity);
void showForDay(Task* listTask, int year, int month, int day, int quantity);
void showForWeek(Task* listTask, int year, int month, int startDay, int quantity);
void showForMonth(Task* listTask, int year, int month, int quantity);
void sortByPriority(Task* listTask, int quantity);
int compareDateTime(Task& a, Task& b);
void sortByDateTime(Task* listTask, int quantity);

