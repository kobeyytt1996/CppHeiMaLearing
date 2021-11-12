#pragma once
#include <iostream>
#include <string>
#include "globalFile.h"
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

class Identity {
public:
	string m_Name;
	string m_Pwd;

	virtual void operMenu() = 0;
};