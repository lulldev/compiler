#include "Grammar.h"
#include <iostream>

using std::cout;
using std::endl;

#ifdef SDD

Grammar::Grammar() {
	load_from_ini();
	int cur_idx = 0;
	for (const auto& production : productions) {
		production_idxes[production.left].insert(cur_idx++);
	}
}

#else

inline bool is_int_or_real(TokenType type) {
	return type == INT_CONSTANT || type == REAL_CONSTANT;
}

inline TokenType get_bin_op_res_type(TokenType lhs_type, TokenType rhs_type) {
	if (is_int_or_real(lhs_type) && is_int_or_real(rhs_type)) {
		return (lhs_type == REAL_CONSTANT || rhs_type == REAL_CONSTANT)?
			REAL_CONSTANT : INT_CONSTANT;
	} else {
		return UNKNOWN;
	}
}

template <typename T>
T get_val_by_type(variant<long long, double> val, TokenType type) {
	switch (type) {
		case INT_CONSTANT:
			return T(boost::get<long long>(val));
		case REAL_CONSTANT:
			return T(boost::get<double>(val));
	}
}

Grammar::Grammar() :
	nonterminals({"E", "T", "F"}),
	terminals(
		{
			ADD, SUB, ASTERISK, DIV, L_PAREN, R_PAREN, INT_CONSTANT, REAL_CONSTANT, END
		}
	),
	start_symbol("E"),
	productions(
		{
			{
				"E", {"E", ADD, "T"},  
				[](deque<LrStackItem>& parsing_stack) {
					int
						t(parsing_stack.size() - 1),
						nt(parsing_stack.size() - 3);
					TokenType
						lhs_type(std::get<TYPE>(parsing_stack[t - 2])),
						rhs_type(std::get<TYPE>(parsing_stack[t])),
						type = get_bin_op_res_type(lhs_type, rhs_type);
					std::get<TYPE>(parsing_stack[nt]) = type;
					switch (type) {
						case INT_CONSTANT: {
							long long
								lhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val + rhs_val;
							return;
						}
						case REAL_CONSTANT: {
							double
								lhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val + rhs_val;
							return;
						}
					}
				}
			},
			{
				"E", {"E", SUB, "T"},
				[](deque<LrStackItem>& parsing_stack) {
					int
						t(parsing_stack.size() - 1),
						nt(parsing_stack.size() - 3);
					TokenType
						lhs_type(std::get<TYPE>(parsing_stack[t - 2])),
						rhs_type(std::get<TYPE>(parsing_stack[t])),
						type = get_bin_op_res_type(lhs_type, rhs_type);
					std::get<TYPE>(parsing_stack[nt]) = type;
					switch (type) {
						case INT_CONSTANT: {
							long long
								lhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val - rhs_val;
							return;
						}
						case REAL_CONSTANT: {
							double
								lhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val - rhs_val;
							return;
						}
					}
				}
			},
			{
				"E", {"T"}
			},
			{
				"T", {"T", ASTERISK, "F"},
				[](deque<LrStackItem>& parsing_stack) {
					int
						t(parsing_stack.size() - 1),
						nt(parsing_stack.size() - 3);
					TokenType
						lhs_type(std::get<TYPE>(parsing_stack[t - 2])),
						rhs_type(std::get<TYPE>(parsing_stack[t])),
						type = get_bin_op_res_type(lhs_type, rhs_type);
					std::get<TYPE>(parsing_stack[nt]) = type;
					switch (type) {
						case INT_CONSTANT: {
							long long
								lhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val * rhs_val;
							return;
						}
						case REAL_CONSTANT: {
							double
								lhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val * rhs_val;
							return;
						}
					}
				}
			},
			{
				"T", {"T", DIV, "F"},
				[](deque<LrStackItem>& parsing_stack) {
					int
						t(parsing_stack.size() - 1),
						nt(parsing_stack.size() - 3);
					TokenType
						lhs_type(std::get<TYPE>(parsing_stack[t - 2])),
						rhs_type(std::get<TYPE>(parsing_stack[t])),
						type = get_bin_op_res_type(lhs_type, rhs_type);
					std::get<TYPE>(parsing_stack[nt]) = type;
					switch (type) {
						case INT_CONSTANT: {
							long long
								lhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<long long>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val / rhs_val;
							return;
						}
						case REAL_CONSTANT: {
							double
								lhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t - 2]), lhs_type
									)
								),
								rhs_val(
									get_val_by_type<double>(
										std::get<VAL>(parsing_stack[t]), rhs_type
									)
								);
							std::get<VAL>(parsing_stack[nt]) = lhs_val / rhs_val;
							return;
						}
					}
				}
			},
			{
				"T", {"F"},
			},
			{
				"F", {INT_CONSTANT},
			},
			{
				"F", {REAL_CONSTANT},
			},
			{
				"F", {L_PAREN, "E", R_PAREN},
				[](deque<LrStackItem>& parsing_stack) {
					int
						t(parsing_stack.size() - 1),
						nt(parsing_stack.size() - 3);
					std::get<VAL>(parsing_stack[nt]) = std::get<VAL>(parsing_stack[t - 1]);
					std::get<TYPE>(parsing_stack[nt]) = std::get<TYPE>(parsing_stack[t - 1]);
				}
			}
		}
	) {	
	int cur_idx = 0;
	for (const auto& production : productions) {
		production_idxes[production.left].insert(cur_idx++);
	}
}

#endif // SDD


#include "../Lexer/Lexer.h"
#include <fstream>

using std::ifstream;

void Grammar::load_from_ini() {
	Lexer lexer;
	ifstream in("../Compiler/Parser/Grammar.ini");
	//ifstream in("Grammar.ini");
	in >> lexer;
	const vector<Token>& token_stream(lexer.get_token_stream());
	int i(0);
	//load nonterminals
	for (; token_stream[i].type != L_BRACE; ++i);
	for (++i; token_stream[i].type != R_BRACE; ++i) {
		nonterminals.push_back(
			symbol_table[
				token_stream[i].symbol_idx
			]
		);
	}
	//load terminals
	terminals.emplace_back(EPSILON);
	terminals.emplace_back(END);
	for (; token_stream[i].type != L_BRACE; ++i);
	for (++i; token_stream[i].type != R_BRACE; ++i) {
		TokenType type(token_stream[i].type);
		if (token_stream[i].type == IDENTIFIER) {
			type = string_to_token_type[ //where "num" would map to NUMERIC_CONSTANT
				symbol_table[
					token_stream[i].symbol_idx
				]
			];
		}
		terminals.emplace_back(type);
	}
	//load start_symbol
	for (; token_stream[i].type != L_BRACE; ++i);
	for (++i; token_stream[i].type != R_BRACE; ++i) {
		start_symbol = symbol_table[
			token_stream[i].symbol_idx
		];
	}
	//load productions
	for (; token_stream[i].type != L_BRACE; ++i);
	while (token_stream[i + 1].type != R_BRACE) {
		for (++i; token_stream[i].type == L_BRACE; ++i);
		Symbol nonterminal(
			symbol_table[
				token_stream[i].symbol_idx
			]
		);
		for (; token_stream[i].type != ARROW; ++i);
		production_idxes[nonterminal].insert(productions.size());
		productions.emplace_back(nonterminal);
		for (++i; token_stream[i].type != R_BRACE; ++i) {
			if (token_stream[i].type != BITWISE_OR) {
				TokenType type(token_stream[i].type);
				if (type == IDENTIFIER) {
					type = string_to_token_type[
						symbol_table[
							token_stream[i].symbol_idx
						]
					];
				}
				if (type != IDENTIFIER) {
					productions.back().right.emplace_back(type);
				} else {
					productions.back().right.emplace_back(
						symbol_table[
							token_stream[i].symbol_idx
						]
					);
				}
			} else {
				production_idxes[nonterminal].insert(productions.size());
				productions.emplace_back(nonterminal);
			}
		}
	}
}

void Grammar::print_productions() {
	for (const auto& nonterminal : nonterminals) {
		for (int i : production_idxes[nonterminal]) {
			cout << productions[i];
		}
	}
	cout << endl;
}

void Grammar::print_first() {
	for (const auto& nonterminal : nonterminals) {
		cout << "first[" << nonterminal << "] = {";
		for (const auto& symbol : first[nonterminal]) {
			cout << token_vals[boost::get<TokenType>(symbol)] << ", ";
		}
		if (first[nonterminal].size()) {
			cout << "\b\b";
		}
		cout << "}\n";
	}
	cout << endl;
}

void Grammar::print_follow() {
	for (const auto& nonterminal : nonterminals) {
		cout << "follow[" << nonterminal << "] = {";
		for (const auto& symbol : follow[nonterminal]) {
			cout << token_vals[boost::get<TokenType>(symbol)] << ", ";
		}
		if (follow[nonterminal].size()) {
			cout << "\b\b";
		}
		cout << "}\n";
	}
	cout << endl;
}

void Grammar::augment() {
	Symbol new_start_symbol = "S" + boost::get<string>(start_symbol);
	production_idxes[new_start_symbol].insert(productions.size()); 
	productions.emplace_back(new_start_symbol);
	productions.back().right.emplace_back(start_symbol);
	start_symbol = new_start_symbol;
	nonterminals.emplace_front(std::move(new_start_symbol));
}

void Grammar::remove_epsilon_production() {
}

void Grammar::remove_left_recursion() {
	set<Symbol> vis_nonterminals;
	vector<Symbol> new_nonterminals;
	for (const auto& nonterminal : nonterminals) {
		//cout << "nonterminal = " << nonterminal << endl;
		set<int> new_production_idxes(production_idxes[nonterminal]);
		for (int i : production_idxes[nonterminal]) {
			Symbol first_symbol(productions[i].right.front());
			//cout << productions[i] << "first_symbol = " << first_symbol << endl;
			if (vis_nonterminals.find(first_symbol) != vis_nonterminals.end()) {
				new_production_idxes.erase(i);
				productions[i].right.pop_front();
				//cout << "first_symbol = " << first_symbol << endl;
				for (int j : production_idxes[first_symbol]) {
					//cout << "add " << j << endl;
					new_production_idxes.insert(productions.size());
					Production new_production(productions[i]);
					new_production.right.insert(
						new_production.right.begin(),
						productions[j].right.begin(),
						productions[j].right.end()
					);
					productions.emplace_back(std::move(new_production));
				}
			}
		}
		production_idxes[nonterminal] = new_production_idxes;
		vector<int> left_recursive_production_idxes;
		for (int i : production_idxes[nonterminal]) {
			const Symbol& first_symbol(productions[i].right.front());
			if (first_symbol == nonterminal) {
				new_production_idxes.erase(i);
				left_recursive_production_idxes.push_back(i);
			}
		}
		if (left_recursive_production_idxes.size()) {
			production_idxes[nonterminal] = new_production_idxes;
			Symbol new_nonterminal(boost::get<string>(nonterminal) + "\'");
			new_nonterminals.emplace_back(new_nonterminal);
			for (int i : production_idxes[nonterminal]) {
				productions[i].right.push_back(new_nonterminal);
			}
			production_idxes[nonterminal] = std::move(new_production_idxes);
			production_idxes[new_nonterminal].insert(productions.size());
			productions.emplace_back(new_nonterminal, std::move(deque<Symbol>{EPSILON}));
			for (int i : left_recursive_production_idxes) {
				productions[i].left = new_nonterminal;
				productions[i].right.pop_front();
				productions[i].right.push_back(new_nonterminal);
				production_idxes[new_nonterminal].insert(i);
			}
		}
		vis_nonterminals.insert(nonterminal);
	}
	for (auto& new_nonterminal : new_nonterminals) {
		nonterminals.emplace_back(std::move(new_nonterminal));
	}
}

#include "../Trie.h"
#include <utility>
#include <boost/lexical_cast.hpp>

using std::pair;
using boost::lexical_cast;

enum {
	MAX_TRIE_SIZE = 500
};

void Grammar::extract_common_left_factor() {
	map<Symbol, int> new_nonterminal_suffixes;
	//Ineffecient loop, needs optimization.
	//Actually in each round, only those newly-added productions 
	//need checking if there exist common left factors among them.
	//Thus only those productions needs adding to the trie.
	while (true) {
		bool has_common_left_factor(false);
		map<Symbol, int> symbol_to_idx;
		int cur_idx(0);
		for (const auto& nonterminal : nonterminals) {
			symbol_to_idx[nonterminal] = cur_idx++;
		}
		for (const auto& terminal : terminals) {
			symbol_to_idx[terminal] = cur_idx++;
		}
		Trie<int, -1> trie(MAX_TRIE_SIZE, cur_idx);
		vector<Symbol> new_nonterminals;
		//Maps each symbol in each production to its idx
		//for insertion in trie
		vector<vector<int>> int_mapped_productions(productions.size());
		for (const auto& nonterminal : nonterminals) {
			trie.clear();
			for (int i : production_idxes[nonterminal]) {
				for (const auto& symbol : productions[i].right) {
					int_mapped_productions[i].push_back(symbol_to_idx[symbol]);
				}
				trie.insert<vector<int>, int>(int_mapped_productions[i], i);
			}
			set<int> remaining_production_idxes(production_idxes[nonterminal]);
			//clf = common left factor
			//in pair<vector<int>, int>:
			//vector<int> contanis indexes of productions shared clf
			//int indicates the length of their clf
			vector<pair<set<int>, int>> clf_shared_productions_sets;
			for (int i : production_idxes[nonterminal]) {
				if (remaining_production_idxes.find(i)
					!= remaining_production_idxes.end()) {
					int cur(trie.root);
					int clf_len(0);
					for (const auto& symbol : productions[i].right) {
						int idx(symbol_to_idx[symbol]);
						int nxt(trie.nodes[cur].next[idx]);
						if (trie.nodes[nxt].vis_vals.size() == 1) {
							if (trie.nodes[cur].vis_vals.size() > 1) {
								clf_shared_productions_sets.emplace_back(
									trie.nodes[cur].vis_vals, clf_len
								);
								for (int i : clf_shared_productions_sets.back().first) {
									remaining_production_idxes.erase(i);
									trie.erase<vector<int>, int>(int_mapped_productions[i], i);
								}
								break;
							}
						}
						cur = nxt;
						++clf_len;
					}
				}
			}
			if (clf_shared_productions_sets.size()) {
				has_common_left_factor = true;
				production_idxes[nonterminal] = std::move(remaining_production_idxes);
				//int new_nonterminal_suffix(1);
				for (auto& clf_shared_productions : clf_shared_productions_sets) {
					Symbol new_nonterminal(
						boost::get<string>(nonterminal)
						+ "_" + lexical_cast<string>(new_nonterminal_suffixes[nonterminal]++)
					);
					new_nonterminals.emplace_back(new_nonterminal);
					Production new_production(nonterminal);
					int clf_len(clf_shared_productions.second);
					auto clf_shared_production_idxes(
						std::move(clf_shared_productions.first)
					);
					bool has_init_new_production(false);
					for (int i : clf_shared_production_idxes) {
						productions[i].left = new_nonterminal;
						for (int j(0); j < clf_len; ++j) {
							if (!has_init_new_production) {
								new_production.right.emplace_back(
									std::move(productions[i].right.front())
								);
							}
							productions[i].right.pop_front();
						}
						has_init_new_production = true;
						if (productions[i].right.empty()) {
							productions[i].right.emplace_back(EPSILON);
						}
						production_idxes[new_nonterminal].insert(i);
					}
					production_idxes[nonterminal].insert(productions.size());
					new_production.right.emplace_back(std::move(new_nonterminal));
					productions.emplace_back(std::move(new_production));
				}
			}
		}
		if (has_common_left_factor) {
			for (auto& new_nonterminal : new_nonterminals) {
				nonterminals.emplace_back(std::move(new_nonterminal));
			}
		} else {
			break;
		}
	}
}

#ifndef BRUTE_FORCE

void Grammar::construct_first() {
	first_of_production.resize(productions.size());
	bool has_updation(true);
	while (has_updation) {
		has_updation = false;
		for (const auto& nonterminal : nonterminals) {
			//print_symbol(cout, nonterminal) << endl;
			int orig_size(first[nonterminal].size());
			for (int i : production_idxes[nonterminal]) {
				const auto& production(productions[i]);
				bool all_has_epsilon(true);
				for (const auto& symbol : production.right) {
					if (symbol.which() == TERMINAL) {
						first_of_production[i].insert(symbol);
						all_has_epsilon = false;
						break;
					}
					first_of_production[i].insert(
						first[symbol].begin(),
						first[symbol].end()
					);
					if (first[symbol].find(EPSILON) == first[symbol].end()) {
						all_has_epsilon = false;
						break;
					} else {
						//cout << "erase\n";
						first_of_production[i].erase(EPSILON);
					}
				}
				if (all_has_epsilon) {
					first_of_production[i].insert(EPSILON);
				}
				//cout << "yes\n";
				//cout << first_of_production[i].size() << endl;
				first[nonterminal].insert(
					first_of_production[i].begin(),
					first_of_production[i].end()
				);
				//cout << "yes\n";
				has_updation |= (first[nonterminal].size() > orig_size);
			}
		}
	}
}

void Grammar::construct_first(const Symbol& nonterminal) {
}

void Grammar::construct_follow() {
	follow[start_symbol].insert(END);
	bool has_updation = true;
	while (has_updation) {
		has_updation = false;
		for (const auto& nonterminal : nonterminals) {
			//print_symbol(cout, nonterminal) << endl;
			int orig_size(follow[nonterminal].size());
			for (const auto& tmp_nonterminal : nonterminals) {
				for (int i : production_idxes[tmp_nonterminal]) {
					const auto& production(productions[i]);
					for (int j(0), k; j < production.right.size(); ++j) {
						if (production.right[j] == nonterminal) {
							for (k = j + 1; k < production.right.size(); ++k) {
								const auto& symbol(production.right[k]);
								if (symbol.which() == TERMINAL) {
									follow[nonterminal].insert(symbol);
									break;
								}
								follow[nonterminal].insert(
									first[symbol].begin(),
									first[symbol].end()
								);
								if (first[symbol].find(EPSILON) == first[symbol].end()) {
									break;
								} else {
									follow[nonterminal].erase(EPSILON);
								}
							}
							if (k == production.right.size()) {
								const auto& another_nonterminal(production.left);
								follow[nonterminal].insert(
									follow[another_nonterminal].begin(),
									follow[another_nonterminal].end()
								);
							}
						}
					}
				}
			}
			has_updation |= (follow[nonterminal].size() > orig_size);
		}
	}
}

void Grammar::construct_follow(const Symbol& nonterminal) {
}

#else

void Grammar::construct_first() {
	first_of_production.resize(productions.size());
	for (const auto& nonterminal : nonterminals) {
		if (!has_constructed_first[nonterminal]) {
			construct_first(nonterminal);
		}
	}
}

void Grammar::construct_first(const Symbol& nonterminal) {
	for (int i : production_idxes[nonterminal]) {
		const auto& production(productions[i]);
		bool all_has_epsilon(true);
		for (const auto& symbol : production.right) {
			if (symbol.which() == TERMINAL) {
				first_of_production[i].insert(symbol);
				all_has_epsilon = false;
				break;
			}
			//This condition is forever true if left recursion has been removed.
			//However, LR parsing allows left recursion.
			//Thus a check to prevent dead loop id needed here.
			if (symbol != nonterminal) {
				if (!has_constructed_first[symbol]) {
					construct_first(symbol);
				}
				first_of_production[i].insert(
					first[symbol].begin(),
					first[symbol].end()
				);
				if (first[symbol].find(EPSILON) == first[symbol].end()) {
					all_has_epsilon = false;
					break;
				} else {
					first_of_production[i].erase(EPSILON);
				}
			} else {
				all_has_epsilon = false;
				break;
			}
		}
		if (all_has_epsilon) {
			first_of_production[i].insert(EPSILON);
		}
		first[nonterminal].insert(
			first_of_production[i].begin(),
			first_of_production[i].end()
		);
	}
	has_constructed_first[nonterminal] = true;
}

void Grammar::construct_follow() {
	follow[start_symbol].insert(END);
	for (const auto& nonterminal : nonterminals) {
		if (!has_constructed_follow[nonterminal]) {
			construct_follow(nonterminal);
		}
	}
	for (const auto& nonterminal : nonterminals) {
		for (const auto& another_nonterminal : nonterminals) {
			if (includes_follow_of[nonterminal][another_nonterminal]
				&& includes_follow_of[another_nonterminal][nonterminal]) {
				follow[nonterminal].insert(
					follow[another_nonterminal].begin(),
					follow[another_nonterminal].end()
				);
				follow[another_nonterminal] = follow[nonterminal];
				includes_follow_of[nonterminal][another_nonterminal]
					= includes_follow_of[another_nonterminal][nonterminal]
					= false;
			}
		}
	}
}

void Grammar::construct_follow(const Symbol& nonterminal) {
	for (const auto& tmp_nonterminal : nonterminals) {
		for (int i : production_idxes[tmp_nonterminal]) {
			const auto& production(productions[i]);
			for (int j(0), k; j < production.right.size(); ++j) {
				if (production.right[j] == nonterminal) {
					for (k = j + 1; k < production.right.size(); ++k) {
						const auto& symbol(production.right[k]);
						if (symbol.which() == TERMINAL) {
							follow[nonterminal].insert(symbol);
							break;
						}
						follow[nonterminal].insert(
							first[symbol].begin(),
							first[symbol].end()
						);
						if (first[symbol].find(EPSILON) == first[symbol].end()) {
							break;
						} else {
							follow[nonterminal].erase(EPSILON);
						}
					}
					if (k == production.right.size()
						&& production.left != nonterminal) {
						const auto& another_nonterminal(production.left);
						includes_follow_of[nonterminal][another_nonterminal] = true;
						if (!includes_follow_of[another_nonterminal][nonterminal]) {
							if (!has_constructed_follow[another_nonterminal]) {
								construct_follow(another_nonterminal);
							}
							follow[nonterminal].insert(
								follow[another_nonterminal].begin(),
								follow[another_nonterminal].end()
							);
						}
					}
				}
			}
		}
	}
	has_constructed_follow[nonterminal] = true;
}

#endif // !BRUTE_FORCE


