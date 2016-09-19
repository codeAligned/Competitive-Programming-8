//Problem: Breed Counting (Silver)
//Type: DP
//Solution: Prefix sums of different breeds at every intervals and subtract intervals for answers, with dp[cows][0] = 0
#include <fstream>
using namespace std;
ifstream fin("bcount.in");
ofstream fout("bcount.out");
int N, Q, dp[3][100001];
int main(){
	//Instantiation
	fin >> N >> Q;
	for(int i = 1; i <= N; i++){
		int c;
		fin >> c;
		dp[c-1][i]++;
		//DP
		dp[0][i] += dp[0][i-1];
		dp[1][i] += dp[1][i-1];
		dp[2][i] += dp[2][i-1];
	}
	//Print results
	for(int i = 0; i < Q; i++){
		int a, b;
		fin >> a >> b;
		fout << dp[0][b]-dp[0][a-1] << " " << dp[1][b]-dp[1][a-1] << " " << dp[2][b]-dp[2][a-1] << endl;
	}
	return 0;
}