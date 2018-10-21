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
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;

namespace mp = boost::multiprecision;

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
typedef mp::cpp_int infint;
typedef pair<ll, ll> llP;
typedef pair<int, int> intP;
typedef complex<double> comp;
typedef vector <int> vec;
typedef vector <ll> vecll;
typedef vector <infint> vecinf;
typedef vector <double> vecd;
typedef vector <vec> mat;
typedef vector <vecll> matll;
typedef vector <vecinf> matinf;
typedef vector <vecd> matd;



//vector の中身を出力
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

const int MAX = 200020;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const ll INFL = 1e18;
const ll MOD = 1e9+7;

const int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
//const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

//********************************template END****************************************//

const string base = "ACGT";

int basemap(char c)
{
	if (c == 'A') return 0;
	if (c == 'C') return 1;
	if (c == 'G') return 2;
	if (c == 'T') return 3;
	//printf("ERROR @ basemap\n");
	return -1;
}

void solve(void){

	ofstream outputfile("output.txt");

	int N, M;
	cin >> N >> M;

	matinf dp(N, vecinf(M, 0));

	dp[0][0] = 1;

	Rep(1, N-1, n) rep(M, m)
	{
		if (m == 0)
		{
			rep(M-1, m2) dp[n][m] += dp[n-1][m2+1];
		}
		else
		{
			dp[n][m] = dp[n-1][m-1];
		}
	}

	infint sum = 0;

	rep(M, m) sum += dp[N-1][m];

	cout << sum << endl;
	outputfile << sum << endl;

	outputfile.close();

}

int main(void){
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}