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