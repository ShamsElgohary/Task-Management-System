#pragma once
#include "CommandArchitecture.hpp"

/////////////////////////////////////////
///////////// ADD COMMANDS HERE /////////
/////////////////////////////////////////

const std::string CreateTaskStr = "CreateTask";

class CreateTaskCommand : public Command {
public:

    CreateTaskCommand(std::unique_ptr<Task> task, std::unique_ptr<TaskRepository> taskRepository);
    void Execute() override;
    std::string Name() const override;

private:
    std::unique_ptr<Task> m_task;
    std::unique_ptr<TaskRepository> m_taskRepository;
};

CreateTaskCommand::CreateTaskCommand(std::unique_ptr<Task> task, std::unique_ptr<TaskRepository> taskRepository) 
    : m_task(std::move(task)), m_taskRepository(std::move(taskRepository)) {}

void CreateTaskCommand::Execute() {
    m_taskRepository->addTask(*m_task);
}

std::string CreateTaskCommand::Name() const
{
    return CreateTaskStr;
}


// SQLTaskRepository sqlTaskRepository;
// auto task = std::make_unique<Task>();
// task->setTitle("Finish task management system");
// auto createTaskCommand = std::make_unique<CreateTaskCommand>(std::move(task), std::make_unique<SQLTaskRepository>(sqlTaskRepository));
// useCommand(*createTaskCommand); // create a task using a command object



/*
{
    // Create some command objects
    SayHelloCommand sayHelloCmd;
    SayGoodbyeCommand sayGoodbyeCmd;

    // Register some commands
    RegisterCommand("hello", &sayHelloCmd);
    RegisterCommand("goodbye", &sayGoodbyeCmd);

    // Queue some commands for execution
    QueueCommand(&sayHelloCmd);
    QueueCommand(&sayGoodbyeCmd);
    QueueCommand(&sayHelloCmd);

    // Execute the queued commands
    ExecuteCommands();

    return 0;
}

*/