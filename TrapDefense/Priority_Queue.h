#pragma once
#include "ProgramBase.h"

void enPQ(Field field[10000], int distances[10000], int damage, Field pos, int* rear);
Field popPQ(Field field[10000], int distances[10000], int* rear);