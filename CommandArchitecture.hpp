#pragma once
#include "Task.hpp"
#include "TaskRepository.hpp"
#include <map>
#include <queue>

// This code shows how a Command object (CreateTaskCommand) can be used to encapsulate a task creation operation, 
// allowing it to be queued or logged, and supporting undoable operations.
// Clients can interact with the system by passing a Command object to a function (useCommand) that executes the command.

class Command {
public:
    virtual void Execute() = 0;

    virtual std::string Name() const = 0;
};


/////////////////////////////////////////
///////////// MAP COMMANDS //////////////
/////////////////////////////////////////


// Map command strings to command objects
std::map< std::string, std::unique_ptr<Command> > commandMap;

// Queue of commands to execute
std::queue<std::string> commandQueue;
// Register a command


void RegisterCommand(std::string command, std::unique_ptr<Command> cmd)
{
    commandMap[command] = std::move(cmd);
}

// Queue a command for execution
void QueueCommand(std::unique_ptr<Command> cmd)
{
    commandQueue.push(cmd->Name());
}

// Execute commands in the queue
void ExecuteCommands()
{
    while (!commandQueue.empty())
    {
        const std::string &commandName = commandQueue.front();
        commandQueue.pop(); 
        ExecuteCommand(commandName);
    }
}

// Execute a command
void ExecuteCommand(std::string commandName)
{
    if (commandMap.find(commandName) != commandMap.end())
    {
        // Call the Execute method on the command object
        auto cmd = std::move(commandMap[commandName]);
        cmd->Execute();
    }
    else
    {
        std::cout << "Unknown command: " << commandName << std::endl;
    }
}