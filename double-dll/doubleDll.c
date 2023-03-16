#include "double-dll.h"  
#include <stdio.h>  
/*根据需要添加相应的头文件*/  
DLL_DECLARE int doubleDll(int a)  
{  
    
        return a+a;  
}  
/* 把所有声明的函数都在这里实现*/