import urllib.request

in_f = open("rosalind_xxxx.txt", 'r')
out_f = open("output.txt", 'w')

text = in_f.read()
protain_names = text.splitlines()

url_str = "https://www.uniprot.org/uniprot/{}.fasta".format(name)
req = urllib.request.Request(url_str)
with urllib.request.urlopen(req) as response:
	raw_page = response.read()
	raw_page = raw_page.decode('utf-8')
	lines = raw_page.splitlines()

in_f.close()
out_f.close()
