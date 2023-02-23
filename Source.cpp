#include <iostream>
using namespace std;

struct item {
	string task;
	int priority;
};

int listSize = -1;
item taskList[1000];

void addTask(string task, int priority) {
	listSize++;
	taskList[listSize].task = task;
	taskList[listSize].priority = priority;

	cout << task << endl;
}

int topTask() {
	int highestPriority = INT_MIN;
	int i = -1;

	for (int j = 0; j <= listSize; j++) {

		if (highestPriority < taskList[j].priority) {
			highestPriority = taskList[j].priority;
			i = j;
		}
	}
	return i;
}

void deleteTask() {
	int i = topTask();

	for (int j = i; j < listSize; j++) {
		taskList[j] = taskList[j + 1];
	}
	listSize--;
}

int main() {
	cout << "Tasks: \n\n";

	//insering tasks to the queue with priority
	addTask("do homework", 2);
	addTask("reading 10 pages", 3);
	addTask("cleaning", 1);

	deleteTask(); //deleting top element(with biggest priority - 3), so now top will be task with priority 2

	int i = topTask();
	cout << " \nTask with biggest priority: " << taskList[i].task << endl; 

}