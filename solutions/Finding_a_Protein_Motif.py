import urllib.request

def findMotif(protain):
	l = len(protain)
	poslis = []
	for i in range(l-3):
		if (protain[i] == 'N' and protain[i+1] != 'P' and (protain[i+2] == 'S' or protain[i+2] == 'T') and protain[i+3] != 'P'):
			poslis.append(i+1)

	return poslis


protain_list = []

in_f = open("rosalind_mprt.txt", 'r')
out_f = open("output.txt", 'w')

text = in_f.read()
protain_names = text.splitlines()

for name in protain_names:
	url_str = "https://www.uniprot.org/uniprot/{}.fasta".format(name)
	req = urllib.request.Request(url_str)
	with urllib.request.urlopen(req) as response:
		raw_page = response.read()
		raw_page = raw_page.decode('utf-8')
		lines = raw_page.splitlines()
		protain = ""
		for line in lines:
			if (line.startswith('>')):
				continue;
			protain += line
		protain_list.append(protain)



for i in range(len(protain_list)):
	protain = protain_list[i]
	pos_lis = findMotif(protain)
	if pos_lis:
		print(protain_names[i])
		out_f.write(protain_names[i])
		out_f.write('\n')
		for j in range(len(pos_lis)):
			if (j != len(pos_lis)-1):
				print(pos_lis[j], end=" ")
				out_f.write(str(pos_lis[j]))
				out_f.write(' ')
			else:
				print(pos_lis[j])
				out_f.write(str(pos_lis[j]))
				out_f.write('\n')


in_f.close()
out_f.close()
