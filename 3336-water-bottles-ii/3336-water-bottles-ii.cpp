class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int drink = numBottles;
        int empty = numBottles;

        while(empty >= numExchange) {
            drink++;
            empty = (empty - numExchange + 1);
            numExchange++;
        }
        return drink;
    }
};