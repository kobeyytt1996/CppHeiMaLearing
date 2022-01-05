#pragma once
#include "FileSystem.h"
#include <iostream>

struct Directoy {
	Directoy() : disk(gfs.numDisks()) {

	}

private:
	std::size_t disk;
};

Directoy tempDir;