#pragma once
#include "Task.hpp"

// Liskov Substitution Principle (LSP)
// (RecurringTask) can be substituted for their base types (Task) and be treated as instances of their base type.

class RecurringTask : public Task {
public:
    void setFrequency(const std::string& frequency);
    std::string getFrequency() const;
    // other methods for recurring task management
private:
    std::string m_frequency;
};

void processTask(const Task& task) {
    // do something with the task
    Task task;
    RecurringTask recurringTask;
    processTask(task); // valid
    processTask(recurringTask); // valid

}



/*
int main(int argc, char* argv[])
{
    vector<Task> tasks = {
        Task("Buy milk", 2),
        Task("Pay bills", 1),
        Task("Clean house", 3),
        Task("Do laundry", 2),
        Task("Wash dishes", 3),
    };

    if (argc > 1) {
        int priorityFilter = atoi(argv[1]);
        filterTasksByPriority(tasks, priorityFilter);
    }
    else {
        displayTasks(tasks);
    }

    return 0;
}

*/