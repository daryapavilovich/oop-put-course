#include <iostream>
using namespace std;
class box {
public:
	double length;
	double width;
	double height;
	double volume(double length, double width, double height) {
		return length * width * height;
	}
};
int main() {
	box package;
	package.length = 3.0;
	package.width = 2.0;
	package.height = 5.0;
	cout << package.volume(package.length, package.width,package.height) << endl;

}
