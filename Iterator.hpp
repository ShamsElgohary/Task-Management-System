#pragma once
#include "Task.hpp"

// This code demonstrates how the Iterator pattern can be used to provide a way to traverse a collection of objects without exposing its internal representation. 
// The TaskCollection class provides an interface for creating an iterator
// While the SimpleTaskCollection class implements it to return a SimpleTaskIterator object.
// The iterator class keeps track of the current position in the collection and provides methods for checking if there are more elements and returning the next element.

class TaskIterator {
public:
    virtual bool hasNext() const = 0;
    virtual Task& next() = 0;
    virtual ~TaskIterator() = default;
};

class TaskCollection {
public:
    virtual std::unique_ptr<TaskIterator> createIterator() = 0;
    virtual ~TaskCollection() = default;
};

////////////////////////////////////////////
////////////////////////////////////////////

class SimpleTaskCollection : public TaskCollection {
public:
    std::unique_ptr<TaskIterator> createIterator() override;
    void addTask(std::unique_ptr<Task> task);
private:
    std::vector<std::unique_ptr<Task>> m_tasks;
};

std::unique_ptr<TaskIterator> SimpleTaskCollection::createIterator() {
    return std::make_unique<SimpleTaskIterator>(m_tasks);
}

void SimpleTaskCollection::addTask(std::unique_ptr<Task> task) {
    m_tasks.push_back(std::move(task));
}

////////////////////////////////////////////
////////////////////////////////////////////


class SimpleTaskIterator : public TaskIterator {
public:
    SimpleTaskIterator(const std::vector<std::unique_ptr<Task>>& tasks);
    bool hasNext() const override;
    Task& next() override;
private:
    const std::vector<std::unique_ptr<Task>>& m_tasks;
    size_t m_index = 0;
};

SimpleTaskIterator::SimpleTaskIterator(const std::vector<std::unique_ptr<Task>>& tasks) : m_tasks(tasks) {}

bool SimpleTaskIterator::hasNext() const {
    return m_index < m_tasks.size();
}

Task& SimpleTaskIterator::next() {
    return *m_tasks[m_index++];
}



/////////////////////////////////////////
///////////// Usage Example /////////////
/////////////////////////////////////////

// auto task1 = std::make_unique<SimpleTask>("Finish task management system");
// auto task2 = std::make_unique<SimpleTask>("Update user interface");
// SimpleTaskCollection taskCollection;
// taskCollection.addTask(std::move(task1));
// taskCollection.addTask(std::move(task2));
// auto taskIterator = taskCollection.createIterator();
// while (taskIterator->hasNext()) {
//     std::cout << taskIterator->next().getTitle() << std::endl;
// }
