#pragma once
#include <iostream>

struct FileSystem
{
	std::size_t numDisks() const {
		return 20;
	}

};

extern FileSystem gfs;