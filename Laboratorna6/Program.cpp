#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace StudentStipendiaApp;

[STAThreadAttribute]
int main()
{
    System::Windows::Forms::Application::EnableVisualStyles();
    System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
    System::Windows::Forms::Application::Run(gcnew StudentStipendiaApp::MyForm());
    return 0;
}