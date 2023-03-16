#ifndef AXLPLUGIN_H  
#define AXLPLUGIN_H  
/**/  
#ifdef _WINDOWS  
#define DLL_DECLARE __declspec(dllexport)  
#else  
#define DLL_DECLARE  
#endif  
DLL_DECLARE int cubeDLL(int a);  
/* 把所有的函数声明都列在这里 */  
#endif