#ifndef AXLPLUGIN_H  
#define AXLPLUGIN_H  
/**/  
#ifdef _WINDOWS  
#define DLL_DECLARE __declspec(dllexport)  
#else  
#define DLL_DECLARE  
#endif  
DLL_DECLARE int doubleDll(int a);  
/* �����еĺ����������������� */  
#endif