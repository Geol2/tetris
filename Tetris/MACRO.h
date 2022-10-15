#pragma once
#include "value.h"

#define SAFE_DELETE(p) if(p) { delete p; p = NULL; }