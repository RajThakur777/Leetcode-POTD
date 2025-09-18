class TaskManager {
    typedef pair<int, int> Task;

    priority_queue<Task> maxHeap;
    unordered_map<int, int> taskPriorityMap;
    unordered_map<int, int> taskOwnerMap;

public:
    TaskManager(vector<vector<int>>& initialTasks) {
        for (const auto& task : initialTasks) {
            add(task[0], task[1], task[2]);
        }
    }

    void add(int userId, int taskId, int priority) {
        maxHeap.push({priority, taskId});
        taskPriorityMap[taskId] = priority;
        taskOwnerMap[taskId] = userId;
    }

    void edit(int taskId, int newPriority) {
        maxHeap.push({newPriority, taskId});
        taskPriorityMap[taskId] = newPriority;
    }

    void rmv(int taskId) {
        taskPriorityMap[taskId] = -1;
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [priority, taskId] = maxHeap.top();
            maxHeap.pop();

            if (priority == taskPriorityMap[taskId]) {
                taskPriorityMap[taskId] = -1;
                return taskOwnerMap[taskId];
            }
        }
        return -1;
    }
};


/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */