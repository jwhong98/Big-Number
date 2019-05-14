//BigNumbersLibrary.h
#include <vector>
namespace BigNumbers {

	class MyBigNumbers {
	public:

		std::vector <int> v1;
		std::vector <int> v2;
		std::vector <int> v3;
		std::string num;
		MyBigNumbers();
		MyBigNumbers(std::string);

		MyBigNumbers operator + (const MyBigNumbers &);

		MyBigNumbers operator - (const MyBigNumbers &);
		
		MyBigNumbers operator * (const MyBigNumbers &);
		
		MyBigNumbers operator / (const MyBigNumbers &);
		
		MyBigNumbers operator % (const MyBigNumbers &);

	};
}
