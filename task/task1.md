# 模拟NVM和安装PMDK
## 模拟NVM
1. 安装Ubuntu 18.04/16.04，然后按照[Intel的教程](https://software.intel.com/zh-cn/articles/how-to-emulate-persistent-memory-on-an-intel-architecture-server)利用自己的内存进行NVM硬件的模拟，跳过内核配置相关，直接从GRUB配置进行。
1. 利用fio等工具对模拟的NVM环境进行测试，**并截图**

## 安装PMDK
1. 先安装本项目里的PMDK相关依赖，放在PMDK-dependence里
1. 然后去[PMDK的仓库](https://github.com/pmem/pmdk)按照教程进行PMDK的安装，并运行[样例程序](https://github.com/pmem/pmdk/blob/master/src/examples/libpmem/full_copy.c)和截图结果
1. 自己编写使用PMDK的程序，利用pmem_is_pmem()函数测试自己模拟的NVM环境是否被识别为NVM，截图结果。

## 提交实验报告
将关键步骤和结果截图放在实验报告中，并交到学者网。注意备注好组员姓名和学号。文件命名格式为：小组号_课程设计_task1