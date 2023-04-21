#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

// This code demonstrates how the Observer pattern can be used to implement a publish-subscribe mechanism.
// The base classes (Observer and Subject) define the interfaces for the observer and the subject. 
// The Task class is a concrete observer that registers itself with the subject (taskCollection in this case) and gets notified when the subject changes.
// When a task is updated, it calls the update method that prints a message indicating that the task has been updated.
// The client code creates the tasks and the subject and then notifies the subject to trigger the update of the tasks.

class Observer {
public:
    virtual void update() = 0;
    virtual ~Observer() = default;
};

class Subject {
public:

    //attach
    void subscribe(Observer* observer)
    {
        m_observers.push_back(observer);
    }
    
    // detach
    void unsubscribe(Observer* observer)
    {
        m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
    }

    void notify()
    {
        for (auto observer : m_observers) 
            observer->update();   
    }
    
    virtual ~Subject() = default;
private:
    std::vector<Observer*> m_observers;
};


/*

std::vector<std::unique_ptr<Task>> taskCollection;
Subject taskSubject;

for (int i = 0; i < 5; i++) {
    auto task = std::make_unique<Task>("Task " + std::to_string(i + 1));
    taskCollection.push_back(std::move(task));
}

for (auto& task : taskCollection) {
    taskSubject.attach(task.get());
}

// Trigger updates
taskSubject.notify();

*/
