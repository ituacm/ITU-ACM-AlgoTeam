// Author: Fatih Baskın
// Reviewer: Ahmet Furkan Kavraz
// Question Link: https://leetcode.com/problems/gas-station/

// Complexity: O(n)
class Solution {
   public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Storing the sum of differances, if total is < 0 cost is greater than total fuel, can't complete the circuit.
        int total = 0;

        // Pointer stores the point where we begun.
        int pointer = 0;

        // Fuel tank is the total fuel that we stored in our vehicle.
        int fuelTank = 0;

        for (int i = 0; i < gas.size(); i++) {
            // Calculating differance between available fuel in gas station and cost of going there
            int differance = gas[i] - cost[i];
            total += differance;

            // Adding differance to fuel tank means we have reached there and adding fuel that is available to our tank.
            // Then subtracting the cost, assessing whether we can reach next station.
            fuelTank += differance;

            // If we can't reach next station (added differance have made our journey impossible)
            // start to calculate from next station.
            if (fuelTank < 0) {
                pointer = i + 1;
                fuelTank = 0;
            }
        }

        // As have explained above, if total < 0 then there is less fuel than cost. Therefore we can't complete circuit.
        if (total < 0) {
            return -1;
        }

        // Return pointer.
        return pointer;
    }
};