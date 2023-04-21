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