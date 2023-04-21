#pragma once
#include "Task.hpp"

// This code demonstrates how the Decorator pattern can be used to add additional behavior to an object without modifying its interface. 
// The base class (Task) defines the basic functionality, 
// while the decorator classes (TaskDecorator and its subclass RecurringTaskDecorator) wrap the base class to add new behavior.


class TaskDecorator : public Task {
public:
    TaskDecorator(std::unique_ptr<Task> task): m_task(std::move(task)) {}
    
    std::string getTitle() const override
    {
        return m_task->getTitle();
    }
protected:
    std::unique_ptr<Task> m_task;
};


class RecurringTaskDecorator : public TaskDecorator {

public:
    RecurringTaskDecorator(std::unique_ptr<Task> task) : TaskDecorator(std::move(task)) {}

    
    std::string getTitle() const override
    {
        return m_task->getTitle() + " (Recurring)";
    }
};



// auto simpleTask = std::make_unique<Task>("Finish task management system");
// auto recurringTask = std::make_unique<RecurringTaskDecorator>(std::move(simpleTask));
// std::cout << recurringTask->getTitle();      
// outputs "Finish task management system (Recurring)"
