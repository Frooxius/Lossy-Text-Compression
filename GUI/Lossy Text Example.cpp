// Lossy Text Example.cpp : main project file.

#include "stdafx.h"
#include "Form1.h"

using namespace LossyTextExample;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	SetProcessDpiAwareness(PROCESS_DPI_AWARENESS::PROCESS_PER_MONITOR_DPI_AWARE);

	// Enabling Windows XP visual effects before any controls are created
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Create the main window and run it
	Application::Run(gcnew Form1());
	return 0;
}
