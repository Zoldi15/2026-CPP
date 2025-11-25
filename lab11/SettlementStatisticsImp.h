//
// Created by User on 25-Nov-25.
//

#ifndef SETTLEMENTSTATISTICSIMPL_H
#define SETTLEMENTSTATISTICSIMPL_H

#include <map>
#include "SettlementStatistics.h"

class SettlementStatisticsImp : public SettlementStatistics {
    public:
    multimap<string, Settlement> Settlements;

    //~SettlementStatisticsImp();

    int numSettlements();
    int numCounties();
    int numSettlementsByCounty(const string& county);

    vector<Settlement> findSettlementsByCounty(const string& county);
    Settlement findSettlementsByNameAndCounty(const string& name, const string& county);

    Settlement maxPopulationBySettlement();
    Settlement minPopulationBySettlement();
    vector<Settlement> findSettlementsByName(const string& name) override;

    void readFromFile(const string &filename);
};

#endif //SETTLEMENTSTATISTICSIMPL_H
