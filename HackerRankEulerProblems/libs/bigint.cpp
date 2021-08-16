#include "bigint.h"

using namespace hackerrank_euler;

static const int32_t aPowersOf10[] = { 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000 };

BigInt::BigInt(int32_t val)
{
	Assign(val);
}

BigInt::BigInt(int32_t nBase, int32_t n)
{
	Assign(n == 0 ? 1 : nBase);
	if (n <= 1)
		return;
	BigInt y(1);
	while (n > 1)
	{
		if (n & 1)
		{
			y.Multiply(*this);
			n = (n - 1) >> 1;
		}
		else
		{
			n >>= 1;
		}
		Multiply(*this);
	}
	Multiply(y);
}

BigInt::BigInt(const std::string& str)
{
	Assign(str);
}

BigInt::BigInt(const char* str)
{
	Assign(str);
}

void BigInt::Assign(int32_t val)
{
	m_vals.clear();
	do
	{
		auto dd = div(val, Base);
		m_vals.push_back((ElemT)dd.rem);
		val = dd.quot;
	} while (val);
}

void BigInt::Assign(const std::string& val)
{
	m_vals.clear();
	if (val.length() == 0)
		return;
	m_vals.reserve(val.size() / 9 + 1);
	size_t nn = val.length();
	while (nn--)
	{
		size_t nPos = nn >= 8 ? nn - 8 : 0;
		m_vals.push_back(std::stoi(val.substr(nPos, nn - nPos + 1)));
		nn = nPos;
	}
}

BigInt& BigInt::operator=(int32_t val)
{
	Assign(val);
	return *this;
}

BigInt& BigInt::operator=(const std::string& val)
{
	Assign(val);
	return *this;
}

BigInt& BigInt::operator*=(const BigInt& rhs)
{
	return Multiply(rhs);
}

BigInt& BigInt::Multiply(const BigInt& rhs)
{
	BigInt res(0);
	res.m_vals.resize(m_vals.size() + rhs.m_vals.size());
	for (size_t n1 = 0; n1 < m_vals.size(); ++n1)
	{
		for (size_t n2 = 0; n2 < rhs.m_vals.size(); ++n2)
		{
			size_t nDigit = n1 + n2;
			ProdT nVal = (ProdT)m_vals[n1] * rhs.m_vals[n2];
			nVal += res.m_vals[nDigit];
			if (nVal >= Base)
			{
				auto dd = lldiv(nVal, Base);
				res.m_vals[nDigit + 1] += (ElemT)dd.quot;
				nVal = dd.rem;
			}
			res.m_vals[nDigit] = (ElemT)nVal;
		}
	}
	// trim leading zero
	if (res.m_vals.size() > 1 && res.m_vals.back() == 0)
		res.m_vals.resize(res.m_vals.size() - 1);
	m_vals.swap(res.m_vals);
	return *this;
}

#ifndef _countof
#define _countof(_Array) (sizeof(_Array) / sizeof(_Array[0]))
#endif

size_t BigInt::GetDigits() const
{
	size_t nDigits = (m_vals.size() - 1) * 9;
	ElemT n = m_vals.back();
	for (int ii = (int)_countof(aPowersOf10)-1; ii >= 0; --ii)
	{
		if (n >= aPowersOf10[ii])
		{
			nDigits += ii+1;
			break;
		}
	}
	return nDigits;
}

char BigInt::operator[](size_t nIndex) const
{
	auto dd = lldiv(nIndex, 9);
	if ((size_t)dd.quot >= m_vals.size())
	{
		// throw error?
		return -1;
	}
	return (m_vals[dd.quot] / aPowersOf10[dd.rem]) % 10;
}

std::string BigInt::str() const
{
	std::ostringstream s;
	for (auto it = m_vals.rbegin(); it != m_vals.rend(); ++it)
	{
		if (it == m_vals.rbegin())
			s << *it;
		else
			s << std::setfill('0') << std::setw(9) << *it;
	}
	return s.str();
}

