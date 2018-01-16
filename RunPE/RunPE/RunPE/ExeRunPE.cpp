#include<Windows.h>
#include "RunPE.h"


int main()
{
	RunPE *runPE = new RunPE();

	//pointer to file's data
	LPVOID pFile;

	//table for name of process
	TCHAR  szFilePath[1024];

	//read file to launch
	pFile = runPE->FileToMem("F:\\test.exe");


	if (pFile)
	{
		//take name of current process
		GetModuleFileName(0, LPWSTR(szFilePath), 1024);


		//launch file in the memory
		runPE->Execfile(LPSTR(szFilePath), pFile);

	}
	return 0;

}