#pragma once

#include <chrono>
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>
#include <ctime>
#include "Observer.hpp"

// Single Responsibility Principle (SRP)
// This Task class has a single responsibility of representing a single task. 
// It has methods for setting and getting the title, due date, and dependencies of a task.

class Task {
public:

    Task(const std::string& title,
         const std::chrono::system_clock::time_point& dueDate = std::chrono::system_clock::time_point(),
         const std::vector<std::string>& dependencies = std::vector<std::string>());

    Task(std::string description, int priority, bool completed = false);

    Task() = default;
    
    // Setters

    void setTitle(const std::string& title);
    void setDueDate(const std::chrono::system_clock::time_point& dueDate);
    void setDependencies(const std::vector<std::string>& dependencies);

    // Getters

    virtual std::string getTitle() const;
    std::vector<std::string> getDependencies() const;
    std::string getDueDate() const;
    int getPriority() const;

    // Other Methods for Task Management

    bool isCompleted() const;
    void complete();
    void reopen();

    // For Observer Pattern
    void update();

private:

    int m_priority;
    bool m_completed = false;
    std::string m_title;
    std::string m_description;
    std::chrono::system_clock::time_point m_dueDate;
    std::vector<std::string> m_dependencies;
};