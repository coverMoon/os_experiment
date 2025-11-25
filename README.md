## 工程结构

```
project_ws/
├── CMakeLists.txt          // CMake 构建脚本
├── src/
│   ├── main.cpp            // 程序入口：负责初始化数据，启动调度循环
│   ├── PCB.h               // 头文件：定义 PCB 结构体和枚举类型
│   ├── Scheduler.h         // 头文件：声明调度器类/函数 (核心逻辑)
│   └── Scheduler.cpp       // 源文件：实现具体的调度算法、链表操作
└── README.md
```