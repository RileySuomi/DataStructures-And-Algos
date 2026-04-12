// my solution to IBM Data Science Challenge 1
// problem didnt have a name and I dont have description of the problem, so I just named it IBMdatascience1. ( for a data science position)
// ( ctrl + c , my solution so i could save it and put it here. )

long minCostRequired(vector<int> computationCap, vector<int> cost, int avgCap, int maxCap) {
   int n = computationCap.size();
   // Edge case: No servers
   if (n == 0) {
       if (avgCap > 0) {
           return -1;     // Impossible to achieve positive average with 0 servers
       }
       return 0;          // avgCap <= 0 is trivially satisfied
   }
   // Step 1: Calculate current total capacity
   long long current_total = 0;
   for (int c : computationCap) {
       current_total += c;
   }
   // Step 2: Calculate required total capacity for the desired average
   long long required_total = (long long)avgCap * n;
   // If already meeting the requirement, no cost needed
   if (current_total >= required_total) {
       return 0;
   }
   // Step 3: Calculate how much more capacity we need to add
   long long needed = required_total - current_total;
   // Step 4: Collect all possible upgrades from each server
   // Each upgrade stores: {cost per unit, maximum units we can add to this server}
   vector<pair<int, long long>> upgrades;
   for (int i = 0; i < n; ++i) {
       long long can_add = (long long)maxCap - computationCap[i];
       if (can_add > 0) {
           upgrades.push_back({cost[i], can_add});
       }
   }
   // Step 5: Sort upgrades by cost (cheapest first) - this is the greedy choice
   sort(upgrades.begin(), upgrades.end());
   // Step 6: Greedily buy capacity from cheapest servers first
   long long total_cost = 0;
   for (auto& upgrade : upgrades) {
       if (needed <= 0) break;
       int unit_cost = upgrade.first;
       long long max_units = upgrade.second;
       // Take as many units as possible from this server
       long long take = min(needed, max_units);
       total_cost += take * (long long)unit_cost;
       needed -= take;
   }
   // Step 7: If we still need more capacity but can't add any more, it's impossible
   if (needed > 0) {
       return -1;
   }
   return total_cost;
}