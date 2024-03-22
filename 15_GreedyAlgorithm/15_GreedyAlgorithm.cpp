#include<iostream>
#include<vector>

using namespace std;

int main() {
	return 0;
}

int CoinChangeGreedy(vector<int>& coins, int amt) {
	int i = coins.size() - 1;
	int count = 0;
	while (amt > 0) {
		while (i > 0 && coins[i] > amt) {//当coin面额大于amt时，减小面额
			i--;
		}
		amt -= coins[i];
		count++;
	}
	return amt == 0 ? count : -1;
}

