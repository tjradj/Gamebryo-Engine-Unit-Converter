#pragma once
#include <iostream>
#include <INI.hpp>
#include <INI_Defaults.hpp>

bool write_default_ini(const std::string& filename = "def.ini")
{
	const section_map
		// Default Setting Values
		defMap{
			{
				"conversions", {
					{ "imperial_to_metric",	"0.3048" },
					{ "metric_to_unit",		"0.0142875313" },
					{ "imperial_to_unit",	"21.3333333333" },
				}
			},
			{
				"config", {
					{ "disable-colors", "false" },
					{ "always-show-input", "false" },
				}
			},
	},
		// Default Setting Comments
		defCommentMap{
			{
				"conversions", {
					{ "imperial_to_metric",	"Used for conversions between metric & imperial. ([Metric] = [Imperial] * [Factor])" },
					{ "metric_to_unit",		"Used for conversions between metric & units. ([Units] = [Metric] * [Factor])" },
					{ "imperial_to_unit",	"Used for conversions between imperial & units. ([Units] = [Imperial] * [Factor])" },
				}
			},
			{
				"config", {
					{ "disable-colors", "false" },
					{ "always-show-input", "false" },
				}
			},
	};
	return INI_Defaults{ defMap, defCommentMap }.write(filename);
}

class Config {
	INI* _config{ nullptr };

public:
	Config(INI& config_inst) : _config{ &config_inst } {}

	

	std::string get(std::string&& header, std::string&& key)
	{
		return _config->get(std::forward<std::string>(header), std::forward<std::string>(key)).value_or("");
	}
	INI::key_list* get(std::string&& header)
	{
		return _config->getSecPtr(std::forward<std::string>(header));
	}

	friend std::ostream& operator<<(std::ostream& os, const Config& c)
	{
		
		return os;
	}
};