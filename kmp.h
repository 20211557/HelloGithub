#include <iostream>
#include <string>
using namespace std;

class KMP{
private:
	int*failure;
public:
	KMP() = default;
	~KMP() = default;
	void fail(const string& pat);
	bool Find(const string& str, const string& pat);
};
