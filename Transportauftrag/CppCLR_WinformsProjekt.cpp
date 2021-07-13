#include "pch.h"
#include "Transportauftrag.h"
#include "Admin.h"
//#include "Funktionen.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//gcnew Transportauftrag_Admin::Admin();
	Application::Run(gcnew Transportauftrag::Haupt());
	return 0;
}