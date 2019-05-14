#include "stdafx.h"
#include "BigNumbersLibrary.h"
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iterator>
#include <string>

namespace BigNumbers {

	MyBigNumbers::MyBigNumbers(){}

	MyBigNumbers::MyBigNumbers(std::string str) {
		num = str;	
		//convert string to int
		for (auto c : num) {		
			v1.push_back(c - '0');
		}
		std::cout << num << std::endl;
	}
	
	//convert all integers in vector to a single integer
	int vectorToInt(std::vector<int> v) {
		std::reverse(v.begin(), v.end());
		int dec = 1;
		int total = 0;
		for (auto& it : v) {
			total += it * dec;
			dec *= 10;
		}
		return total;
	}

	MyBigNumbers MyBigNumbers::operator+ (const MyBigNumbers & mbn) {

		MyBigNumbers result;
		
		int carry = 0;

		for (auto c : mbn.num) {
			v2.push_back(c - '0');
		}
		
		while(v2.size() < v1.size()) {
			v2.insert(v2.begin() + 0, 0);
		}

		while (v1.size() < v2.size()) {
			v1.insert(v1.begin() + 0, 0);
		}
		

		for (int i = v1.size(); i != 0; i--) {
			int num = (v1[i - 1] + v2[i - 1] + carry) % 10;
			v3.push_back(num);
			if (v1[i - 1] + v2[i - 1] + carry >= 10) {
				carry = 1;
			}
			else {
				carry = 0;
			}
		}
		if (carry == 1) {
				v3.push_back(1);
		}


		std::reverse(v3.begin(), v3.end());
		std::ostringstream oss;
		if (!v3.empty()) {
			std::copy(v3.begin(), v3.end() - 1, std::ostream_iterator<int>(oss, ""));
			oss << v3.back();
		}

		result = oss.str();

		v2.clear();
		v3.clear();

		return result;
	}

	MyBigNumbers MyBigNumbers::operator - (const MyBigNumbers & mbn) {

		MyBigNumbers result;
		std::vector<int> temp;

		//will hold string of resulting int
		std::ostringstream oss;

		int carry = 0;

		for (auto c : mbn.num) {
			v2.push_back(c - '0');
		}

		while (v2.size() < v1.size()) {
			v2.insert(v2.begin() + 0, 0);
		}

		while (v1.size() < v2.size()) {
			v1.insert(v1.begin() + 0, 0);
		}

		//holds same internals as v1
		for (int i = 0; i < v1.size(); i++) {
			temp.push_back(v1[i]);
		}

		//check if the result will be negative
		int neg = vectorToInt(temp) - vectorToInt(v2);

		//if the result is negative
		if (neg < 0) {
			for (int i = temp.size(); i != 0; i--) {
				int num = ((v2[i - 1] + carry) - temp[i - 1]);
				if (num < 0) {
					carry = 10;
					num = ((v2[i - 1] + carry) - temp[i - 1]);
					v3.push_back(num);
					carry = 0;
					int j = i - 2;
					v2[j] = v2[j] - 1;
					j--;
				}
				else {
					v3.push_back(num);
				}
			}

			//insert negative sign
			oss << "-";			

		}
		else {

			for (int i = temp.size(); i != 0; i--) {
				int num = ((temp[i - 1] + carry) - v2[i - 1]);
				if (num < 0) {
					carry = 10;
					num = ((temp[i - 1] + carry) - v2[i - 1]);
					v3.push_back(num);
					carry = 0;
					int j = i - 2;
					temp[j] = temp[j] - 1;
					j--;
				}
				else {
					v3.push_back(num);
				}
			}
			
		}

		while (v3.back() == 0) {
			v3.pop_back();
		}

		std::reverse(v3.begin(), v3.end());

		if (!v3.empty()) {
			std::copy(v3.begin(), v3.end() - 1, std::ostream_iterator<int>(oss, ""));
			oss << v3.back();
		}

		result = oss.str();
		
		v2.clear();
		v3.clear();

		return result;
	}
	
	MyBigNumbers MyBigNumbers::operator * (const MyBigNumbers & mbn) {

		MyBigNumbers result;
		MyBigNumbers prod1;
		MyBigNumbers prod2;

		int product;
		std::vector<int> products;
		//std::vector <std::vector <int>>  *products;
		int carry = 0;

		for (auto c : mbn.num) {
			v2.push_back(c - '0');
		}

		/*while (v2.size() < v1.size()) {
			v2.insert(v2.begin() + 0, 0);
		}

		for (int i = v1.size(); i != 0; i--) {
			for (int j = v1.size(); j != 0; j--) {
				product = v1[j - 1] * v2[i - 1] + carry;
				if (product >= 10) {
					carry = product / 10;
					product %= 10;
				}
				else {
					carry = 0;
				}
				products.push_back(product);
			}
			products.push_back(0);
		}*/

		int res = vectorToInt(v1) * vectorToInt(v2);

		std::ostringstream oss;
		oss << res;

		result = oss.str();

		v2.clear();

		return result;

	}

	MyBigNumbers MyBigNumbers::operator / (const MyBigNumbers & mbn) {

		MyBigNumbers result;

		for (auto c : mbn.num) {
			v2.push_back(c - '0');
		}

		int res = vectorToInt(v1) / vectorToInt(v2);

		std::ostringstream oss;
		oss << res;

		result = oss.str();

		v2.clear();

		return result;

	}

	MyBigNumbers MyBigNumbers::operator % (const MyBigNumbers & mbn) {

		MyBigNumbers result;

		for (auto c : mbn.num) {
			v2.push_back(c - '0');
		}

		int res = vectorToInt(v1) % vectorToInt(v2);

		std::ostringstream oss;
		oss << res;

		result = oss.str();

		v2.clear();

		return result;
		
	}

	

}
