#include <iostream>
#include <vector>
#include <string>

struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(std::vector<Task>& tasks, const std::string& description) {
    tasks.push_back(Task(description));
    std::cout << "Task added successfully!\n";
}

// Function to view tasks
void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks found.\n";
    } else {
        std::cout << "Tasks:\n";
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". ";
            if (tasks[i].completed) std::cout << "[Completed] ";
            std::cout << tasks[i].description << std::endl;
        }
    }
}

// Function to mark a task as completed
void markTaskCompleted(std::vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        std::cout << "Task marked as completed.\n";
    } else {
        std::cout << "Invalid task index!\n";
    }
}

// Function to remove a task from the list
void removeTask(std::vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        std::cout << "Task removed successfully.\n";
    } else {
        std::cout << "Invalid task index!\n";
    }
}

int main() {
    std::vector<Task> tasks;

    std::cout << "Welcome to Simple To-Do List Manager!\n";

    while (true) {
        std::cout << "\nChoose an option:\n";
        std::cout << "1. Add Task\n";
        std::cout << "2. View Tasks\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Remove Task\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cin.ignore(); // Ignore the newline character
                std::cout << "Enter task description: ";
                std::string description;
                std::getline(std::cin, description);
                addTask(tasks, description);
                break;
            }
            case 2:
                viewTasks(tasks);
                break;
            case 3: {
                int index;
                std::cout << "Enter task index to mark as completed: ";
                std::cin >> index;
                markTaskCompleted(tasks, index);
                break;
            }
            case 4: {
                int index;
                std::cout << "Enter task index to remove: ";
                std::cin >> index;
                removeTask(tasks, index);
                break;
            }
            case 5:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
