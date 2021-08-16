#ifndef LIBS_BIGINT_H_
#define LIBS_BIGINT_H_

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>    // for std::setfill
#include <sstream>    // for ostringstream

namespace hackerrank_euler
{

class BigInt
{
	typedef int32_t    ElemT;
	typedef int64_t    ProdT;
	constexpr static ElemT Base = 1000000000;
	constexpr static ElemT Upper = 999999999;

	friend std::ostream& operator<<(std::ostream& s, const BigInt& n);
	friend std::istream& operator>>(std::istream& s, BigInt& val);
public:
	BigInt(int32_t val = 0);
	BigInt(int32_t nBase, int32_t nPower);
	BigInt(const std::string& str);
	BigInt(const char* str);
public:
	BigInt& operator=(int32_t val);
	BigInt& operator=(const std::string& val);

	friend BigInt operator*(const BigInt& lhs, const BigInt& rhs)
	{
		BigInt tlhs(lhs);
		tlhs *= rhs;
		return tlhs;
	}

	BigInt& operator*=(const BigInt& rhs);

	BigInt& Multiply(const BigInt& rhs);

	size_t GetDigits() const;
	char operator[](size_t nIndex) const;

	std::string str() const;
protected:
	void Assign(int32_t val);
	void Assign(const std::string& val);
protected:
	std::vector<ElemT>    m_vals;
};

inline static std::ostream& operator<<(std::ostream& s, const BigInt& n)
{
	for (auto it = n.m_vals.rbegin(); it != n.m_vals.rend(); ++it)
	{
		if (it == n.m_vals.rbegin())
			s << *it;
		else
			s << std::setfill('0') << std::setw(9) << *it;
	}
	return s;
}

static std::istream& operator>>(std::istream& s, BigInt& val)
{
	std::string str;
	s >> str;
	val = str;
	return s;
}


}

#endif // LIBS_BIGINT_H_
