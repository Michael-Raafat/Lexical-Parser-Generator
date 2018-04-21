/* 
 * GrammarExpression.cpp
 * Created on: 4/20/18
 *     Author: marc
 */

#include "GrammarExpression.h"

void GrammarExpression::print_expression() {
    cout << "Expression : ";
    for (unsigned i = 0; i < expression.size(); i++) {
        cout << expression[i]->name << " ";
    }
    cout << endl;
    cout << "First : ";
    for (auto it = first_strings.begin(); it != first_strings.end(); it++) {
        cout << "{\"" << *it << "\"}" << ", ";
    }
    cout << endl;
    cout << "Belongs to : " << belongs_to->name << endl;
}