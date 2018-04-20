/*
 * GrammarTable.h
 *
 *  Created on: Apr 17, 2018
 *      Author: amrnasr
 */

#ifndef SYNTACTIC_GRAMMAR_TABLE_MODEL_GRAMMARTABLE_H_
#define SYNTACTIC_GRAMMAR_TABLE_MODEL_GRAMMARTABLE_H_

#include <unordered_map>
#include "unordered_set"
#include <string>
#include <vector>

struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1,T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);

		return h1 ^ h2;
	}
};

using namespace std;

class GrammarTable {
	private:
		unordered_map<pair<string, string>, vector<string>, pair_hash> table;
		unordered_set<pair<string, string>, pair_hash> synchronizing;
		unordered_set<string> non_terminals, terminals;
		string start_rule;
	public:
		bool add_entry(string non_terminal, string terminal, vector<string> rules);
		bool has_entry(string non_terminal, string terminal);
		vector<string> get_entry(string non_terminal, string terminal);
		void add_synch(string non_terminal, string terminal);
		bool is_synch(string non_terminal, string terminal);
		vector<string> get_terminals();
		vector<string> get_non_terminals();
		void set_terminals(vector<string> term);
		void set_non_terminals(vector<string> non_term);
		bool is_terminal(string str);
		bool is_non_terminal(string str);
		void set_start(string str);
		string get_start();
};



#endif /* SYNTACTIC_GRAMMAR_TABLE_MODEL_GRAMMARTABLE_H_ */
