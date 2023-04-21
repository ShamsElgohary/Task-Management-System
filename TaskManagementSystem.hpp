#pragma once
#include "Task.hpp"
#include "TaskRepository.hpp"


class TaskManagementSystem {
public:
    TaskManagementSystem(std::unique_ptr<TaskRepository> taskRepository);
    void createTask(const std::string& title);
    void updateTask(const Task& task);
    void deleteTask(const std::string& id);
    std::vector<Task> getTasks() const;
    void displayTasks(const std::vector<Task>& tasks);
   
private:
    std::unique_ptr<TaskRepository> m_taskRepository;
};



/*

void useTaskManagementSystem(TaskCreator& taskCreator) {
taskCreator.createTask("Finish task management system");
}

SQLTaskRepository sqlTaskRepository;
TaskManagementSystem taskManagementSystem(std::make_unique<SQLTaskRepository>(sqlTaskRepository));
useTaskManagementSystem(taskManagementSystem); // create a task using the task management system

*/