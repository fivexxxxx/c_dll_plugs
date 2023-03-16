/*
#include "double-dll.h"  
#include "square-dll.h"
#include "cube-dll.h"
*/
#include <stdio.h> 
#include <Windows.h>
#include <stdlib.h>

typedef int (*cubeFuction)(int);
struct plugin{
	struct plugin *next;
	char *pname;
	void *phandle;
	int(*process)(int);
};

struct plugin *findplugin(struct plugin *plist,const char *pname)
{
	while(plist){
		if(strcmp(plist->pname,pname)==0){
			return plist;
		}
		plist=plist->next;
	}
	return NULL;
}

struct plugin *createplugin(const char *pname){
	HMODULE handle;
	char libname[100] = "";
    struct plugin *p = (struct plugin*)malloc(sizeof(struct plugin));
    p->next = NULL;
    p->pname = strdup(pname);
    
    strcat(libname, pname);
    strcat(libname, ".dll");

	handle =LoadLibraryA(libname);
    if (handle == NULL) {
        return NULL;
    }
    p->phandle = handle;
	p->process = (cubeFuction)GetProcAddress(handle, "cubeDll");

    if (p->process == NULL) {
        return NULL;
    }
    return p;
}
int main()  
{	
	int a;
    char pname[100];
    struct plugin *plist = NULL;
    while (scanf("%d%s", &a, pname) != EOF) {
        struct plugin *p = findplugin(plist, pname);
        if (p == NULL) {
            p = createplugin(pname);
            if (p == NULL) {
                return -1;
            }
            p->next = plist;
            plist = p;
        }
        printf("%d\n", p->process(a));
    }
	system("pause");
    return 0;  
}






















	/*
    printf("double(x) = %d\n", doubleDll(2));
	printf("square(x) = %d\n", squareDll(2));
	printf("cube(x) = %d\n", cubeDll(2));
	*/
	/*
	HMODULE hDll=LoadLibrary(L"cube-dll.dll");
	if(hDll!=NULL)
	{
		cubeFuction cube=(cubeFuction)GetProcAddress(hDll,"cubeDll");
		if(cube!=NULL)
		{
			printf("cube value:%d\n",cube(2));
		}
		FreeLibrary(hDll);
	}*/

