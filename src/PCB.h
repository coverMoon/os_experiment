#pragma once
#include <string>
#include <iostream>

// 定义进程状态
enum State {
    WAIT,   // 就绪(W)
    RUN,    // 运行(R)
    FINISH  // 完成(F)
};

// 定义 PCB 结构体
struct PCB {
    // 1. 进程标识符
    std::string name;

    // 2. 链表指针
    PCB* next;

    // 3. 调度参数
    int priority;   // 优先数：越大越先运行
    int runTime;    // 需要运行的时间
    int usedTime;   // 已占用 CPU 时间

    // 4. 状态
    State state;

    // 构造函数，在创建进程时直接初始化数据
    PCB(std::string n, int p, int t)
    {
        name = n;
        priority = p;
        runTime = t;
        usedTime = 0;
        state = WAIT;   // 创建时默认在就绪态
        next = nullptr;
    }

    // 辅助函数：打印当前信息
    void printInfo() const
    {
        std::cout << name << "\t"
                  << priority << "\t"
                  << runTime << "\t"
                  << usedTime << "\t"
                  << (state == RUN ? "RUN" : (state == FINISH ? "FINISH" : "WAIT"))
                  << std::endl;
    }
};