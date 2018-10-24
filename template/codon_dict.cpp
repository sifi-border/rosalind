#include <map>
#include <string>

using namespace std;

map<string, char> codon_dictionary =
{
	make_pair("TCA", 'S'),	//Serine
	make_pair("TCC", 'S'),	//Serine
	make_pair("TCG", 'S'),	//Serine
	make_pair("TCT", 'S'),	//Serine
	make_pair("TTC", 'F'),	//Phenylalanine
	make_pair("TTT", 'F'),	//Phenylalanine
	make_pair("TTA", 'L'),	//Leucine
	make_pair("TTG", 'L'),	//Leucine
	make_pair("TAC", 'Y'),	//Tyrosine
	make_pair("TAT", 'Y'),	//Tyrosine
	make_pair("TAA", '_'),	//Stop
	make_pair("TAG", '_'),	//Stop
	make_pair("TGC", 'C'),	//Cysteine
	make_pair("TGT", 'C'),	//Cysteine
	make_pair("TGA", '_'),	//Stop
	make_pair("TGG", 'W'),	//Tryptophan
	make_pair("CTA", 'L'),	//Leucine
	make_pair("CTC", 'L'),	//Leucine
	make_pair("CTG", 'L'),	//Leucine
	make_pair("CTT", 'L'),	//Leucine
	make_pair("CCA", 'P'),	//Proline
	make_pair("CCC", 'P'),	//Proline
	make_pair("CCG", 'P'),	//Proline
	make_pair("CCT", 'P'),	//Proline
	make_pair("CAC", 'H'),	//Histidine
	make_pair("CAT", 'H'),	//Histidine
	make_pair("CAA", 'Q'),	//Glutamine
	make_pair("CAG", 'Q'),	//Glutamine
	make_pair("CGA", 'R'),	//Arginine
	make_pair("CGC", 'R'),	//Arginine
	make_pair("CGG", 'R'),	//Arginine
	make_pair("CGT", 'R'),	//Arginine
	make_pair("ATA", 'I'),	//Isoleucine
	make_pair("ATC", 'I'),	//Isoleucine
	make_pair("ATT", 'I'),	//Isoleucine
	make_pair("ATG", 'M'),	//Methionine
	make_pair("ACA", 'T'),	//Threonine
	make_pair("ACC", 'T'),	//Threonine
	make_pair("ACG", 'T'),	//Threonine
	make_pair("ACT", 'T'),	//Threonine
	make_pair("AAC", 'N'),	//Asparagine
	make_pair("AAT", 'N'),	//Asparagine
	make_pair("AAA", 'K'),	//Lysine
	make_pair("AAG", 'K'),	//Lysine
	make_pair("AGC", 'S'),	//Serine
	make_pair("AGT", 'S'),	//Serine
	make_pair("AGA", 'R'),	//Arginine
	make_pair("AGG", 'R'),	//Arginine
	make_pair("GTA", 'V'),	//Valine
	make_pair("GTC", 'V'),	//Valine
	make_pair("GTG", 'V'),	//Valine
	make_pair("GTT", 'V'),	//Valine
	make_pair("GCA", 'A'),	//Alanine
	make_pair("GCC", 'A'),	//Alanine
	make_pair("GCG", 'A'),	//Alanine
	make_pair("GCT", 'A'),	//Alanine
	make_pair("GAC", 'D'),	//Aspartic Acid
	make_pair("GAT", 'D'),	//Aspartic Acid
	make_pair("GAA", 'E'),	//Glutamic Acid
	make_pair("GAG", 'E'),	//Glutamic Acid
	make_pair("GGA", 'G'),	//Glycine
	make_pair("GGC", 'G'),	//Glycine
	make_pair("GGG", 'G'),	//Glycine
	make_pair("GGT", 'G')	 //Glycine
};
