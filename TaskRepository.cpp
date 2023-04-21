#pragma once

#include <fstream>
#include <sstream>
#include "TaskRepository.hpp""

const std::string fileNameDemo = "tasks.txt";


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

// Functions commonly used in this file
// Reduces code duplication
namespace
{
    inline void writeToFile(std::ofstream& outputFile, Task const& task)
    {
        outputFile << task.getTitle() << "," << task.getDueDate() << "," << task.getDueDate() << std::endl;
    }

    inline bool readFromFile(std::istringstream& iss, Task& task)
    {
        std::string title;
        bool isComplete;

        bool readFromFileAction = false;
        
        if (iss >> title >> std::boolalpha >> isComplete)
        {
            task.setTitle(title);
            //task.s(isComplete);
            readFromFileAction = true;
        } 

        return readFromFileAction;        
    }


}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

//Singleton

TaskRepository::TaskRepository(std::string pathFile)
{
    m_pathFile = pathFile;
}


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////

std::shared_ptr<TaskRepository> SQLTaskRepository::getInstance(std::string pathFile)
{
    if(m_instance == nullptr)
        m_instance = std::make_shared<SQLTaskRepository>(pathFile);

    return m_instance;
}

void SQLTaskRepository::addTask(const Task& task)
{
    // add the task to the SQL database
    std::cout << "Adding task to SQL database: " << task.getTitle() << std::endl;
 
}
   
void SQLTaskRepository::updateTask(const Task& task)
{

}

void SQLTaskRepository::deleteTask(const std::string& id)
{

}

std::vector<Task> SQLTaskRepository::getTasks() const
{

}
    
// implementation details for SQLTaskRepository

//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


std::shared_ptr<TaskRepository> FileTaskRepository::getInstance(std::string pathFile)
{
    if(m_instance == nullptr)
        m_instance = std::make_shared<FileTaskRepository>(pathFile);

    return m_instance;
}

void FileTaskRepository::addTask(const Task& task)
{
    // add the task to the file
    
    std::cout << "Adding task to file: " << task.getTitle() << std::endl;

    std::ofstream outputFile(fileNameDemo, std::ios::app);
    if (outputFile.is_open()) 
    {
        writeToFile(outputFile, task);
        outputFile.close();
        std::cout << "Added task to file: " << task.getTitle() << std::endl;
    }
    else 
    {
        std::cout << "Error opening file!" << std::endl;
    }

}
   
void FileTaskRepository::updateTask(const Task& task)
{
    std::string taskID = task.getTitle();

    std::vector<Task> tasks = getTasks();
    for (int i = 0; i < tasks.size(); i++) {
        
        if (tasks[i].getTitle() == taskID) {

            // Update old task with the new task
            tasks[i] = task;
            
            // write the new task in the database
            std::ofstream outputFile(fileNameDemo);
            
            for (const Task& task : tasks) 
            {
                writeToFile(outputFile, task);
            }
            return;
        }
    }
    throw std::runtime_error("Task not found.");

}

void FileTaskRepository::deleteTask(const std::string& taskID)
{
    std::vector<Task> tasks = getTasks();
    for (int i = 0; i < tasks.size(); i++) {
        
        if (tasks[i].getTitle() == taskID) {

            tasks.erase(tasks.begin() + i);
            std::ofstream outputFile(fileNameDemo);
            
            for (const Task& task : tasks) 
            {
                writeToFile(outputFile, task);
            }
            return;
        }
    }
    throw std::runtime_error("Task not found.");
}

std::vector<Task> FileTaskRepository::getTasks() const
{
    std::vector<Task> tasks;
    std::ifstream inputFile(fileNameDemo);
    
    if (!inputFile) 
    {
        throw std::runtime_error("Failed to open file");
    }

    std::string line;
    while (std::getline(inputFile, line))
    {
        std::istringstream iss(line);
        Task task;

        if (! (readFromFile(iss, task)) ) {

            throw std::runtime_error("Error reading task from file");
        }

        tasks.push_back(task);
    }

    return tasks;
}


// implementation details for FileTaskRepository
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////


//    Task task("Buy groceries", "2023-04-08", "10:00");

//    FileTaskRepository fileRepo;
//    fileRepo.addTask(task);