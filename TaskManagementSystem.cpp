#pragma once
#include "Task.hpp"
#include "TaskManagementSystem.hpp"


TaskManagementSystem::TaskManagementSystem(std::unique_ptr<TaskRepository> taskRepository)
{
    this->m_taskRepository = std::move(taskRepository);
}

void TaskManagementSystem::createTask(const std::string& title)
{
    std::string t = title;
    Task inputTask(title);
    m_taskRepository->addTask(inputTask);
}

void TaskManagementSystem::updateTask(const Task& task)
{
    m_taskRepository->updateTask(task);    
}

void TaskManagementSystem::deleteTask(const std::string& id)
{
    m_taskRepository->deleteTask(id);
}

std::vector<Task> TaskManagementSystem::getTasks() const
{
    m_taskRepository->getTasks();
}

void TaskManagementSystem::displayTasks(const std::vector<Task>& tasks)
{
    std::vector<Task> sortedTasks(tasks);
    std::sort(sortedTasks.begin(), sortedTasks.end(), [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
    });

    for (const Task& task : sortedTasks) {
        std::cout << "[" << (task.isCompleted() ? "X" : " ") << "] "
             << task.getPriority() << " - " << task.getTitle() << std::endl;
    }
}
