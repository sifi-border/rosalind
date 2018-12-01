#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cmath>
#include <complex>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cassert>
#include <iomanip>
#include <fstream>
#include "Codon_dict.hpp"
#include "Monoisotopic_mass_table.hpp"
//#include "tabaityo.hpp"
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define Repr(e, b, i) for(int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n-1, i)
#define repr(n, i) Repr(n-1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)),(v).end())
#define bitcnt(x) __builtin_popcount(x)
#define fst first
#define snd second
#define Pqaz(T) priority_queue<T,vector<T>,greater<T>>
#define Pqza(T) priority_queue<T>
#define put(x) cout << x;
#define putsp(x) cout << x << ' ';
#define putbd cout << "---------------------------------------------" << endl;
#define putln(x) cout << x << endl;
#define debug(x) cerr << #x << "=" << x << endl;
#define ENJYU std::ios::sync_with_stdio(false);std::cin.tie(0);

typedef long long ll;
typedef pair<ll, ll> llP;
typedef pair<int, int> intP;
typedef complex<double> comp;
typedef vector <int> vec;
typedef vector <ll> vecll;
typedef vector <double> vecd;
typedef vector <vec> mat;
typedef vector <vecll> matll;
typedef vector <vecd> matd;

//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

const int MAX = 200020;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const ll INFL = 1e18;
const ll MOD = 1e6;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
//const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

const string dna_base = "ATCG";
const string rna_base = "AUCG";

int basemap(char c)
{
	if (c == 'A') return 0;
	if (c == 'T' || c == 'U') return 1;
	if (c == 'C') return 2;
	if (c == 'G') return 3;
	return -1;
}

//fasta format
string readg()
{
	string res = "";

	char nowc;

	while(~scanf("%c\n", &nowc))
	{
		if (nowc == '>') break;
		if (basemap(nowc) >= 0) res.pb(nowc);
	}

	return res;
}

//********************************template END****************************************//

ofstream outputfile("output.txt");

string S;
ll dp[1<<9][1<<9];

ll rec(int l, int r)
{
	if (~dp[l][r]) return dp[l][r];
	if (l+1 == r)
	{
		return dp[l][r] = (basemap(S[l])^basemap(S[r])) == 1;
	}
	ll tmp = ((basemap(S[l])^basemap(S[r])) == 1) ? rec(l+1, r-1) : 0;
	for (int c = l+1; c < r; c += 2)
	{
		tmp += rec(l, c) * rec(c+1, r) % MOD;
		tmp %= MOD;
	}
	return dp[l][r] = tmp;
}

void solve(void)
{

	cin >> S;
	S = readg();

	memset(dp, -1, sizeof(dp));

	cout << S << endl;

	ll ans = rec(0, (int)S.size()-1);

	cout << ans << endl;
	outputfile << ans << endl;

	outputfile.close();

}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
