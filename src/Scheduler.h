#pragma once
#include "PCB.h"

class Scheduler {
private:
    // 就绪队列的头指针
    PCB* head;

public:
    // 构造函数
    Scheduler();

    // 1. 创建一个新的进程，并自动放入队列
    // 参数：进程标识，初始优先数，需要运行的时间
    void createProcess(std::string name, int priority, int time);

    // 2. 将进程按规则插入到就绪队列
    // 规则：最高优先数优先算法/FCFS
    void insertProcess(PCB* p);

    // 3. 启动调度器
    void run();

    // 打印当前队列状态
    void displayQueue();

};