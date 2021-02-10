#include "preprocesor.h"
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <sstream>
#include <unordered_map>


	void preproscesor::senteces_separetor(std::string read_URl, std::string create_URl){

		std::ifstream read_file(read_URl, std::ios::in);
		std::ofstream create_file(create_URl);
		std::string sentens;
		if (read_file.is_open()) {
			// Inside of this loop is where the magic happends 
			// first it divides the paragraph on sentences and tokenizind them to later out put it on another file
			while (!read_file.eof()) {
				std::getline(read_file, sentens, '.');
				if (sentens[0] == ' ') {
					sentens.erase(sentens.begin());
				}
				//Token list this varaible is a list of all of the string in the senteces 
				std::vector<std::string> token_list = Tokenizer(sentens);
				std::unordered_map<std::string, int> world_copunters = world_copunter(token_list);
				//
				create_file << sentens << std::endl;
			}
		}
		else {
			std::cout << "File did not opend" << std::endl;
		}
		read_file.close();
		create_file.close();
	}
	
	// divide the sentences into an array of single worlds
	std::vector<std::string> preproscesor::Tokenizer(std::string sentece) {
		std::vector<std::string> token_list;
		std::stringstream check1(sentece);
		std::string intemediate;
		while (std::getline(check1, intemediate, ' ')) {
			token_list.push_back(intemediate);
		}
		return token_list;
	}
	// count the number of words on a sentence
	std::unordered_map<std::string, int> preproscesor::world_copunter(std::vector<std::string>& token_list) {
		std::unordered_map<std::string, int> world_copunter;
		for (int i = 0; i < token_list.size();i++) {
			if (world_copunter.find(token_list[i]) != world_copunter.end()) {
				world_copunter[token_list[i]]++;
			}
			else {
				world_copunter[token_list[i]] = 1;
			}
		}

		return world_copunter;

	}
