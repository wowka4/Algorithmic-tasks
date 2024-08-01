#include <iostream>
#include <map>
#include <string>
#include <tuple>

using namespace std;

// Перечислимый тип для статуса задачи
enum class TaskStatus {
    NEW, // новая
    IN_PROGRESS, // в разработке
    TESTING, // на тестировании
    DONE // завершена
};

// Объявляем тип-синоним для map<TaskStatus, int>,
// позволяющего хранить количество задач каждого статуса
using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
public:
    static TaskStatus Next(TaskStatus task_status) {
        return static_cast<TaskStatus>(static_cast<int>(task_status) + 1);
    }

    // Получить статистику по статусам задач конкретного разработчика
    const TasksInfo &GetPersonTasksInfo(const string &person) const {
        return tasks_to_person_.at(person);
    }

    // Добавить новую задачу (в статусе NEW) для конкретного разработчика
    void AddNewTask(const string &person) {
        tasks_to_person_[person][TaskStatus::NEW]++;
    }

    // Обновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(const string &person, int task_count) {
        TasksInfo updated_tasks, untouched_tasks;
        if (!tasks_to_person_.count(person)) return {updated_tasks, untouched_tasks};
        for (int i = 0; i < 3; ++i) {
            const int min = std::min(tasks_to_person_.at(person)[static_cast<TaskStatus>(i)], task_count);
            task_count -= min;
            tasks_to_person_.at(person)[static_cast<TaskStatus>(i)] -= min;
            updated_tasks[static_cast<TaskStatus>(i + 1)] += min;
            untouched_tasks[static_cast<TaskStatus>(i)] += tasks_to_person_.at(person)[static_cast<TaskStatus>(i)];
            tasks_to_person_.at(person)[static_cast<TaskStatus>(i)] += updated_tasks[static_cast<TaskStatus>(i)];
        }
        tasks_to_person_.at(person)[TaskStatus::DONE] += updated_tasks[TaskStatus::DONE];
        return {updated_tasks, untouched_tasks};
    }

private:
    map<string, TasksInfo> tasks_to_person_;
};

// Принимаем словарь по значению, чтобы иметь возможность
// обращаться к отсутствующим ключам с помощью [] и получать 0,
// не меняя при этом исходный словарь.
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks"s
            << ", "s << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress"s
            << ", "s << tasks_info[TaskStatus::TESTING] << " tasks are being tested"s
            << ", "s << tasks_info[TaskStatus::DONE] << " tasks are done"s << endl;
}

int main() {
    TeamTasks tasks;
    tasks.AddNewTask("Ilia"s);

    cout << "Ilia's tasks: "s;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"s));
    cout << endl;

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia"s, 1);
    cout << "Updated Ilia's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ilia's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << "Ilia's tasks" << endl;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));

    cout << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia"s, 1);
    cout << "Updated Ilia's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ilia's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << "Ilia's tasks" << endl;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia"s, 1);
    cout << "Updated Ilia's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ilia's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    tasks.AddNewTask("Ilia"s);
    cout << "Ilia's tasks" << endl;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
    cout << endl;
    tie(updated_tasks, untouched_tasks) = tasks.PerformPersonTasks("Ilia"s, 1);
    cout << "Updated Ilia's tasks: "s;
    PrintTasksInfo(updated_tasks);
    cout << "Untouched Ilia's tasks: "s;
    PrintTasksInfo(untouched_tasks);
    cout << "Ilia's tasks" << endl;
    PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
}
