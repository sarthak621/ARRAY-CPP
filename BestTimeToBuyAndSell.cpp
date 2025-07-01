class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //we have to maximize the profit

        //intution: if you are selling on ith day then you buy it on min. price from 0th to (i-1)th day

        int min_buy=prices[0];
        int profit=0;

        for(int i=1;i<prices.size();i++){
            int cost= prices[i]-min_buy;

            profit=max(profit,cost);

            min_buy=min(min_buy,prices[i]);
        }

        return profit;
    }
};


// //bruteforce
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         //we have to maximize the profit
//         int n=prices.size();

//         int minBuy=prices[0];
//         int profit=0;
//         int maxi=INT_MIN;
        
//         if(n==1) return 0;

//         for(int i=0;i<n-1;i++){
//             if(prices[i+1]<minBuy){
//                 minBuy=prices[i+1];
//             }

//             profit=prices[i+1]-minBuy;
//             maxi=max(profit,maxi);

//         }
//         return maxi;
//     }
// };

