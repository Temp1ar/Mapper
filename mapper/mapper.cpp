#include <iostream>
#include <map>

#include "Mapper.h"

int main() {
	auto m (mapper(1,3.0)(2,2)(3,5.6));
	auto m2(mapper(new int(1),3.0)(new int(2),2)(new int(3),5.6));
	auto m3(mapper(1,new double(3.0))(2,new double(2))(3,new double(5.6)));
	auto m4(mapper(new int(1),new double(3.0))(new int(2),new double(2))(new int(3),new double(5.6)));
	return 0;
}