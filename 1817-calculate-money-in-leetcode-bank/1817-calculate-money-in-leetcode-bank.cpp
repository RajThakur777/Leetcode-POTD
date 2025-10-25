class Solution {
public:
    int totalMoney(int n) {
        int total = 0;
        int week = 0; 
        int day = 0; 
        
        for (int i = 1; i <= n; i++) {
            total += (week + 1) + day; 
            day++;  
            
            if (day == 7) { 
                day = 0;
                week++; 
            }
        }
        return total;
    }
};