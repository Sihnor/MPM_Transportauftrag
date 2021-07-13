#pragma once
#include <string>

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