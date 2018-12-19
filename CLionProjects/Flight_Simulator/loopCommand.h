//
// Created by neta on 12/18/18.
//

#ifndef FLIGHT_SIMULATOR_LOOPCOMMAND_H
#define FLIGHT_SIMULATOR_LOOPCOMMAND_H

#include "vector"
#include "CommandExpression.h"
#include "Command.h"
#include "conditionParser.h"
#include "Expression.h"
#include "ifCommand.h"
#include "unordered_map"

using namespace std;

class loopCommand : public conditionParser {
    vector<std::string> vector1;
    Expression *c;
public:
    loopCommand(Expression *command1, vector<std::string> vector1) : conditionParser(command1,vector1) {}

    void execute(const std::vector<std::string> ve) {}

    void doCondition(vector<pair<Expression*,vector<string>>> veOfCnd, vector<string> condition) {
        int row = 0;
        int i = 0;
        while (isTrue(condition)) {
        for (auto it = veOfCnd.begin(); it != veOfCnd.end(); it++) {
            if (it->second.at(0)=="while" || it->second.at(0)=="if") {
                veOfCnd.erase(veOfCnd.begin(),veOfCnd.begin()+i);
                row += cndINcnd(veOfCnd);
                it+=row;
            } else {
                if (it->second.size()>1) {
                    it->first->calculate(it->second);
                }
            }
            i++;
         }
    }
}


};
#endif //FLIGHT_SIMULATOR_LOOPCOMMAND_H