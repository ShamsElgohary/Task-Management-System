#pragma once

#include "Task.hpp"

//////////////////////////////////////////////////////////////////////////////////////////////
// Interface Segregation Principle (ISP)
//////////////////////////////////////////////////////////////////////////////////////////////

class TaskCreator {
public:
    virtual void addTask(const Task& task) = 0;
};

class TaskUpdater {
public:
    virtual void updateTask(const Task& task) = 0;
};

class TaskDeleter {
public:
    virtual void deleteTask(const std::string& id) = 0;
};

class TaskReader {
public:
    virtual std::vector<Task> getTasks() const = 0;
};


//////////////////////////////////////////////////////////////////////////////////////////////
// Open/Closed Principle (OCP)
// This code demonstrates the use of abstractions (TaskRepository) to define the behavior of the system,
// and allowing concrete implementations (SQLTaskRepository and FileTaskRepository) to be swapped out as needed.
//////////////////////////////////////////////////////////////////////////////////////////////


class TaskRepository {

public:

    TaskRepository(std::string pathFile);
    virtual void addTask(const Task& task) = 0;
    virtual void updateTask(const Task& task) = 0;
    virtual void deleteTask(const std::string& id) = 0;
    virtual std::vector<Task> getTasks() const = 0;
    virtual ~TaskRepository() {};

protected:
    //Singleton
    static std::shared_ptr<TaskRepository> m_instance;
    static std::string m_pathFile;
};

class SQLTaskRepository : public TaskRepository {
public:

    void addTask(const Task& task) override;
    void updateTask(const Task& task) override;
    void deleteTask(const std::string& id) override;
    std::vector<Task> getTasks() const override;
    // implementation details for SQLTaskRepository

    using TaskRepository::TaskRepository;
    // Inherited
    // TaskRepository(std::string pathFile);
    // std::shared_ptr<TaskRepository> m_instance;
    // std::string m_pathFile;
};

class FileTaskRepository : public TaskRepository {
public:

    void addTask(const Task& task) override;
    void updateTask(const Task& task) override;
    void deleteTask(const std::string& id) override;
    std::vector<Task> getTasks() const override;
    // implementation details for FileTaskRepository

    using TaskRepository::TaskRepository;
    // Inherited
    // TaskRepository(std::string pathFile);
    // std::shared_ptr<TaskRepository> m_instance;
    // std::string m_pathFile;
};



//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////// FACTORY FOR THE REPOS ///////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


class TaskRepositoryFactory
{
public:
    virtual std::shared_ptr<TaskRepository> createTaskRepository(std::string pathFile) = 0;
    virtual ~TaskRepositoryFactory() {};
};


class SQLRepositoryFactory : public TaskRepositoryFactory
{
public:
    std::shared_ptr<TaskRepository> createTaskRepository(std::string pathFile) override
    {
        return std::make_shared<SQLTaskRepository>(pathFile);
    }
};


class FileRepositoryFactory : public TaskRepositoryFactory
{
public:
    std::shared_ptr<TaskRepository> createTaskRepository(std::string pathFile) override
    {
        return std::make_shared<FileTaskRepository>(pathFile);
    }
};


/*

int main() {
    // Create a ConcreteTaskCreatorA and create a ConcreteTaskA
    std::unique_ptr<TaskCreator> taskCreatorA = std::make_unique<ConcreteTaskCreatorA>();
    std::unique_ptr<Task> taskA = taskCreatorA->createTask();
    std::cout << taskA->getName() << std::endl;
    taskA->execute();

    // Create a ConcreteTaskCreatorB and create a ConcreteTaskB
    std::unique_ptr<TaskCreator> taskCreatorB = std::make_unique<ConcreteTaskCreatorB>();
    std::unique_ptr<Task> taskB = taskCreatorB->createTask();
    std::cout << taskB->getName() << std::endl;
    taskB->execute();

    return 0;
}

*/