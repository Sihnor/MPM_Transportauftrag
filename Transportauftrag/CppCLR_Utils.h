// Copyright Richard Kaiser, 2017. http://www.rkaiser.de. All rights reserved.  
// Diese Quelltexte dürfen in eigenen Programmen verwendet werden, wenn sie 
// einen Hinweis auf die Quelle (die erste Zeile oben) enthalten. In keinem 
// Fall wird eine Haftung für direkte, indirekte, zufällige oder Folgeschäden 
// übernommen, die sich aus der Nutzung ergeben.
// It is permitted to use this source text in programs of your own, provided that 
// it contains a reference to the source (the first two lines above). All 
// liabilities for use of the code are disclaimed.

#ifndef CPPCLR_UTILS_H
#define CPPCLR_UTILS_H

#if !__cplusplus_cli 
#error Only for C++/CLI Applications (e.g. Visual Studio Windows Forms Projects)
#endif

#define SIMPLE_STRING_CONVERSIONS 1
#if SIMPLE_STRING_CONVERSIONS 
  // Diese Konversionsfunktionen sind für alle Buchbeispiele 
  // ausreichend. 
  // 
#include <string>
namespace rk1 {
  /*
  Conversion functions for .NET strings in C++ Windows Forms projects
  (Visual Studio 2008 and later). These functions can only be used
  in a CLR Windows Forms project.
  */
  std::string to_string(System::String^ S)
  {
    std::string s;
    for (int i = 0; i < S->Length; i++)
      s += S[i];
    return s;
  }

  System::String^ to_String(std::string s)
  {
    return gcnew System::String(s.c_str());
  }

  // Überladene Varianten für char* und wstring
  
  char* toCharPtr(System::String^ S)
  {
    using System::Runtime::InteropServices::Marshal;
    char* p = (char*)Marshal::StringToHGlobalAnsi(S).ToPointer();

    //// Always free the unmanaged string.
    //Marshal::FreeHGlobal(IntPtr(stringPointer));
    return p;
  }

  System::String^ to_String(const char* s)
  {
    return gcnew System::String(s);
  }

  System::String^ to_String(const wchar_t* s)
  {
    return gcnew System::String(s);
  }


  System::String^ to_String(std::wstring s)
  {
    return gcnew System::String(s.c_str());
  }

} // end of namespace rk1 {

#else // #if SIMPLE_STRING_CONVERSIONS 

#include <cstdio>

#include <string>
#include <msclr\marshal_cppstd.h>

namespace rk1 {

  // using System::String;
  // Diese marshal_as Funktionen können zur Konversion von weiteren Datentypen 
  // verwendet werden: http://msdn.microsoft.com/en-us/library/bb384865.aspx

  // Die #include-Anweisung für diese Datei sollte vor allen anderen using-Anweisungen für . 
  // .Net kommen (z.B. using System;). Andernfalls kann eine Flut von Fehlermeldungen 
  // die Folge sein. Deswegen am besten am Anfang von Form1.h einbinden. 

#pragma message ("CppClr_Utils.h must be #included before all other .Net usings, ")
#pragma message ("e.g. before 'using namespace System'. Otherwise there may lots of")
#pragma message ("compiler errors like")
#pragma message ("IDataObject: Mehrdeutiges Symbol")

  using System::Windows::Forms::TextBox;

  System::String^ to_String(std::string s)
  {
    return msclr::interop::marshal_as<System::String^>(s);
  }

  /*
  System::String^ to_String(const std::string& s)
  {
  return msclr::interop::marshal_as<System::String^>(s);
  }
  */

  /* Alternative Möglichkeit
  System::String^ to_String(std::string s)
  {
  return gcnew System::String(s.c_str());
  }
  */

  std::string to_string(System::String^ S)
  {
    return msclr::interop::marshal_as<std::string>(S);
  }

  /* Alternative Möglichkeit

  std::string to_string(System::String^ S)
  {
  std::string s;
  for (int i=0;i<S->Length; i++)
  s+=S[i];
  return s;
  }
  */

  System::String^ to_String(std::wstring s)
  {
    return msclr::interop::marshal_as<System::String^>(s);
  }
  /*
  System::String^ to_String(const std::wstring& s)
  {
  return msclr::interop::marshal_as<System::String^>(s);
  }
  */
  std::wstring to_wstring(System::String^ S)
  {
    return msclr::interop::marshal_as<std::wstring>(S);
  }

  void __test_converions()
  { // Mit den Konversionsfunktionen von oben müssten 
    // diese Anweisungen kompiliert werden:
    using System::String; // funktioniert nur bei einer C++ Windows 
    // Forms Anwendung mit Visual Studio 
    using std::string;
    char* c1 = "9ou9ouo";
    const char* c2 = "9ou9ouo";
    String^ SC1 = rk1::to_String(c1);
    String^ SC2 = rk1::to_String(c2);
    String^ SC3 = rk1::to_String("jjj");

    string s1 = "9ou9ouo";
    const string s2 = "9ou9ouo";
    String^ S1 = rk1::to_String(s1);
    String^ S2 = rk1::to_String(s2);
    String^ S3 = rk1::to_String("jojopj");

    string r1 = rk1::to_string(S1);
    string r2 = rk1::to_string(S2);
    string r3 = rk1::to_string("ikhhi");

  }
}
#endif // #if SIMPLE_STRING_CONVERSIONS 
#endif // !CPPCLR_UTILS_H

