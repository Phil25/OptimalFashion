#pragma once

#include <string>
#include <array>
#include <vector>
#include <set>

namespace optifa
{
	struct ArmorPiece final
	{
		enum class Type { Head, Chest, Hands, Legs };

		enum class Param
		{
			Physical, Strike, Slash, Thrust,
			Magic, Fire, Lightning, Dark,
			Bleed, Poison, Frost, Curse,
			Poise, Weight,
			Size
		};

		using NameList = std::set<std::string>;
		using Vector = std::vector<ArmorPiece>;
		using ParamArray = std::array<float, static_cast<size_t>(Param::Size)>;
		using MinParams = std::vector<std::pair<Param, float>>;

		const std::string name;
		const ParamArray params;

		ArmorPiece(std::string name, ParamArray params) noexcept
			: name(std::move(name)), params(std::move(params))
		{
		}

		inline float Get(const Param p) const noexcept
		{
			return params[static_cast<size_t>(p)];
		}
	};
}