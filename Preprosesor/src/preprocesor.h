#pragma once
#include <string>
#include <vector>
#include <unordered_map>

class preproscesor {
public:
	void senteces_separetor(std::string URl, std::string create_URl);
	std::vector<std::string> Tokenizer(std::string sentece);
	std::unordered_map<std::string, int> world_copunter(std::vector<std::string>& token_list);
};