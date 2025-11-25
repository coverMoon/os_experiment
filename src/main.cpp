#include <iostream>
#include "Scheduler.h"

int main() {
    // 1. 创建调度器
    Scheduler os;

    // 2. 初始化进程
    std::cout << "Initializing Processes..." << std::endl;

    // 格式: createProcess(名字, 初始优先级, 需要运行时间)
    os.createProcess("P1", 10, 3);
    os.createProcess("P2", 30, 2);
    os.createProcess("P3", 20, 3);
    os.createProcess("P4", 30, 4);
    os.createProcess("P5", 5,  1);

    std::cout << "Init Complete. Initial Queue:" << std::endl;
    os.displayQueue();

    std::cout << "Press Enter to start simulation..." << std::endl;
    std::cin.get();

    // 3. 启动调度
    os.run();

    return 0;
}