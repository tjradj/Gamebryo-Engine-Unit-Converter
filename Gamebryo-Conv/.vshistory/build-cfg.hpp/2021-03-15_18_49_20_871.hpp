#pragma once
#include <iostream>
#include <INI.hpp>
#include <INI_Defaults.hpp>

class Config {
	INI* _config{ nullptr };

public:
	Config(INI& config_inst) : _config{ &config_inst } {}

	bool write_default(const std::string& filename = "def.ini")
	{
		const section_map 
			defMap{
				{
					"conversions", { 
						{ "metric_to_imperial",	"" }, 
						{ "metric_to_unit",		"" }, 
						{ "imperial_to_unit",	"" }, 
					}
				},
			},
			defCommentMap{
				{
					"conversions", {
						{ "metric_to_imperial",	"The factor used to convert metric to imperial, where [imperial] = [metric] / [value]" },
						{ "metric_to_unit",		"" },
						{ "imperial_to_unit",	"" },
					}
				},
			};
		return INI_Defaults{ defMap, defCommentMap }.write(filename);
	}

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