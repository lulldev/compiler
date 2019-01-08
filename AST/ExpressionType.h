#pragma once
#include <string>
#include <boost/optional.hpp>
#include <map>
#include <unordered_map>
#include <unordered_set>

enum class ExpressionType
{
	Int,
	Float,
	Bool,
	String
};

bool Convertible(ExpressionType from, ExpressionType to);
bool ConvertibleToBool(ExpressionType type);

boost::optional<ExpressionType> GetPreferredType(ExpressionType left, ExpressionType right);

std::string ToString(ExpressionType type);
