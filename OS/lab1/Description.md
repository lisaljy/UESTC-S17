# 考察父进程被终止后，子进程的不同状态
题目：
在操作系统中，一个进程可以创建另一个进程。创建者称为父进程，被创建者成为子进程。当父进程被终止后，子进程可能有两种状态：

* 子进程一并被终止；
* 子进程成为孤儿进程，被init进程领养。

*请在linux实验验证：什么情况下出现第一种结果，什么情况下出现第二种结果。*

## 1.所需知识点汇总整理

### 进程管理基本语句

* 查询进程

查询正在运行的进程信息

```
$ps -ef
```

查询系统的进程树，进而查看某个进程的父进程

```
$pstree
```

同时查询进程的id，和其父进程id

```
$ps -ef |grep <进程名>
$ps -o pid,ppid,comm
```

* 终止进程

杀死指定id的进程

```
$kill PID
```

### Fork函数

* Fork函数的作用

一般来讲, 我们编写1个普通的c程序, 运行这个程序直到程序结束, 系统只会分配1个pid给这个程序, 也就就说, 系统里只会有一条关于这个程序的进程。 但是当执行Fork()函数之后，系统则会包含多条关于这个程序的进程。Fork()函数的作用是复制当前进程(包括进程在内存里的堆栈数据)为1个新的镜像. 然后这个新的镜像和旧的进程同时执行下去. 相当于本来1个进程, 遇到fork() 函数后就分叉成两个进程同时执行了. 而且这两个进程是互不影响

![alt text](https://github.com/lisaljy/UESTC-S17/blob/master/OS/lab1/pic/1.PNG)

## 2.实验操作过程

[创建父进程和子进程](https://github.com/lisaljy/UESTC-S17/blob/master/OS/lab1/src/CreateChildExe.c)

```c
#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("Father is created\n\n");

    fork();//create a child process

    printf("Child is created\n\n");

    int i; scanf("%d",&i);   //prevent exiting
    return 0;
}
```

![alt text](https://github.com/lisaljy/UESTC-S17/blob/master/OS/lab1/pic/2.PNG)

运行后系统的进程：

![alt text](https://github.com/lisaljy/UESTC-S17/blob/master/OS/lab1/pic/3.PNG)

杀掉父进程：
![alt text](https://github.com/lisaljy/UESTC-S17/blob/master/OS/lab1/pic/4.PNG)
![alt text](https://github.com/lisaljy/UESTC-S17/blob/master/OS/lab1/pic/5.PNG)

## 3.结论
