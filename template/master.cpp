#include "bits/stdc++.h"
#include "Codon_dict.hpp"
#include "Monoisotopic_mass_table.hpp"
//#include "tabaityo.hpp"
using namespace std;

#define Rep(b, e, i) for (int i = b; i <= e; i++)
#define Repr(e, b, i) for (int i = e; i >= b; i--)
#define rep(n, i) Rep(0, n - 1, i)
#define repr(n, i) Repr(n - 1, 0, i)
#define all(v) (v).begin(), (v).end()
#define pb(v) push_back(v)
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define bitcnt(x) __builtin_popcount(x)
#define fst first
#define snd second
#define Pqaz(T) priority_queue<T, vector<T>, greater<T>>
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
typedef vector<int> vec;
typedef vector<ll> vecll;
typedef vector<double> vecd;
typedef vector<vec> mat;
typedef vector<vecll> matll;
typedef vector<vecd> matd;

template <class T>
ostream &operator<<(ostream &o, const vector<T> &v)
{
	o << "{";
	for (int i = 0; i < (int)v.size(); i++)
		o << (i > 0 ? ", " : "") << v[i];
	o << "}";
	return o;
}

const int MAX = 200020;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1 << 29;
const ll INFL = 1e18;
const ll MOD = 1e9 + 7;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
//const int dx[]={-1,-1,-1,0,1,1,1,0},dy[]={-1,0,1,1,1,0,-1,-1};

const string dna_base = "ATCG";
const string rna_base = "AUCG";

//I/O files
ifstream inputfile("input.txt");
ofstream outputfile("output.txt");

int basemap(char c)
{
	if (c == 'A') return 0;
	if (c == 'T' || c == 'U') return 1;
	if (c == 'C') return 2;
	if (c == 'G') return 3;
	return -1;
}

//fasta format
string readg(string buf)
{
	string res = "";

	if (buf[0] == '>') return res;

	char nowc;

	for (char nowc : buf)
	{
		if (basemap(nowc) >= 0) res.pb(nowc);
	}

	return res;
}

string rev_complement(string strand)
{
	string res = "";
	for (char c : strand)
	{
		res.pb(dna_base[basemap(c) ^ 1]);
	}
	reverse(all(res));

	return res;
}

//********************************template END****************************************//

void solve(void)
{
	if (inputfile.fail())
	{
		cout << "FILE READ ERROR" << endl;
		return;
	}

	//input
	string buf, strand = "";
	getline(inputfile, buf);
	while (getline(inputfile, buf))
	{
		strand += readg(buf);
		if (strand == "") break;
	}

	inputfile.close();
	outputfile.close();

}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
