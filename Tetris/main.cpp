#include <iostream>
#include "Core.h";

using namespace std;

int main() {
	if (!CCore::GetInst()->Init()) {
		CCore::DestroyInst();
		return 0;
	}

	CCore::GetInst()->Run();

	CCore::DestroyInst();

	return 0;
}