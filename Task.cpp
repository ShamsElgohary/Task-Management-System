#include "Task.hpp"

Task::Task(const std::string& title, 
           const std::chrono::system_clock::time_point& dueDate, 
           const std::vector<std::string>& dependencies)
{
    m_title = title;
    m_dueDate = dueDate;
    m_dependencies = dependencies;
}


// Setters

void Task::setTitle(const std::string& title)
{
    m_title = title;
}

void Task::setDueDate(const std::chrono::system_clock::time_point& dueDate)
{
    m_dueDate = dueDate; 
}

void Task::setDependencies(const std::vector<std::string>& dependencies)
{
    m_dependencies = dependencies;
}

// Getters

std::string Task::getTitle() const
{
    return m_title;
}

std::vector<std::string> Task::getDependencies() const
{
    return m_dependencies;
}

std::string Task::getDueDate() const
{
    // Convert the time point to a time_t object
    std::time_t time = std::chrono::system_clock::to_time_t(m_dueDate);
    // Convert the time_t object to a string representation
    std::string time_str = std::ctime(&time);
    time_str.erase(std::remove(time_str.begin(), time_str.end(), '\n'), time_str.end());
    return time_str;
}

// other methods for task management

bool Task::isCompleted() const
{
    return m_completed;
}

void Task::complete()
{
    m_completed = true;
}

void Task::reopen()
{
    m_completed = false;
}


// For Observer Pattern

void Task::update() 
{
std::cout << "Task " << m_title << " updated" << std::endl;
}
