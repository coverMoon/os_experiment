#include "Scheduler.h"
#include <iostream>

// 构造函数
Scheduler::Scheduler()
{
    head = nullptr;
}

// 创建并插入进程
void Scheduler::createProcess(std::string name, int priority, int time)
{
    // 为新进程开辟一块内存
    auto newProcess = new PCB(name, priority, time);

    // 插入链表
    insertProcess(newProcess);
}

// 按优先级插入链表
void Scheduler::insertProcess(PCB* p)
{
    // A. 队列为空
    if (head == nullptr)
    {
        head = p;
        p->next = nullptr;

        return;
    }

    // B. 新进程优先级 > 头结点优先级
    if (p->priority > head->priority)
    {
        p->next = head;
        head = p;

        return;
    }

    // C. 插入到链表中间或尾部
    PCB* current = head;
    // 条件：只要 current->next 不为空，且 current->next 的优先级 >= 新进程优先级
    while (current->next != nullptr && current->next->priority >= p->priority)
    {
        current = current->next;
    }

    p->next = current->next;
    current->next = p;
}

// 打印队列
void Scheduler::displayQueue()
{
    PCB* p = head;
    if (p == nullptr)
    {
        std::cout << "Queue is empty." <<std::endl;
        return;
    }

    std::cout << "Name\tPrio\tTime\tState" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    while (p != nullptr)
    {
        std::cout << p->name << "\t"
                  << p->priority << "\t"
                  << p->runTime << "\t"
                  << (p->state == WAIT ? "WAIT" : "RUN")
                  << std::endl;

        p = p->next;
    }
    std::cout << std::endl;
}

void Scheduler::run()
{
    std::cout << "\nStart Simulation..." << std::endl;
    int round = 1;  // 记录运行的时间片总数

    while (head != nullptr)
    {
        PCB* current = head;
        head = head->next;
        current->next = nullptr;

        current->state = RUN;

        // --- 逻辑计算区 ---
        const int PRIORITY_PENALTY = 1; // 每时间片优先级惩罚
        const int TIME_SLICE = 1;       // 时间片长度

        int oldPriority = current->priority;

        // 执行运算
        current->priority -= PRIORITY_PENALTY;
        current->runTime -= TIME_SLICE;
        current->usedTime += TIME_SLICE;

        // --- UI 显示区 ---
        std::cout << "\n================ [ Round " << round++ << " ] ================" << std::endl;
        std::cout << "Running Process : [" << current->name << "]" << std::endl;
        std::cout << "Priority Change : " << oldPriority << " -> " << current->priority << std::endl;
        std::cout << "Remaining Time  : " << (current->runTime < 0 ? 0 : current->runTime) << std::endl;

        std::cout << "\nWaiting Queue (Others):" << std::endl;
        displayQueue();

        // --- 调度区 ---
        if (current->runTime <= 0)
        {
            current->state = FINISH;
            std::cout << ">>> Process [" << current->name << "] has FINISHED! <<<" << std::endl;
            delete current;
        }
        else
        {
            current->state = WAIT;
            std::cout << ">>> Process [" << current->name << "] Re-inserted into queue." << std::endl;
            insertProcess(current);
        }
    }

    std::cout << "\n=============================================" << std::endl;
    std::cout << "All processes completed. System Halt." << std::endl;
}